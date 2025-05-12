#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

int check_input(int count, char *args[]) {
    return count == 2;
}

int get_num(char *num_str) {
    int num = atoi(num_str);
    return (num > 0) ? num : -1;
}

void show_help(char *name) {
    printf("Используй: %s <число>\n", name);
}

int main(int count, char *args[]) {
    if (!check_input(count, args)) {
        show_help(args[0]);
        return 1;
    }

    int num = get_num(args[1]);
    if (num <= 0) {
        printf("Число должно быть больше 0\n");
        return 1;
    }

    int tri_num = get_tri_num(num);
    printf("Треугольное число для n = %d: %d\n", num, tri_num);
    make_tri_file(num);
    printf("Треугольник в triangle.txt\n");
    return 0;
}