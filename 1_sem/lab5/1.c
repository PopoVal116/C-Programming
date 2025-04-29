#include <stdio.h>
int step(unsigned int n) {
    return (n > 0) && ((n & (n - 1)) == 0); //проверяет является ли число степенью двойки
}
int main(){
    int n;
    scanf("%d", &n);
    if (step(n)){
        printf("%d является степенью числа 2\n", n);
    }
    else{
        printf("%d не является степенью числа 2\n", n);
    }
}
