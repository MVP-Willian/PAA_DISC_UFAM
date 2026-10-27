
// ============================================================
// PROBLEMA 2446 -- Change
// Técnica: Mochila 0/1 (Subset Sum / verificação de soma exata)
// ============================================================

#include <iostream>
using namespace std;

int main() {
    int V, M;
    cin >> V >> M;

    int moedas[1000];
    for (int i = 0; i < M; i++) cin >> moedas[i];

    bool dp[100001];
    for (int i = 0; i <= V; i++) dp[i] = false;
    dp[0] = true; // soma 0 é sempre possível (sem moedas)

    // Mochila 0/1: percorre em ordem DECRESCENTE para garantir
    // que cada moeda seja usada no máximo uma vez.
    for (int i = 0; i < M; i++)
        for (int soma = V; soma >= moedas[i]; soma--)
            if (dp[soma - moedas[i]]) dp[soma] = true;

    cout << (dp[V] ? "S" : "N") << '\n';
    return 0;
}

