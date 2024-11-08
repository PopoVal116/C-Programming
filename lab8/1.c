#include <stdio.h>
int main(){
    int N;
    printf("Введите размер матрицы(до 3): ");
    scanf("%d", &N);
    int matrix[3][4];
    printf("Введите элементы матрицы: \n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= N; j++){
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
    float x;
    float y;
    float z;
    int opr;
    if (N == 2){
        opr = matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
        x = (matrix[0][2]*matrix[1][1]-matrix[0][1]*matrix[1][2])/opr;
        y = (matrix[0][0]*matrix[1][2]-matrix[0][2]*matrix[1][0])/opr;
        printf("Определитель матрицы методом Крамера равен %d \n", opr);
        printf("x = %.2f \n", x);
        printf("y = %.2f\n", y);
    }
    else if(N == 3){
        opr = matrix[0][0]*matrix[1][1]*matrix[2][2]+matrix[0][1]*matrix[1][2]*matrix[2][0]+matrix[0][2]*matrix[1][0]*matrix[2][0]-matrix[0][2]*matrix[1][1]*matrix[2][0]-matrix[0][1]*matrix[1][0]*matrix[2][2]-matrix[0][0]*matrix[1][2]*matrix[2][1];
        x = (matrix[0][3]*matrix[1][1]*matrix[2][2]+matrix[0][1]*matrix[1][2]*matrix[2][3]+matrix[0][2]*matrix[1][3]*matrix[2][1]-matrix[0][2]*matrix[1][1]*matrix[2][3]-matrix[0][1]*matrix[1][3]*matrix[2][2]-matrix[0][3]*matrix[1][2]*matrix[2][1])/opr;
        y = (matrix[0][0]*matrix[1][3]*matrix[2][2]+matrix[0][3]*matrix[1][2]*matrix[2][0]+matrix[0][2]*matrix[1][0]*matrix[2][3]-matrix[0][2]*matrix[1][3]*matrix[2][0]-matrix[0][3]*matrix[1][0]*matrix[2][2]-matrix[0][0]*matrix[1][2]*matrix[2][3])/opr;
        z = (matrix[0][0]*matrix[1][1]*matrix[2][3]+matrix[0][1]*matrix[1][3]*matrix[2][0]+matrix[0][3]*matrix[1][0]*matrix[2][1]-matrix[0][3]*matrix[1][1]*matrix[2][0]-matrix[0][1]*matrix[1][0]*matrix[2][3]-matrix[0][0]*matrix[1][3]*matrix[2][1])/opr;
        printf("Определитель матрицы равен %d \n", opr);
        printf("x = %.2f \n", x);
        printf("y = %.2f \n", y);
        printf("z = %.2f \n", z);
    }
    else{
        opr = matrix[0][0];
    }

}