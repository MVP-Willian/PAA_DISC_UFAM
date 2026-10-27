
// ============================================================
// PROBLEMA 1517 -- Apples
// Técnica: DP estilo LIS com distância de Chebyshev
// ============================================================

#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    while (cin >> N >> M >> K) {
        if (N == 0 && M == 0 && K == 0) break;

        int X[1000], Y[1000], T[1000], dp[1000];
        for (int i = 0; i < K; i++) cin >> X[i] >> Y[i] >> T[i];

        int inicioX, inicioY;
        cin >> inicioX >> inicioY;

        int resposta = 0;
        for (int i = 0; i < K; i++) {
            dp[i] = 0;

            // Distância de Chebyshev: máximo entre deslocamentos
            // horizontal e vertical. Rafael anda 1 por segundo em
            // qualquer direção (incluindo diagonal).
            int dx = X[i] - inicioX; if (dx < 0) dx = -dx;
            int dy = Y[i] - inicioY; if (dy < 0) dy = -dy;
            int distancia = dx > dy ? dx : dy;

            if (distancia <= T[i]) dp[i] = 1;

            // LIS: tenta estender sequência que termina em maçã j
            for (int j = 0; j < i; j++) {
                if (dp[j] > 0) {
                    int difX = X[i] - X[j]; if (difX < 0) difX = -difX;
                    int difY = Y[i] - Y[j]; if (difY < 0) difY = -difY;
                    int dist = difX > difY ? difX : difY;
                    if (T[i] - T[j] >= dist) {
                        int candidato = dp[j] + 1;
                        if (candidato > dp[i]) dp[i] = candidato;
                    }
                }
            }
            if (dp[i] > resposta) resposta = dp[i];
        }
        cout << resposta << '\n';
    }
    return 0;
}
