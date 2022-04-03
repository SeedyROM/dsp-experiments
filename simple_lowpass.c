/*
* WARNING
* This a garbage example from a much larger, more math filled tutorial. Not helpful, ignore THIS!
*/

/**
 * @file simple_lowpass.c
 * @author Zack Kollar (SeedyROM) (me@seedyrom.io)
 * @brief 
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

typedef double sample;

sample simple_lowpass(sample *x, sample *y, int M, sample xm1) {
    y[0] = x[0] + xm1;

    for(int n = 1; n < M; n++) {
        y[n] = x[n] + x[n-1];
    }

    return x[M-1];
}

int main(int argc, char **argv) {
    double x[10] = {1,2,3,4,5,6,7,8,9,10};
    double y[10];

    int N = 10;
    int M = N / 2;
    double xm1 = 0;

    xm1 = simple_lowpass(&x[0], &y[0], M, xm1);
    xm1 = simple_lowpass(&x[M], &y[M], M, xm1);

    for (int i=0; i < N; i++) {
        printf("x[%d]=%f\ty[%d]=%f\n", i, x[i], i, y[i]);
    }

    return 0;
}