#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void bubbleSort(int nums[], int count, int *comps, int *moves) {
    *comps = 0;
    *moves = 0;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            (*comps)++;
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                (*moves) += 3;
            }
        }
    }
}

void make_down_nums(int nums[], int count) {
    for (int i = 0; i < count; i++) {
        nums[i] = count - i;
    }
}

void make_random_nums(int nums[], int count) {
    for (int i = 0; i < count; i++) {
        nums[i] = rand() % 100;
    }
}

void make_up_nums(int nums[], int count) {
    for (int i = 0; i < count; i++) {
        nums[i] = i + 1;
    }
}