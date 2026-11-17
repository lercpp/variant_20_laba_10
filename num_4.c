#include <stdio.h>

int main() {
    int n, m;

    printf("Введите кол-во строк и столбцов: ");
    scanf("%d %d", &n, &m);

    int a[n][m];

    printf("Введите элементы матрицы:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int max = a[0][0];
    int max_i = 0;
    int max_j = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        a[max_i][j] = 0;
    }

    for (int i = 0; i < n; i++) {
        a[i][max_j] = 0;
    }

    printf("Результат:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
