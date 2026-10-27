
// ============================================================
// PROBLEMA 1966 -- The Voyage Home
// Técnica: Mochila Fracionária (Greedy) + busca linear da pirâmide
// ============================================================

#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    long long B;
    scanf("%d %lld", &n, &B);

    vector<int> v(n), p(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    // Ordena por menor preço por cm³ (mais barato por unidade primeiro)
    // Uso comparação cruzada para evitar divisão de inteiros: p[a]/v[a] < p[b]/v[b]
    // equivale a p[a]*v[b] < p[b]*v[a].
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){
        return (long long)p[a]*v[b] < (long long)p[b]*v[a];
    });

    double volume = 0.0;
    long long budget = B;
    for (int i : idx) {
        if (budget <= 0) break;
        if (p[i] == 0)          { volume += v[i]; }          // queijo grátis
        else if (budget >= p[i]){ volume += v[i]; budget -= p[i]; } // compra tudo
        else { volume += (double)budget/p[i]*v[i]; budget = 0; }    // compra fração
    }

    long long cubes = (long long)volume; // trunca: cubos inteiros de 1 cm³

    // Maior base n tal que n*(n+1)/2 <= cubes (pirâmide triangular)
    long long base = 0;
    while ((base+1)*(base+2)/2 <= cubes) base++;

    printf("%lld\n", base);
    return 0;
}