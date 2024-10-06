```
function a3_test()
    n = 19; % 2n+1, n=9

    d = randn(n, 1);  
    a = randn(n, 1);  
    a((n+1)/2) = d((n+1)/2);  % ensure a(n/2+1) = d(n/2+1)

    % Construct the exact solution vector
    x_exact = ones(n, 1);

    d(1) = 10^(-15);  % Change d1 to 10^(-15)
    a(1) = 10^(-8);
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
>> a3_test  FOR Q3D
Diagonal elements d:
    0.0000
    2.1920
    1.5357
    0.9073
    0.4023
   -0.5384
   -0.1152
    1.8220
   -2.0215
   -0.6370
   -0.1888
    0.1483
   -1.7839
    0.5291
    0.7297
   -0.9401
   -0.2593
   -1.2135
    1.6245

Off-diagonal elements a:
    0.0000
   -0.2509
   -0.9255
    0.0987
    1.6843
    0.2753
    0.3533
   -1.2004
    0.1661
   -0.6370
   -1.3814
    1.1283
    2.4654
   -1.5579
   -2.0666
   -0.0726
    0.7591
   -0.0817
   -0.1585

Right-hand side vector b:
   -0.1585
    2.1103
    2.2948
    0.8347
   -1.6644
   -2.0963
    2.3502
    2.9503
   -3.4029
   -0.6370
   -0.0227
   -1.0521
   -1.4306
    0.8043
    2.4140
   -0.8415
   -1.1847
   -1.4644
    1.6245

FOR Q3D
genp output: 9.992007e-01
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
Relative error for GENP: 1.833669e-04
Relative error for GEPP: 1.394267e-09
Error bound (epsilon * cond(A)): 6.993755e-07
```

FOR Q3D
In this example, d(1) is still very small, but we have also made a(1) small. I notice that the error bound is much larger than in other iterations of this question, meaning that the matrix is much more ill-conditioned.

The relative error for GENP is still larger than the error bound, which means that the error is not due to the round-off error (epsilon). Instead, it is due to the large relative error between the exact solution and the computed solution.

Since the relative error for GEPP is much smaller than the error bound, we can conclude that GEPP is more accurate than GENP at performing computations on this matrix.
