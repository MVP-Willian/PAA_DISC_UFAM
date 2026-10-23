#include <iostream>
#include <vector>

using namespace std;

int main() {
    int casos;
    cin >> casos;

    while (casos--) {
        int l;
        cin >> l;

        vector<int> trem(l);
        for (int i = 0; i < l; ++i) {
            cin >> trem[i];
        }

        // Bubble Sort contando as trocas.
        // Escolhi ele porque só troca vagões vizinhos, igual à ponte,
        // e cada troca desfaz exatamente uma inversão (número mínimo).
        // Como L <= 50, O(L^2) é mais que suficiente.
        int trocas = 0;
        for (int i = 0; i < l - 1; ++i) {
            for (int j = 0; j < l - 1 - i; ++j) {
                if (trem[j] > trem[j + 1]) {
                    swap(trem[j], trem[j + 1]);
                    trocas++;
                }
            }
        }

        cout << "Optimal train swapping takes " << trocas << " swaps.\n";
    }

    return 0;
}