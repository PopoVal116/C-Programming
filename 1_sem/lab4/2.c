#include <stdio.h>
int main(){
        int N;
        scanf("%d", &N);
        for(int i=1; i<=N; i++){
             printf("%d",i);
             for(int k=1; k <=(N+1)-i; k++){
                   printf("%c", 'o');}
                   printf("\n");}
}
