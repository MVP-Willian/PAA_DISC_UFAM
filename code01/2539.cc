#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        vector<int> fila(n);
        for (int i = 0; i < n; ++i) {
            cin >> fila[i];
        }

        // BIT: bit guarda quantos jogadores "à frente" já foram vistos.
        // Escolhi BIT porque conta "quantos menores que x" em O(log N),
        // evitando o O(N^2) de comparar todos os pares.
        vector<int> bit(n + 1, 0);
        long long total = 0; // pode passar de 2^31 (até ~5*10^9)
        int vistos = 0;

        // Percorre da direita (perto do campo) para a esquerda
        for (int i = n - 1; i >= 0; --i) {
            int x = fila[i];

            // Conta quantos já vistos têm número <= x
            int menores = 0;
            for (int k = x; k > 0; k -= k & (-k)) {
                menores += bit[k];
            }

            // Os outros vistos têm número maior: x cumprimenta todos eles
            total += vistos - menores;

            // Marca x como visto
            for (int k = x; k <= n; k += k & (-k)) {
                bit[k]++;
            }
            vistos++;
        }

        cout << total << "\n";
    }

    return 0;
}