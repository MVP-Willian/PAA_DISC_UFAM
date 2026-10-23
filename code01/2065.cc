#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    // Fila de prioridade (menor primeiro) com pares (tempo livre, caixa).
    // Escolhi isso porque sempre preciso do caixa que libera primeiro,
    // e o par já desempata pelo menor número do caixa sozinho.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> caixas;
    for (int i = 0; i < n; ++i) {
        caixas.push({0, i}); // todos começam livres no tempo 0
    }

    int fim = 0;
    for (int j = 0; j < m; ++j) {
        int c;
        scanf("%d", &c);

        // Pega o caixa que fica livre primeiro
        pair<int, int> atual = caixas.top();
        caixas.pop();

        int livre = atual.first;
        int id = atual.second;

        // Atende o cliente e calcula quando o caixa fica livre de novo
        int termina = livre + v[id] * c;
        if (termina > fim) {
            fim = termina; // guarda o maior tempo de término
        }

        caixas.push({termina, id});
    }

    printf("%d\n", fim);

    return 0;
}