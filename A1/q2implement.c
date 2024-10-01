// PART B
#include <stdio.h>
#include <math.h>

void compute(int n) {
    double p = 2 * sqrt(2);
    for (int i = 2; i < n; i++) {
        double square = pow(p / pow(2, i), 2);  // (Pn/2^n)^2
        p = (2 * p) / (sqrt(2 + (2 * sqrt(1 - square))));

        printf("p%d = %le\n", i + 1, p);
    }
}

int main() {
    compute(35);
    return 0;
}
