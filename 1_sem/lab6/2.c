#include <stdio.h>
int main() {
    int A[7]={17,53,28,3332,1,1333,66};
    int max_1 = A[0];
    int min_1 = 9994;
    for(int i=0; i<7; i++){
        if (A[i] %2 !=0){
           if (max_1<A[i]){
            max_1=A[i];
            }
        }
        if (A[i] %2 ==0){
           if (min_1>A[i]){
            min_1=A[i];
        }
    }
}
printf("Максимальный среди нечетных: %d\n Минимальное среди четных: %d\n", max_1, min_1);
}
