% Rule: All Pompeians are Romans.
roman(X) :- pompeian(X).

% Rule: All Romans were either loyal to Caesar or hated him.
hates(X, caesar) :- roman(X), \+ loyal(X, caesar).

% Rule: People only try to assassinate rulers they are not loyal to.
loyal(X, Y) :- \+ tried_to_assassinate(X, Y).
\+ loyal(X, Y) :- tried_to_assassinate(X, Y), ruler(Y).

% Facts: Marcus tried to assassinate Caesar.
tried_to_assassinate(marcus, caesar).

% Facts: Marcus is a Pompeian.
pompeian(marcus).

% Facts: Caesar is a ruler.
ruler(caesar).

% Query: Did Marcus hate Caesar?
% ?- hates(marcus, caesar).
