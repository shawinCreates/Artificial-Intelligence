% Rule: All people who are graduating are happy.
happy(X) :- graduating(X).

% Rule: Happy people smile.
smiles(X) :- happy(X).

% Facts: Rinku is graduating.
graduating(rinku).

% Query: Does Rinku smile?
% ?- smiles(rinku).