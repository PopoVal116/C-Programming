#include <stdio.h>
int main(){
        int a,s,n,k;
        scanf("%d", &a);
        for(n=a,s=0;n!=0;n=n/10){
           k=n%10;
           s+=k;}
printf("сумма цифр числа а равна %d", s);
}
