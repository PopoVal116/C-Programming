#include <stdio.h>
int main(){
        int n=2;
        int a;
        scanf("%d", &a);
        int flag =0;
        while(a%n!=0){
             n++;
             if(n==a){
                   flag =1;
                   break;}
}
if(flag==1){printf("простое число");}
else{printf("составное число");}
}
