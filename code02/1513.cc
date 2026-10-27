
// ============================================================
// PROBLEMA 1513 -- Horse
// Técnica: BFS (distâncias) + DP com Bitmask (TSP)
// ============================================================

#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    int dl[8] = {-2,-2,-1,-1, 1, 1, 2, 2};
    int dc[8] = {-1, 1,-2, 2,-2, 2,-1, 1};

    while (cin >> n >> m >> k && (n||m||k)) {
        vector<string> tab(n);
        for (int i = 0; i < n; ++i) cin >> tab[i];

        // Coleta posições: 0 = cavalo, 1..k = peões
        vector<int> pl(1), pc(1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (tab[i][j]=='C') { pl[0]=i; pc[0]=j; }
                else if (tab[i][j]=='P') { pl.push_back(i); pc.push_back(j); }
            }

        // BFS de cada ponto importante para calcular distâncias mínimas
        // Uso BFS porque cada salto custa 1 e há obstáculos '#'.
        vector<vector<int>> dist(k+1, vector<int>(k+1,0));
        for (int a = 0; a <= k; ++a) {
            vector<vector<int>> d(n, vector<int>(m,-1));
            queue<pair<int,int>> fila;
            d[pl[a]][pc[a]] = 0;
            fila.push({pl[a], pc[a]});
            while (!fila.empty()) {
                auto [l,c] = fila.front(); fila.pop();
                for (int t = 0; t < 8; ++t) {
                    int nl=l+dl[t], nc=c+dc[t];
                    if (nl>=0&&nl<n&&nc>=0&&nc<m&&tab[nl][nc]!='#'&&d[nl][nc]==-1) {
                        d[nl][nc] = d[l][c]+1;
                        fila.push({nl,nc});
                    }
                }
            }
            for (int b = 0; b <= k; ++b) dist[a][b] = d[pl[b]][pc[b]];
        }

        // DP com bitmask (TSP): dp[mask][i] = menor custo com mask
        // capturados, parado no peão i. Evita o K! de força bruta.
        const int INF = 1e9;
        int total = 1<<k;
        vector<vector<int>> dp(total, vector<int>(k, INF));
        for (int i = 0; i < k; ++i) dp[1<<i][i] = dist[0][i+1];
        for (int mask = 1; mask < total; ++mask)
            for (int i = 0; i < k; ++i) {
                if (dp[mask][i]==INF) continue;
                for (int j = 0; j < k; ++j) {
                    if (mask&(1<<j)) continue;
                    int novo = mask|(1<<j);
                    int custo = dp[mask][i]+dist[i+1][j+1];
                    if (custo < dp[novo][j]) dp[novo][j] = custo;
                }
            }
        int resp = INF;
        for (int i = 0; i < k; ++i)
            resp = min(resp, dp[total-1][i]+dist[i+1][0]);
        printf("%d\n", resp);
    }
    return 0;
}
