#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    int cidade = 1;

    while (scanf("%d", &n) == 1 && n != 0) {
        // Counting Sort: consumo por pessoa vai só de 0 a 200.
        // Escolhi isso porque N pode ser 10^6, e agrupar por consumo
        // já deixa tudo ordenado sem precisar de sort.
        vector<int> pessoas(201, 0);
        long long totalX = 0, totalY = 0;

        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            pessoas[y / x] += x; // divisão inteira já arredonda para baixo
            totalX += x;
            totalY += y;
        }

        // Linha em branco entre casos (mas não depois do último)
        if (cidade > 1) {
            printf("\n");
        }
        printf("Cidade# %d:\n", cidade++);

        // Imprime em ordem crescente de consumo, separando com espaço
        bool primeiro = true;
        for (int c = 0; c <= 200; ++c) {
            if (pessoas[c] > 0) {
                if (!primeiro) printf(" ");
                printf("%d-%d", pessoas[c], c);
                primeiro = false;
            }
        }
        printf("\n");

        // Média truncada em 2 casas usando só inteiros (sem erro de double)
        long long media = (totalY * 100) / totalX;
        printf("Consumo medio: %lld.%02lld m3.\n", media / 100, media % 100);
    }

    return 0;
}