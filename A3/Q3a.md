```
function x = a3_genp(d, a, b)
    % Input:  
    % - di is the main diagonal for the matrix A
    % - ai is the digonal opposite to the main diagonal for the matrix A
    % - b is the linear combination of A's columns
    % Output
    % - x: solution vector
    %
        
    % size of matrix
    n = length(b);

    % forward elimination
    for k = 1:(n-1)/2
        % j starts from bottom row and traverses upwards
        i = n + 1 - k;
        % calculate multiplier
        mult = a(k) / d(k);
        % reduce elements on main diagonal
        d(i) = d(i) - mult * a(i);
        % reduce corresponding b value
        b(i) = b(i) - mult * b(k);
    end

    % back substitution

    x = zeros(n, 1);
    % solve for elements in lower triangular part and middle
    for k = n:-1:(n-1)/2+1
        x(k) = (b(k) / d(k));
    end
    
    % solve for elements in upper triangular part
    for k = (n-1)/2:-1:1
        f = n - k + 1;
        x(k) = (b(k) - a(f) * x(f)) / d(k);
    end
end

```

```
function x = a3_gepp(d, a, b)
    % Input:
    % - d: main diagonal of matrix A (vector of size 2n+1)
    % - a: off-diagonal elements (opposite the main diagonal)
    % - b: right-hand side vector (linear combination of A's columns)
    % Output:
    % - x: solution vector

    % Size of the matrix
    n = length(b);

    % Forward elimination with PP
    for k = 1:(n-1)/2
        i = n + 1 - k; 

        % Partial pivoting: 
        if abs(a(k)) > abs(d(k))
            % Swap the diagonal and off-diagonal elements
            temp = d(k);
            d(k) = a(k);
            a(k) = temp;

            % Swap the corresponding elements in the other row
            temp = d(i);
            d(i) = a(i);
            a(i) = temp;

            % Swap the right-hand side vector
            temp = b(k);
            b(k) = b(i);
            b(i) = temp;
        end

        % Elimination
        mult = a(k) / d(k);  % Multiplier for elimination
        d(i) = d(i) - mult * a(i);  % Update diagonal
        b(i) = b(i) - mult * b(k);  % Update RHS
    end

    % Back substitution
    x = zeros(n, 1);  % Initialize solution vector of size n
    for k = n:-1:(n-1)/2+1
        x(k) = (b(k) / d(k));
    end
    
    % solve for elements in upper triangular part
    for k = (n-1)/2:-1:1
        f = n - k + 1;
        x(k) = (b(k) - a(f) * x(f)) / d(k);
    end
end
```