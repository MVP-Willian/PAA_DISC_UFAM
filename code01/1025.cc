#include <iostream>
#include <vector>

using namespace std;


// Eu pensei em primeiro pegar todas as bolinhas inserilas em uma lista, depois ordenar essa lista usando um algoritmos guloso (selection sort), e depois fazer uma busca binária dentro dessa lista.

// As partes de onde foram feitos os algoritmos estao comentadas, de restante sao apenas questoes de sintaxe do problema


int main() {
    int n, q;
    int qtd = 1;

    while (cin >> n >> q && (n != 0 || q != 0)) {
        vector<int> marbles(n);
        for (int i = 0; i < n; ++i) {
            cin >> marbles[i];
        }

        // Selection Sort O(N^2)
        for (int pivot = 0; pivot < n - 1; ++pivot) {
            int menor = pivot;
            for (int i = pivot + 1; i < n; ++i) {
                if (marbles[i] < marbles[menor]) {
                    menor = i;
                }
            }
            swap(marbles[pivot], marbles[menor]);
        }

        cout << "CASE# " << qtd++ << ":\n";

        for (int i = 0; i < q; ++i) {
            int query;
            cin >> query;

            int inicio = 0, fim = n - 1;
            int pos = -1;

            // Busca binária
            while (inicio <= fim) {
                int meio = inicio + (fim - inicio) / 2;

                if (marbles[meio] == query) {
                    pos = meio;
                    fim = meio - 1; // Continua buscando à esquerda
                } else if (marbles[meio] < query) {
                    inicio = meio + 1;
                } else {
                    fim = meio - 1;
                }
            }

            if (pos != -1) {
                cout << query << " found at " << pos + 1 << "\n";
            } else {
                cout << query << " not found\n";
            }
        }
    }

    return 0;
}