#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
    srand(time(NULL));
    testSorting(selectionSort, "Selection Sort");
    testSorting(countingSort, "Counting Sort");

    printf("\nИнформация о процессоре:\n");
    system("cat /proc/cpuinfo | grep 'model name' | uniq");
    system("cat /proc/cpuinfo | grep 'cpu MHz' | uniq");
    return 0;
}