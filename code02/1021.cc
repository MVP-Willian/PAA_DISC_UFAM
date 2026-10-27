
// ============================================================
// PROBLEMA 1021 -- Banknotes and Coins
// Técnica: Algoritmo Guloso (maior denominação primeiro)
// ============================================================


#include <cstdio>

int main() {
    double val;
    while (scanf("%lf", &val) == 1) {
        // Converte para centavos (inteiro) para evitar erro de ponto flutuante
        long long cents = (long long)(val * 100 + 0.5);

        long long notes[] = {10000, 5000, 2000, 1000, 500, 200};
        double    nv[]    = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00};
        long long coins[] = {100, 50, 25, 10, 5, 1};
        double    cv[]    = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01};

        // Guloso: usa o máximo possível da maior denominação, depois a próxima
        printf("NOTAS:\n");
        for (int i = 0; i < 6; i++) {
            printf("%lld nota(s) de R$ %.2f\n", cents/notes[i], nv[i]);
            cents %= notes[i];
        }
        printf("MOEDAS:\n");
        for (int i = 0; i < 6; i++) {
            printf("%lld moeda(s) de R$ %.2f\n", cents/coins[i], cv[i]);
            cents %= coins[i];
        }
    }
    return 0;
}

