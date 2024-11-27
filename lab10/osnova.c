#include "function.h"

int main() {
    int N;
    printf("Введите количество параллелепипедов: ");
    scanf("%d", &N);

    PP p[N]; 

    for (int i = 0; i < N; i++) {
        printf("Введите a, b, h для параллелепипеда %d: ", i + 1);
        scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].h);
    }

    int min = minV(p, N);

    printf("Параллелепипед с наименьшим объемом: %d\n", min + 1); // +1 для удобства
    printf("Стороны: a = %d, b = %d, h = %d\n", p[min].a, p[min].b, p[min].h);
    printf("Объем: %d\n", V(p[min]));

    return 0;
}
