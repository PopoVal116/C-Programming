#include <stdio.h>
int main(){
        int s;
        int i;
        int n;
        scanf("%d", &n);
        for(s=1,i=1;i<=n;i++){
              s=s*i;}
        printf("факториал числа равен %d", s);
}
