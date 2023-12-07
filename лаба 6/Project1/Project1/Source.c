#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

int MaxChange(int n, int* arr) {
    int max;
    max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] % 2 == 0) {
            arr[i] = (max + 1);
        }
    }
    return max;
}


void BubbleSort(int n, int* mass) {
    int tmp;
    bool noSwap;

    for (int i = n - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                tmp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = tmp;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }
}

void ShellSort(int n, int* mass)
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}

void MainChange(int n, int* arr, int* mas, int max) {

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == (max + 1)) {
            arr[i] = mas[j];
            j++;
        }
        
    }
    printf("\nОтсортированный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void BaddestVar(int n, int* arr) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)  arr[i] = n - i;
        else arr[i] = n - i;
    }
}

void MainCompare(int n, int count, int* arr, int* mas, int max) {
    double time_spent = 0.0;
    double time_spent1 = 0.0;

    clock_t begin = clock();
    ShellSort(count, mas);
    printf("\nМетод Шелла: ");
    MainChange(n, arr, mas, max);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nВремя выполнения сортировки методом Шелла: %.4f секунд\n", time_spent);

    clock_t begin1 = clock();
    max = MaxChange(n, arr);
    BubbleSort(count, mas);
    printf("\nПузырьковый метод: ");
    MainChange(n, arr, mas, max);
    clock_t end1 = clock();
    time_spent1 += (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf("\nВремя выполнения сортировки пузырьковым методом: %.4f секунд\n", time_spent1);

    if (time_spent > time_spent1) {
        printf("\nСортировка пузырьковым методом быстрее на %.4lf секунд", time_spent - time_spent1);
    }
    else if (time_spent < time_spent1) {
        printf("\nСортировка методом Шелла быстрее на %.4lf секунд", time_spent1 - time_spent);
    }
    else printf("\nСортировки занимают одинаковое количество времени");
}


int main() {
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    int n, choice, i, j = 0, count = 0, max;
    int* arr;
    int* mas;
Start:
    printf("Введите размер массива A: ");
    scanf_s("%d", &n);

    arr = (int*)malloc(n * sizeof(int));
    mas = (int*)malloc(n * sizeof(int));
    printf("Выберите способ заполнения массива 1: вручную, 2: рандом\t");
    scanf_s("%d", &choice);

    if (choice == 1) {
        printf("Введите элементы массива A:\n");
        for (i = 0; i < n; i++) {
            scanf_s("%d", &arr[i]);
        }
    }
    else if (choice == 2) {
        for (i = 0; i < n; i++) {
            arr[i] = -5 + rand() % 15;
        }
    }
    else {
        printf("Некорректный ввод\n");
        getchar() != "\n";
        goto Start;
    }

    printf("Сгенерированный массив: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] % 2 == 0) {
            mas[j] = arr[i];
            j++;
            count++;
        }
    }

    mas = (int*)realloc(mas, count * sizeof(int));
    max = MaxChange(n, arr);
 
    MainCompare(n, count, arr, mas, max);

    BaddestVar(n, arr);
    mas = (int*)realloc(mas, n * sizeof(int));
    count = 0;
    j = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] % 2 == 0) {
            mas[j] = arr[i];
            j++;
            count++;
        }
    }
    mas = (int*)realloc(mas, count * sizeof(int));
    max = MaxChange(n, arr);
    MainCompare(n, count, arr, mas, max);

    free(arr);
    free(mas);
    _getch();
    return 0;
}