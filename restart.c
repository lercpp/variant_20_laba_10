
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Выделение памяти под матрицу
int **create_matrix(int n, int m) {
    int **a = malloc(n * sizeof(int *));

    if (a == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        a[i] = malloc(m * sizeof(int));

        if (a[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(a[j]);
            }
            free(a);
            return NULL;
        }
    }

    return a; //возвращаем указатель
}

// Заполнение случайными числами
void fill_matrix(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 21 - 10;
        }
    }
}

// Вывод матрицы
void print_matrix(int **a, int n, int m) {
    printf("Матрица:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

// Подсчёт отрицательных элементов в строках с нулём
int count_negative(int **a, int n, int m) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int has_zero = 0;
        int negative = 0;

        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                has_zero = 1;
            }

            if (a[i][j] < 0) {
                negative++;
            }
        }

        if (has_zero) {
            count += negative;
        }
    }

    return count;
}

// Освобождение памяти
void free_matrix(int **a, int n) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }

    free(a);
}

int main() {
    int n, m;

    srand(time(NULL));

    printf("Введите количество строк и столбцов: ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("Некорректный размер матрицы.\n");
        return 1;
    }

    int **a = create_matrix(n, m);

    if (a == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    fill_matrix(a, n, m);
    print_matrix(a, n, m);

    printf("Количество отрицательных элементов: %d\n",
           count_negative(a, n, m));

    free_matrix(a, n);

    return 0;
}
