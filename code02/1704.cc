
// ============================================================
// PROBLEMA 1704 -- Arranging Tasks
// Técnica: Algoritmo Guloso (escalonamento por prazo)
// ============================================================


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, h;
    while (scanf("%d %d", &n, &h) == 2) {
        vector<pair<int,int>> tasks(n); // (valor, prazo)
        int total = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &tasks[i].first, &tasks[i].second);
            total += tasks[i].first;
        }

        // Guloso: processa do maior valor para o menor.
        // Para cada tarefa, tenta encaixar no slot mais tardio disponível
        // antes do prazo -- isso maximiza o dinheiro ganho.
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });

        vector<bool> slot(h+1, false);
        int earned = 0;
        for (auto& [v, t] : tasks) {
            // Usa min(t, h): prazo maior que H não ajuda
            for (int s = min(t, h); s >= 1; s--) {
                if (!slot[s]) { slot[s]=true; earned+=v; break; }
            }
        }
        printf("%d\n", total - earned); // dinheiro perdido
    }
    return 0;
}
