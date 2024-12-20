% Define mammals
mammal(X) :- horse(X).
mammal(X) :- cow(X).
mammal(X) :- pig(X).

% Define horses
horse(bluebeard).
horse(Y) :- parent(X, Y), horse(X).

% Define inverse relationship between parent and offspring
offspring(Y, X) :- parent(X, Y).

% Every mammal has a parent
has_parent(X) :- mammal(X), parent(_, X).

% Add facts about parent-child relationships
parent(bluebeard, charlie). 
