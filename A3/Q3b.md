```
function a3_test()
    n = 19; % 2n+1, n=9

    d = randn(n, 1);  
    a = randn(n, 1);  
    a((n+1)/2) = d((n+1)/2);  % ensure a(n/2+1) = d(n/2+1)

    % Construct the exact solution vector
    x_exact = ones(n, 1);

    % Construct vector b
    b = zeros(n, 1);
    for i = 1:n
        if i ~= (n+1)/2
            b(i) = d(i) + a(n+1-i);  % Symmetric structure of the matrix
        else
            b(i) = d(i);  % Special case for the middle element
        end
    end


    fprintf('Diagonal elements d:\n');
    disp(d);
    fprintf('Off-diagonal elements a:\n');
    disp(a);
    fprintf('Right-hand side vector b:\n');
    disp(b);

    % solve using GENP
    x_genp = a3_genp(d, a, b);
    fprintf('genp output: %e\n', x_genp)

    % solve using GEPP
    x_gepp = a3_gepp(d, a, b);
    fprintf('gepp output: %e\n', x_gepp)

    % relative errors for GENP and GEPP
    relative_error_genp = norm(x_exact - x_genp) / norm(x_exact);
    relative_error_gepp = norm(x_exact - x_gepp) / norm(x_exact);

    % coefficient matrix A and compute its condition number
    A = construct_matrix(d, a, n);
    condition_number_A = cond(A);

    % compute the product of epsilon and condition number
    epsilon = eps;
    error_bound = epsilon * condition_number_A;

    fprintf('Relative error for GENP: %e\n', relative_error_genp);
    fprintf('Relative error for GEPP: %e\n', relative_error_gepp);
    fprintf('Error bound (epsilon * cond(A)): %e\n', error_bound);
end

function A = construct_matrix(d, a, n)
    % constructs the matrix A based on d and a according to the given structure
    A = zeros(n);  % initialize the matrix
    for i = 1:n
        A(i,i) = d(i);  % diagonal elements
        A(n+1-i,i) = a(i);  % off-diagonal elements
    end
end

```

```
>> a3_test  FOR Q3B
Condition number of A: 3.606948e+02
Diagonal elements d:
    0.5108
   -0.6563
   -0.1250
   -0.5305
    0.1056
    1.1284
    0.7425
    1.1436
   -0.9147
    0.1798
   -0.9833
    0.3848
    0.3257
    1.2963
    1.0992
    0.6532
   -0.5051
   -0.4760
   -2.0516

Off-diagonal elements a:
   -0.4483
   -1.5512
    0.9298
    0.9019
    0.1383
   -0.3784
    0.1431
    1.6050
    1.3491
    0.1798
    0.1684
   -1.1205
    0.4007
    0.7391
    0.9000
   -1.5312
    0.5046
   -0.8642
   -0.3766

Right-hand side vector b:
    0.1343
   -1.5205
    0.3796
   -2.0617
    1.0056
    1.8674
    1.1432
    0.0231
   -0.7463
    0.1798
    0.3658
    1.9899
    0.4688
    0.9179
    1.2375
    1.5552
    0.4248
   -2.0272
   -2.4999

Q3B
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
genp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
gepp output: 1.000000e+00
Relative error for GENP: 5.392603e-15
Relative error for GEPP: 3.386875e-15
Error bound (epsilon * cond(A)): 8.009033e-14
```

FOR Q3B
The fact that the relative error for both GENP and GEPP is very close to machine epsilon indicates that the matrix is well-conditioned and the solutions are accurate to within the machine precision.

Since GEPP and GENP produce the same results (the numbers are so close that they are rounded to 1), we are sure that their function implementations are correct. 
However, we can see that the relative error for GENP is slightly larger than that for GEPP. This is because GEPP uses partial pivoting to ensure numerical stability, which can sometimes lead to a slightly smaller relative error for the solution. Since both relative erorrs are smaller than the error bound, we can conclude that both methods performed well for this particular matrix.
