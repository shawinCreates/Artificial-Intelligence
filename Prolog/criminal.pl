criminal(X) :- american(X), sells(X, Y, Z), weapon(Y), hostile(Z).

hostile(X) :- enemy(X, america).

missile(missile1).
missile(missile2).
weapon(X) :- missile(X).

sells(george, missile1, iraq).
sells(george, missile2, iraq).

american(george).
country(iraq).
enemy(iraq, america).