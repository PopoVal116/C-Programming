#include <stdio.h>
#include "triangle.h"

int get_tri_num(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return n + get_tri_num(n - 1);
}

void make_tri_file(int n) {
    FILE *file = fopen("triangle.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла triangle.txt\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            fprintf(file, "* ");
        }
        fprintf(file, "\n");
    }
    fclose(file);
}