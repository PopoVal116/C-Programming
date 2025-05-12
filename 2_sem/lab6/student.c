#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Student addStudent(const char name[], int m, int f, int i) {
    struct Student s;
    strncpy(s.name, name, sizeof(s.name) - 1);
    s.name[sizeof(s.name) - 1] = '\0';
    s.ball_math = m; s.ball_fiz = f; s.ball_inf = i;
    s.total = m + f + i;
    return s;
}

void printStudents(struct Student arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("Имя: %s | Матем: %d | Физ: %d | Инф: %d | Общий балл: %d\n", 
               arr[i].name, arr[i].ball_math, arr[i].ball_fiz, arr[i].ball_inf, arr[i].total);
    printf("\n");
}

void generateStudents(struct Student arr[], int n) {
    char *names[] = {"Алексей", "Мария", "Иван", "Светлана", "Дмитрий", 
                     "Анна", "Максим", "Елена", "Анастасия", "Сергей"};
    for (int i = 0; i < n; i++)
        arr[i] = addStudent(names[rand() % 10], rand() % 101, rand() % 101, rand() % 101);
}

void selectionSort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j].total > arr[maxIdx].total)
                maxIdx = j;
        struct Student temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

void countingSort(struct Student arr[], int n) {
    struct Student output[n];
    int count[MAX_SCORE + 1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i].total]++;
    for (int i = MAX_SCORE - 1; i >= 0; i--)
        count[i] += count[i + 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i].total] - 1] = arr[i];
        count[arr[i].total]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void testSorting(void (*sortFunc)(struct Student[], int), const char *name) {
    struct Student students[N];
    generateStudents(students, N);
    size_t data_size = N * sizeof(struct Student);

    printf("До сортировки (%s):\n", name);
    printStudents(students, N);

    clock_t start = clock();
    sortFunc(students, N);
    clock_t end = clock();

    printf("После сортировки (%s):\n", name);
    printStudents(students, N);
    printf("Время работы %s: %f секунд\n", name, (double)(end - start) / CLOCKS_PER_SEC);
    printf("Размер данных %s: %lu байт\n\n", name, data_size);
}