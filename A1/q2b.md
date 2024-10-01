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

PART B:
p3 = 3.061467e+00
p4 = 3.121445e+00
p5 = 3.136548e+00
p6 = 3.140331e+00
p7 = 3.141277e+00
p8 = 3.141514e+00
p9 = 3.141573e+00
p10 = 3.141588e+00
p11 = 3.141591e+00
p12 = 3.141592e+00
p13 = 3.141593e+00
p14 = 3.141593e+00
p15 = 3.141593e+00
p16 = 3.141593e+00
p17 = 3.141593e+00
p18 = 3.141593e+00
p19 = 3.141593e+00
p20 = 3.141593e+00
p21 = 3.141593e+00
p22 = 3.141593e+00
p23 = 3.141593e+00
p24 = 3.141593e+00
p25 = 3.141593e+00
p26 = 3.141593e+00
p27 = 3.141593e+00
p28 = 3.141593e+00
p29 = 3.141593e+00
p30 = 3.141593e+00
p31 = 3.141593e+00
p32 = 3.141593e+00
p33 = 3.141593e+00
p34 = 3.141593e+00
p35 = 3.141593e+00


PART B:
From the original equation, the errors in calculation come from the expression inside the outer square root; which is "1 minus the inner square root".
```
1 - sqrt(1 - square);
```
Where square = pow(p / pow(2, i), 2); (simply called square since we square the value inside the expression)

Therefore, in order to rationalize original equation properly, we have to get rid of the fact that we must do "1 minus the inner square root".

By bringing in the outside 2 and simplifying the expression to "2 - 2sqrt(1 - square)", we can multiply the numerator and denominator by
2 + 2sqrt(1 - square) to achieve sqrt(a^2 + b^2) using (a-b)(a+b). After simplifying, the final expression is 2p/(sqrt(2 + 2sqrt(1-square))), and
the previous need for subtraction is replaced by addition, which does not violate the bounds of double precision.

