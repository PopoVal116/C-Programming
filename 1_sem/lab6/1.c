#include <stdio.h>
int main(){
    int A[5]={123, 45, 3, 7, 54};
    int B[5]={-13, -72, 23, 5, -44};
    int C[5]={0};
    int max_A = A[0];
    int otr_B=0;
    int sum_C=0;
    for(int i; i<5; i++){
         if (B[i]<0){
            otr_B++;
        }
        C[i]=A[i]+B[i];
        sum_C+=C[i];
        if (max_A<A[i]){
            max_A=A[i];
        }
    }
    printf("Максимальное из А: %d\n Количество отрицательных в В: %d\n Среднее арифметическое среди всех элементов С: %.2lf\n", max_A, otr_B, (double)sum_C/5);
    
}
