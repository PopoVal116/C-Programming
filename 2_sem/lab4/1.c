#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    char filename[100], line[MAX_LINE_LENGTH], longest_line[MAX_LINE_LENGTH] = "";
    int max_length = 0;

    if (argc > 1){
        strncpy(filename, argv[1], 99);
        filename[99] = '\0';
    } else {
        printf("Введите имя файла: ");
        scanf("%99s", filename);
    }

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Ошибка открытия файла");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        int len = strlen(line);
        if (line[len - 1] == '\n') line[--len] = '\0';
        if (len > max_length) {
            max_length = len;
            strcpy(longest_line, line);
        }
    }
    fclose(fp);

    for (int i = 0, j = max_length - 1; i < j; i++, j--) {
        char temp = longest_line[i];
        longest_line[i] = longest_line[j];
        longest_line[j] = temp;
    }

    printf("Самая длинная строка в обратном порядке: %s\n", longest_line);
    return 0;
}
