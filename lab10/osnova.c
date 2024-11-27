#include "function.h"

int main() {
    int N;
    printf("Введите количество параллелепипедов: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Количество параллелепипедов должно быть положительным.\n");
        return 1;
    }

    PP p[N]; 

    for (int i = 0; i < N; i++) {
        printf("Введите a, b, h для параллелепипеда %d: ", i + 1);
        scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].h);

        if (p[i].a <= 0 || p[i].b <= 0 || p[i].h <= 0) {
            printf("Ошибка: стороны параллелепипеда должны быть положительными.\n");
            return 1; 
        }
    }

    int min = minV(p, N);

    printf("Параллелепипед с наименьшим объемом: %d\n", min + 1); // +1 для удобства
    printf("Стороны: a = %d, b = %d, h = %d\n", p[min].a, p[min].b, p[min].h);
    printf("Объем: %d\n", V(p[min]));

    return 0;
}
