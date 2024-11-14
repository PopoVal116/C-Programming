//Элементы тех столбцов матрицы А,  суммы которых больше 12, уменьшить на  элемент главной диагонали 
//соответствующего столбца. Определить количество таких строк.  Побочную диагональ упорядочить по убыванию.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 //максимальный размер матрицы

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) { // ввод матрицы
    printf("Введите элементы матрицы %d x %d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            while (1) {
                printf("Элемент [%d][%d]: ", i + 1, j + 1);
                if (scanf("%d", &matrix[i][j]) != 1) {
                    printf("Ошибка ввода. Пожалуйста, введите целое число\n");
                    return;
                } else if (matrix[i][j] < 0) {
                    printf("Ошибка: элемент не может быть отрицательным. Пожалуйста, заполните матрицу заново\n");
                    return; // возвращаемся к вызову в main для повторного ввода
                } else {
                    break;
                }
            }
        }
    }
}

void processMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) { 
    int count = 0;

    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][j];
        }

        if (sum > 12) { //подсчет стоблцов с суммой >12
            int diagonalElement = matrix[j][j]; 
            for (int i = 0; i < n; i++) {
                matrix[i][j] -= diagonalElement; 
            }
            count++;
        }
    }

    printf("Количество столбцов с суммой > 12: %d\n", count);
}

void sortSecondaryDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    // Находим элементы побочной диагонали
    int diagonal[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        diagonal[i] = matrix[i][n - 1 - i];
    }

    // Сортируем элементы побочной диагонали по убыванию
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (diagonal[i] < diagonal[j]) {
                int temp = diagonal[i];
                diagonal[i] = diagonal[j];
                diagonal[j] = temp;
            }
        }
    }

    // Записываем отсортированные элементы обратно в матрицу
    for (int i = 0; i < n; i++) {
        matrix[i][n - 1 - i] = diagonal[i];
    }
}


void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    printf("Матрица после обработки:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    while (1) {
        printf("Введите размерность матрицы (n <= %d): ", MAX_SIZE);
        if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) { 
            printf("Ошибка ввода. Пожалуйста, введите целое число от 1 до %d\n", MAX_SIZE);
            return 0;
        } else {
            break;
        }
    }

    while (1) {
        inputMatrix(matrix, n);
        
        // проверка н а отрицательные элементы
        int hasNegative = 0;
        for (int i = 0; i < n && !hasNegative; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) {
                    hasNegative = 1;
                    break;
                }
            }
        }

        if (!hasNegative) {
            break; // если нет отрицательных элементов выход из цикла
        }
    }

    printMatrix(matrix, n);
    processMatrix(matrix, n);
    sortSecondaryDiagonal(matrix, n);
    printMatrix(matrix, n);

    return 0;
}
