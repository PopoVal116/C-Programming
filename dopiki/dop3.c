#include <stdio.h>
#include <string.h>

int main(){
    char s[100];
    printf("Введите строку: ");
    scanf("%s", s);
    int nums[10000];
    int c =0;
    char *prom = strtok(s, ",");
    while (prom != NULL){
        int nachalo;
        int konets;

        if(sscanf(prom, "%d-%d", &nachalo, &konets) == 2){
            for(int i = nachalo; i <= konets; i++){
                nums[c++]=i;
            }
        } else{
            int num;
            if(sscanf(prom, "%d", &num) == 1){
                nums[c++]=num;
            }
        }
        prom = strtok(NULL, ",");
    }
    for (int i = 0; i < c - 1; i++) {
        for (int j = 0; j < c - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < c; i++) {
        printf("%d", nums[i]);
    }
    printf("\n");

    return 0;
}