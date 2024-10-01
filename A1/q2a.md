#include <stdio.h>
#include <math.h>

void compute(int n) {
    // perimeter with n = 2:
    double p = 2 * sqrt(2);

    for (int i = 2; i < n; i++) {
        double square = pow(p / pow(2, i), 2);  // (Pn/2^n)^2
        p = pow(2, i) * sqrt(2 * (1 - sqrt(1 - square)));
        printf("p%d = %le\n", i + 1, p);
    }
}

int main() {
    compute(35);
    return 0;
}


PART A:
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
p19 = 3.141594e+00
p20 = 3.141597e+00
p21 = 3.141597e+00
p22 = 3.141674e+00
p23 = 3.141830e+00
p24 = 3.142451e+00
p25 = 3.142451e+00
p26 = 3.162278e+00
p27 = 3.162278e+00
p28 = 3.464102e+00
p29 = 4.000000e+00
p30 = 0.000000e+00
p31 = 0.000000e+00
p32 = 0.000000e+00
p33 = 0.000000e+00
p34 = 0.000000e+00
p35 = 0.000000e+00


.

PART A:
As p increases from 3 to 15, the value of p gets closer and closer to the true value of pi.
From p16 to p18, there is slight fluctuation in the value of p that does not follow the trends of previous iterations. This is most likely
due to floating-point precision.
From p19 to p21, we start to see a more significant difference between these values and the previous iterations of p. These iterations also start to 
deviate noticably from the true value of pi, indicating the computation is starting to introduce more numerical errors.
From p22 to p35, we see an even more significant difference in the ten-thousandths place of decimal, followed by a difference in the hundredths place,
followed by a sudden increase in the value of p at p28 and p29, followed by zeroes. These zeroes are a result of underflow in the calculation underneath the outer square root - "1 minus the inner square root". 

So starting from p = 30, the expression is no longer able to properly perform calculations because:
p/2^n squared becomes increasingly small, therefore 1 - p/2^n is very close to 1. The square root of 1 - p/2^n is also close to 1, and finally, taking 1 minus 1 - p/2^n wil result in a rounding to zero when the value of it is less than half the machine epsilon.
