```
function a3_test()
    n = 19; % 2n+1, n=9

    d = randn(n, 1);  
    a = randn(n, 1);  
    a((n+1)/2) = d((n+1)/2);  % ensure a(n/2+1) = d(n/2+1)

    % Construct the exact solution vector
    x_exact = ones(n, 1);

    d(1) = 10^(-15);  % Change d1 to 10^(-15)

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
>> a3_test FOR Q3C
Diagonal elements d:
    0.0000
    0.1866
    0.9509
   -0.7905
   -0.4895
    2.9745
   -0.6226
    1.9203
    0.9611
   -0.5578
   -0.1066
   -0.2152
    0.4735
    1.3656
   -1.6378
    2.0237
    0.7778
   -0.5489
   -0.1260

Off-diagonal elements a:
    0.2996
    0.2962
    1.2008
    1.0902
   -0.3587
   -0.1299
    0.7337
    0.1203
    1.1363
   -0.5578
    0.4717
    0.2883
    1.3919
   -1.3455
    0.0007
    0.0535
   -2.3419
    1.2481
    2.8092

Right-hand side vector b:
    2.8092
    1.4346
   -1.3910
   -0.7370
   -0.4887
    1.6290
    0.7693
    2.2086
    1.4328
   -0.5578
    1.0298
   -0.0948
    1.2072
    1.2357
   -1.9965
    3.1139
    1.9786
   -0.2527
    0.1736

FOR Q3C
genp output: 8.881784e-01
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
Relative error for GENP: 2.565363e-02
Relative error for GEPP: 1.972918e-16
Error bound (epsilon * cond(A)): 3.223599e-15

```

FOR Q3C
In this matrix, we set d(1) to 10^(-15), which is very small. Intuitively, we can see that the solution to the linear system is heavily influenced by the value of d(1) (Since when a diagonal element is zero, GENP will not work). 

The relative error for GENP is much larger than the error bound, which means that the error is not due to the round-off error (epsilon). Instead, it is due to the large relative error between the exact solution and the computed solution.

Since the relative error for GEPP is much smaller than the error bound, we can conclude that GEPP is more accurate than GENP at performing computations on this matrix.
