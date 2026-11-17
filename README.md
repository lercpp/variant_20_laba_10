# variant_20_laba_10

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);

    int **a = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        a[i] = malloc(m * sizeof(int));
    }

    // Работа с матрицей

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }

    free(a);

    return 0;
}
