% Rule: All dogs are animals.
animal(X) :- dog(X).

% Rule: All animals will die.
die(X) :- animal(X).

% Facts: Puppy is a dog.
dog(puppy).

% Query: Will Puppy die?
% ?- die(puppy).