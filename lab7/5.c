#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char output[10000] = "";
    char str[]="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char *word = strtok(str, " ");
    while (word != NULL) {
        strcat(output, "?");
        strcat(output, word);
        strcat(output, " ");
        word = strtok(NULL, " ");
    }
    output[strlen(output) - 1] = "0";
    printf("Результат: %s\n", output);
}
