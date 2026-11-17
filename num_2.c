#include <stdio.h>

int main() {
    int n, m;

    printf("Введите кол-во строк и столбцов: ");
    scanf("%d %d", &n, &m);

    int a[n][m];

    printf("Введите элементы матрицы:\n");

    for (int i = 0; i < n; i++) { //строки
        for (int j = 0; j < m; j++) { //столбцы
            scanf("%d", &a[i][j]);
        }
    }

    int found = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            int min = 1;
            int max = 1;

            for (int k = 0; k < m; k++) {
                if (a[i][k] < a[i][j]) {
                    min = 0;
                    break;
                }
            }

            for (int k = 0; k < n; k++) {
                if (a[k][j] > a[i][j]) {
                    max = 0;
                    break;
                }
            }

            if (min == 1 && max == 1) {
                printf("Седловая точка: %d, строка: %d, столбец: %d\n",
                       a[i][j], i + 1, j + 1);
                found = 1;
            }
        }
    }

    if (found == 0) {
        printf("нет седловых точек\n");
    }

    return 0;
}
