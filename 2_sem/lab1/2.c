#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5                // Количество студентов
#define MAX_SCORE 300     // Максимальный возможный балл

// Структура для хранения информации о студенте
struct Student {
    char name[64];       // Имя студента
    int ball_math;      // Оценка по математике
    int ball_fiz;       // Оценка по физике
    int ball_inf;       // Оценка по информатике
    int total;          // Общий балл
};

// Функция для создания студента
struct Student addStudent(const char name[], int m, int f, int i) {
    struct Student s;
    strncpy(s.name, name, sizeof(s.name) - 1); // Копирование имени
    s.name[sizeof(s.name) - 1] = '\0';          // Обеспечение завершения строки
    s.ball_math = m; s.ball_fiz = f; s.ball_inf = i; // Установка оценок
    s.total = m + f + i;                        // Вычисление общего балла
    return s;                                   // Возврат студента
}

// Функция для вывода информации о студентах
void printStudents(struct Student arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("Имя: %s | Матем: %d | Физ: %d | Инф: %d | Общий балл: %d\n", 
               arr[i].name, arr[i].ball_math, arr[i].ball_fiz, arr[i].ball_inf, arr[i].total);
    printf("\n");
}


// Функция сортировки выбором
void selectionSort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i; // Индекс максимального элемента
        for (int j = i + 1; j < n; j++)
            if (arr[j].total > arr[maxIdx].total) // Поиск максимального
                maxIdx = j;
        // Обмен местами
        struct Student temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

void countingSort(struct Student arr[], int n) {
    struct Student output[n]; // Массив для отсортированных студентов
    int count[MAX_SCORE + 1] = {0}; // Массив для подсчета
    // Подсчет количества студентов с каждым баллом
    for (int i = 0; i < n; i++) {
        count[arr[i].total]++;
    }
    // Преобразование массива count для получения индексов
    for (int i = MAX_SCORE - 1; i >= 0; i--) {
        count[i] += count[i + 1];
    }
    // Сортировка студентов в массив output (в порядке убывания)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i].total] - 1] = arr[i]; // Вставка
        count[arr[i].total]--; // Уменьшение счетчика
    }
    // Копирование отсортированных студентов обратно в arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Функция для генерации случайных студентов
void generateStudents(struct Student arr[], int n) {
    char *names[] = {"Алексей", "Мария", "Иван", "Светлана", "Дмитрий", 
                     "Анна", "Максим", "Елена", "Анастасия", "Сергей"};
    for (int i = 0; i < n; i++)
        // Создание студента с случайным именем и оценками
        arr[i] = addStudent(names[rand() % 10], rand() % 101, rand() % 101, rand() % 101);
}

// Функция для сортировки
void testSorting(void (*sortFunc)(struct Student[], int), const char *name) { //void (*sortFunc)(struct Student[], int) — указатель на функцию сортировки, 
                                                                              //которая будет вызываться. 
                                                                              // const char *name — имя сортировки, которое будет выводиться в сообщениях.
    struct Student students[N]; // Массив студентов
    generateStudents(students, N); // Генерация студентов
    size_t data_size = N * sizeof(struct Student); // Размер данных
    
    printf("До сортировки (%s):\n", name);
    printStudents(students, N); // Вывод студентов до сортировки

    clock_t start = clock(); // Запись времени начала сортировки
    sortFunc(students, N); // Вызов функции сортировки
    clock_t end = clock(); // Запись времени окончания сортировки

    printf("После сортировки (%s):\n", name);
    printStudents(students, N); // Вывод студентов после сортировки
    printf("Время работы %s: %f секунд\n", name, (double)(end - start) / CLOCKS_PER_SEC); // Вывод времени выполнения сортировки
    printf("Размер данных %s: %lu байт\n\n", name, data_size); // Вывод размера данных
}

// Основная функция программы
int main() {
    srand(time(NULL)); // Случайные числа
    testSorting(selectionSort, "Selection Sort"); // Тестирование сортировки выбором
    testSorting(countingSort, "Counting Sort"); // Тестирование сортировки подсчетом

    printf("\nИнформация о процессоре:\n");
    // Вывод информации о процессоре
    system("cat /proc/cpuinfo | grep 'model name' | uniq"); // Модель процессора
    system("cat /proc/cpuinfo | grep 'cpu MHz' | uniq"); // Тактовая частота процессора
    return 0; 
}
