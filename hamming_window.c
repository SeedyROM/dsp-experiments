/**
 * @file hamming_window.c
 * @author Zack Kollar (SeedyROM) (me@seedyrom.io)
 * @brief 
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Run: gcc -lm hamming_window.c && ./a.out | gnuplot -p -e "plot '-' with lines"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

const double hamming_window(const double n, const double M) {
    const double half_M = M / 2;
    if(abs(n) > half_M) {
        return 0.0;
    } else {
        return 0.54 + 0.45 * cos(n * PI / half_M);
    }
}

int main()
{
    double M = 2;

    for(double n = -M/2; n < M/2; n += 0.1) {
        double h = hamming_window(n, M);
        printf("%f %f\n", n, h);
    }    
    return 0;
}