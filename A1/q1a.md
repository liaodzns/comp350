PART A

For x = 100.0: The value of x is reduced by 20 square roots in the first loop and then multiplied back in the second loop.
Every time we take the square root, we have to truncate or round the result to fit within the limits of floating-point precision.
The iterations for x = 100 look something like this: 100, 10, ~3._, ~1._, ... After 20 iterations, x will be close to, but greater than 1.
When squaring x, the small rounding errors made in the first loop are amplified, and this process repeats over each iteration.

For x = 0.1: Similar to the case with x = 100, the iterations for x = 0.1 look something like this: 0.1, ~0.3_, ~0.5_, ...
After 20 iterations, x will be close to 1, but still less than 1 since we are dealing with decimal numbers.
Similarily to performing square root functions with x = 100, computing the square root of x = 0.1 over 20 iterations will result in rounding errors.
Therefore, when we square, there will be a difference between the final value of x and 0.1.

In single precision, we have about 7 decimal digits of precision, so when we perform multiple operations on a number,
small errors can accumulate. This will lead to final results that differ from the original value of x.


#include <stdio.h>
#include <math.h>

float compute(float x, int n) {
    // sqrt n times
    for (int i = 0; i < n; i++) {
        x = sqrt(x);
    }

    // multiply n times
    for (int i = 0; i < n; i++) {
        x = x * x;
    }
    
    return x;
}

int main() {
    float x1 = 100.0f;
    float x2 = 0.1f;
    int n = 20;

    printf("x equals: %e\n", x1);
    float result1 = compute(x1, n);
    printf("final x: %e\n", result1);

    printf("x equals: %e\n", x2);
    float result2 = compute(x2, n);
    printf("final x: %e\n", result2);

    return 0;
}

PART A:
x equals: 1.000000e+02
final x: 9.001778e+01
x equals: 1.000000e-01
final x: 9.896518e-02




