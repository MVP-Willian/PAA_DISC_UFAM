
// ============================================================
// PROBLEMA 1288 -- Destruction Cannon
// Técnica: Mochila 0/1 clássica (maximização de dano)
// ============================================================

#include <iostream>
using namespace std;

int main() {
    int testes;
    cin >> testes;

    for (int t = 0; t < testes; t++) {
        int N;
        cin >> N;

        int X[50], Y[50]; // poder de destruição e peso
        for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

        int K, R;
        cin >> K >> R;

        int dp[101];
        for (int p = 0; p <= K; p++) dp[p] = 0;

        // Mochila 0/1: para cada peça, atualiza em ordem DECRESCENTE
        // de peso para não reutilizar a mesma peça.
        // dp[p] = maior dano com capacidade p.
        for (int i = 0; i < N; i++)
            for (int p = K; p >= Y[i]; p--) {
                int candidato = dp[p - Y[i]] + X[i];
                if (candidato > dp[p]) dp[p] = candidato;
            }

        if (dp[K] >= R)
            cout << "Missao completada com sucesso" << '\n';
        else
            cout << "Falha na missao" << '\n';
    }
    return 0;
}