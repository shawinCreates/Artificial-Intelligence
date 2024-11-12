mammal(X) :- horse(X).
mammal(X) :- cow(X).
mammal(X) :- pig(X).

horse(bluebeard).          
horse(Y) :- parent(X, Y), horse(X). 

offspring(Y, X) :- parent(X, Y). 

has_parent(X) :- mammal(X), parent(_, X).