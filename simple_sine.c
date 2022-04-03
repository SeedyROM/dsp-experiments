/**
 * @file simple_sine.c
 * @author Zack Kollar (SeedyROM) (me@seedyrom.io)
 * @brief 
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Run: gcc -lm simple_sine.c && ./a.out | gnuplot -p -e "plot '-' with lines"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "toolbox.h"

int main() {
    double Fs = 44100; // 44100kHz
    double F = 440.0; // 440Hz
    double dt = 1.0 / Fs; // Sample time
    double theta = 2.0 * PI; // Phase

    double samples = dt * 512; // How many samples to generate
    for(double t = 0; t < samples; t += dt) {
        double value = sin(2 * PI * F * t + theta);
        printf("%f %f\n", t, value);
    }

    return 0;
}