
// ============================================================
// PROBLEMA 1485 -- Turkish Roulette
// Técnica: DP 2D + enumeração do ponto inicial (rotação)
// ============================================================

#include <iostream>
using namespace std;

int main() {
    int S, B;
    while (cin >> S >> B && (S != 0 || B != 0)) {
        int X[250]; // valores dos espaços da roleta
        int Y[125]; // valores das bolas

        for (int i = 0; i < S; i++) cin >> X[i];
        for (int i = 0; i < B; i++) cin >> Y[i];

        const long long NEG = -(1LL << 60);
        long long dp[126][251];
        long long melhor = NEG;

        // Testa cada espaço como posição inicial da primeira bola.
        // Fixar o início transforma o problema circular em linear.
        for (int inicio = 0; inicio < S; inicio++) {

            for (int k = 0; k <= B; k++)
                for (int d = 0; d <= S; d++)
                    dp[k][d] = NEG;

            // 0 bolas extras adicionadas: lucro extra = 0
            for (int d = 0; d <= S - 2; d++) dp[0][d] = 0;

            int proximo = (inicio + 1) % S;
            // Lucro do dealer: -(valor_bola)*(soma_dos_dois_espaços)
            long long lucroInicial = -(long long)Y[0] * (X[inicio] + X[proximo]);

            // DP para posicionar as bolas restantes.
            // dp[k][d] = maior lucro extra colocando até a k-ésima bola
            //            adicional dentro da distância relativa d.
            for (int k = 1; k < B; k++) {
                for (int d = 2; d <= S - 2; d++) {
                    // Opção 1: não colocar a bola k na posição d
                    dp[k][d] = dp[k][d - 1];

                    int posicao = (inicio + d) % S;
                    int vizinho = (posicao + 1) % S;
                    long long lucro = -(long long)Y[k] * (X[posicao] + X[vizinho]);

                    // Opção 2: colocar a bola k na posição d
                    // (requer bola k-1 a distância ≤ d-2)
                    if (dp[k - 1][d - 2] != NEG) {
                        long long candidato = dp[k - 1][d - 2] + lucro;
                        if (candidato > dp[k][d]) dp[k][d] = candidato;
                    }
                }
            }

            long long total = lucroInicial + dp[B - 1][S - 2];
            if (total > melhor) melhor = total;
        }
        cout << melhor << '\n';
    }
    return 0;
}
