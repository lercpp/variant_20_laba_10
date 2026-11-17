#include <stdio.h>

int main() {
    int n, m;
    int count = 0;

    printf("Введите кол-во строк и столбцов: ");
    scanf("%d %d", &n, &m);

    int a[n][m];

    printf("Введите элементы матрицы:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        int has_zero = 0;

        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                has_zero = 1;
            }
        }

        if (has_zero == 1) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] < 0) {
                    count++;
                }
            }
        }
    }

    printf("Кол-во отрицательных элементов: %d\n", count);

    return 0;
}
