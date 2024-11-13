% Rule: All oversmart persons are stupid.
stupid(X) :- oversmart(X).

% Rule: Children of all stupid persons are naughty.
naughty(Y) :- child(Y, X), stupid(X).

% Facts: Ram is the child of Hari.
child(ram, hari).

% Facts: Hari is oversmart.
oversmart(hari).

% Query: Is Ram naughty?
% ?- naughty(ram).