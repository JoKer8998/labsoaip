#include <conio.h>
#include <stdio.h>
#include<locale.h>
#include<malloc.h>
#include <stdlib.h>

void SearchMin(int n, int m, int** mas) {
    int min, count, tmp;

    for (int i = 0; i < n; i++) {
        mas[i] = (int*)realloc(mas[i], (m + 1) * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        min = mas[i][0];
        count = 0;
        for (int j = 0; j < m; j++) {
            if (mas[i][j] < min) {
                min = mas[i][j];
                count = j;
            }
        }
        mas[i][m] = min;
    }
}

void InsertionSort(int n, int m, int** mass)
{
    int newElement, location, tmp;
    for (int j = m; j <= m; j++) {
        for (int i = 1; i < n; i++)
        {
            newElement = mass[i][j];
            location = i - 1;
            while (location >= 0 && mass[location][j] < newElement)
            {
                for (int k = 0; k < m + 1; k++) {
                    tmp = mass[i][k];
                    mass[i][k] = mass[i - 1][k];
                    mass[i - 1][k] = tmp;
                }
                i--;
                location--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        mass[i] = (int*)realloc(mass[i], m * sizeof(int));
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int i, j, n, m, choice;
    int** mas;
    printf("Введите кол-во строк и столбцов матрицы\n");
    scanf_s("%d\t%d", &n, &m);
    mas = (int**)malloc(n * sizeof(int*));

    srand(time(0));
Start:
    printf("Выберите способ заполнения массива 1: вручную, 2: рандом\t");
    scanf_s("%d", &choice);
    if (choice == 2) {
        printf("Сгенерированный массив:\n");
        for (i = 0; i < n; i++)
        {
            mas[i] = (int*)malloc(m * sizeof(int));
            for (j = 0; j < m; j++)
            {
                mas[i][j] = 1 + rand() % 10;
                printf("[%d][%d] = %d\t", i + 1, j + 1, mas[i][j]);
            }
            printf("\n");
        }
    }

    else if (choice == 1) {
        for (i = 0; i < n; i++)
        {
            mas[i] = (int*)malloc(m * sizeof(int));
            for (j = 0; j < m; j++)
            {
                printf("[%d][%d] = ", i, j);
                scanf_s("%d", &mas[i][j]);
            }
        }
        printf("\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("[%d][%d] = %d\t", i + 1, j + 1, mas[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Некорректный ввод\n");
        getchar() != "\n";
        goto Start;
    }

    SearchMin(n, m, mas);
    InsertionSort(n, m, mas);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("[%d][%d] = %d\t", i + 1, j + 1, mas[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        free(mas[i]);
    }
    free(mas);
}