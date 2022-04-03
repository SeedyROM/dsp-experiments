#include "toolbox.h"

//
// Special signals!
// Where n is the current sample/point in time
// All examples below are from -N, N where 0 is the center in discrite time
// And the x axis is time
//

//
// Delta signal δ[n]: AKA the dirac delta, AKA an IMPULSE
//
// Example:
//
//         o
//         |
//         |
//   o o o | o o o
// < - - - 0 - - - >
//
static inline double delta(double n)
{
    return n == 0 ? 1 : 0;
}

//
// Unit signal/step function: u[n]
//
// Example:
//
//         o o o o
//         | | | |
//         | | | |
//   o o o | | | |
// < - - - 0 - - - >
//
static inline double unit(double n)
{
    return n >= 0 ? delta(n) : 0; // This can be generalized to `return n >= 0 ? 1 : 0`
                                  // I'm doing this for my brain
}

//
// TODO: How is this a weighted sum?
// According to people: any signal can be described by the weighted sum of shifted impulses
// 2δ[n+1] + 1δ[n] + -1δ[n-1] ... (so on and so forth)
//

// UGH I'm not getting this... What how the fuck does shifting work in discrete time/programming?
// Maybe the examples will help?
// TODO: Apparently the next step is convolution...