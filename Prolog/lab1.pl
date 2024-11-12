rainy(kathmandu).
rainy(pokhara).
dull(X):-rainy(X).

eats(ram,mangoes).

parent(tom,bob).
parent(pom,bob).
parent(tom,liz).
parent(bob,ann).
parent(bob,pat).
parent(pat,jim).

located_in(bmc,bhaktapur).
located_in(baneshwor,kathmandu).
located_in(sahidgate,kathmandu).
located_in(pokhara,kaski).
located_in(X,nepal):-located_in(X,bhaktapur).
located_in(X,nepal):-located_in(X,kathmandu).
located_in(X,western_region):-located_in(X,kaski).
located_in(X,asia):-located_in(X,nepal).
located_in(X,asia):-located_in(X,western_region).


gcd(X,X,X).
gcd(X,Y,D):-X < Y , Y1 is Y - X, gcd(X,Y1,D).
gcd(X,Y,D):-Y < X , gcd(Y,X,D).
lcm(X,Y,LCM):-gcd(X,Y,D), LCM is (X*Y)//D.

member(X,[X|Tail]).
member(X,[Head|Tail]):-member(X,Tail).

sum:-write('X='),read(X),write('Y='),read(Y),S is X+Y,
write('The Sum is '),nl,write(S).

start:-radius(R),
circ(R,C),write('Circumference is '),write(C),nl,
area(R,A),write('Area is '),write(A).

radius(R):-write('Radius= '),read(R).
circ(R,C):-C is 2*3.14*R.
area(R,A):-A is 3.14*R*R.

animal(X):-dog(X).
die(X):-animal(X).
dog(jimmy).


stupid(X):-oversmart(X).
naughty(X):-child(X,Y),stupid(Y).
child(ram,hari).
oversmart(hari).

father(chintu,mintu).
mother(mintu,pintu).
parent(X,Y):-father(X,Y).
parent(X,Y):-mother(X,Y).
grandparent(X,Y):-parent(X,Z),parent(Z,Y).
ancestor(X,Y):-parent(X,Y).
