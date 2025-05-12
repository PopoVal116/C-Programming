#ifndef STUDENT_H
#define STUDENT_H

#define N 5
#define MAX_SCORE 300

struct Student {
    char name[64];
    int ball_math, ball_fiz, ball_inf, total;
};

struct Student addStudent(const char name[], int m, int f, int i);
void printStudents(struct Student arr[], int n);
void generateStudents(struct Student arr[], int n);
void selectionSort(struct Student arr[], int n);
void countingSort(struct Student arr[], int n);
void testSorting(void (*sortFunc)(struct Student[], int), const char *name);

#endif