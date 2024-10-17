#include <stdio.h>
int main(){
        int s;
        int n;
        int a;
        scanf("%d", &a);
        for( s=0, n=2; n<a; n++){
              if(a%n==0){
              s=1;
              break;}}
          if(s==0){
              printf("число простое");}
          else{ printf("число непростое");}
}

