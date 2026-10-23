#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> nomes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nomes[i];
    }

    // Ordena em ordem alfabética.
    // Escolhi o sort direto porque string já compara alfabeticamente,
    // e com N <= 100 não precisa de nada mais elaborado.
    sort(nomes.begin(), nomes.end());

    // O K-ésimo da chamada está no índice K-1 (vetor começa em 0)
    cout << nomes[k - 1] << "\n";

    return 0;
}