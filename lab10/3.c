//Создайте структуру Прямоугольный_Параллелепипед с элементами 
//– a и b – стороны прямоугольника-основания, h – высота
// параллелепипеда. Найдите, у какого из N заданных 
//параллелепипедов объем наименьший?

#include <stdio.h>

typedef struct {
    int a; 
    int b;
    int h;
} PP;


int V(PP p) {
    return p.a * p.b * p.h;
}


int minV(PP p[], int N) {
    int k = 0; 
    int minv = V(p[0]);

    for (int i = 1; i < N; i++) {
        int tV = V(p[i]);
        if (tV < minv) {
            minv = tV;
            k = i;
        }
    }
    return k;
}

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
