PART B

For x = 100.0:
When squaring x repeatedly, the value of x becomes extremely large and cannot be represented by single precision anymore. When squaring ten 20 times, we get
10^256, which is larger than the largest decimal number representable in single precision floating point value, 3.40282347E+38. Therefore this value cannot be properly represented and leads
to overflow. When we enter the second loop and try to perform the square root, the value of x has already been rounded to infinity, and it's value cannot be restored.

For x = 0.1:
Squaring 0.1 multiple times causes X to move towards zero. After 20 iterations, x will be smaller than 1.17549435E-38, the smallest positive decimal number representable in floating point number in single precision. Therefore x will not even be in subnormal range and the value of x will be rounded to zero.
There fore when taking the square root multiple times, we are taking the square root of zero many times, which will result in zero.

#include <stdio.h>
#include <math.h>

float compute(float x, int n) {
    // multiply n times
    for (int i = 0; i < n; i++) {
        x = x * x;
    }

    // sqrt n times
    for (int i = 0; i < n; i++) {
        x = sqrt(x);
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

PART B:
x equals: 1.000000e+02
final x: inf
x equals: 1.000000e-01
final x: 0.000000e+00