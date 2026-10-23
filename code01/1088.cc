#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        // Conta os ciclos da permutação em O(N).
        // Escolhi isso em vez de contar inversões direto (O(N^2)),
        // porque só preciso saber se o número de inversões é par ou ímpar,
        // e (N - ciclos) tem a mesma paridade das inversões.
        vector<bool> visitado(n + 1, false);
        int ciclos = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visitado[i]) {
                ciclos++;
                int j = i;
                // Segue o ciclo até voltar ao início
                while (!visitado[j]) {
                    visitado[j] = true;
                    j = p[j];
                }
            }
        }

        // Cada jogada remove exatamente 1 inversão:
        // se o total for ímpar, Marcelo (que começa) faz a última jogada
        if ((n - ciclos) % 2 == 1) {
            cout << "Marcelo\n";
        } else {
            cout << "Carlos\n";
        }
    }

    return 0;
}