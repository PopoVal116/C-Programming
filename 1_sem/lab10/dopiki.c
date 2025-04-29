#include "function.h"
#include <stdio.h>

int V(PP p) {
    return p.a * p.b * p.h;
}


int minV(PP p[], int N) {
    int k = 0; 
    int minv = V(p[0]);

    for (int i = 1; i < N; i++) {
        int tV = V(p[i]);
        if (tV < minv) {
            minv = tV;
            k = i;
        }
    }
    return k;
}
