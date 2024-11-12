cat(tom).
animal(X):-cat(X).


father(chintu,mintu).
mother(mintu,pintu).
parent(X,Y):-father(X,Y).
parent(X,Y):-mother(X,Y).
grandparent(X,Y):-parent(X,Z),parent(Z,Y).
ancestor(X,Y):-parent(X,Y).