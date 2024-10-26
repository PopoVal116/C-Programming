#include <stdio.h>
int main(){
        int N;
        int num=1;
        printf("Введите размер прямоугольника:");
        scanf("%d", &N);
        for(int i=0; i<N; i++){
                for(int k=0; k<N; k++){
                        printf("%d", num);
                 num++;}
        printf("\n");
        }
return 0;
}
