// PART B

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
