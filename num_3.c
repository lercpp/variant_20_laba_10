#include <stdio.h>

int main() {
    int n, m, size;

    printf("Введите кол-во строк и столбцов: ");
    scanf("%d %d", &n, &m);

    int a[n][m];

    printf("Введите элементы матрицы:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Введите размер квадрата: ");
    scanf("%d", &size);

    if (size <= 0 || size > n || size > m) {
        printf("Некорректный размер\n");
        return 0;
    }

    int found = 0;

    for (int i = 0; i <= n - size; i++) {
        for (int j = 0; j <= m - size; j++) {

            int zero = 1;

            for (int x = i; x < i + size; x++) {
                for (int y = j; y < j + size; y++) {

                    if (a[x][y] != 0) {
                        zero = 0;
                    }
                }
            }

            if (zero == 1) {
                printf("Квадрат найден : строка %d, столбец %d\n",
                       i + 1, j + 1);
                found = 1;
            }
        }
    }

    if (found == 0) {
        printf("Квадрат не найден\n");
    }

    return 0;
}
