% Define a predicate to perform calculations
calculate :-
    write('Enter the first number: '),
    read(X),
    write('Enter the second number: '),
    read(Y),

    Sum is X + Y,
    Difference is X - Y,
    Product is X * Y,
    
    % Check for division by zero
    (Y =\= 0 -> Division is X / Y ; Division = 'undefined (division by zero)'),

    % Display the results
    write('Sum: '), write(Sum), nl,
    write('Difference: '), write(Difference), nl,
    write('Product: '), write(Product), nl,
    write('Division: '), write(Division), nl.
