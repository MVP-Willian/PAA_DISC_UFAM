#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    // Separo pares e ímpares em vetores diferentes.
    // Escolhi isso porque fica mais simples do que um comparador
    // personalizado: cada grupo só precisa de uma ordenação normal.
    vector<int> pares, impares;

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) {
            pares.push_back(x);
        } else {
            impares.push_back(x);
        }
    }

    // Ordena os dois grupos em ordem crescente
    sort(pares.begin(), pares.end());
    sort(impares.begin(), impares.end());

    // Pares: do menor para o maior
    for (int i = 0; i < (int)pares.size(); ++i) {
        printf("%d\n", pares[i]);
    }

    // Ímpares: percorre de trás para frente (maior para o menor)
    for (int i = (int)impares.size() - 1; i >= 0; --i) {
        printf("%d\n", impares[i]);
    }

    return 0;
}