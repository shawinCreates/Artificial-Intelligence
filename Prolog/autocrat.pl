% Rule: All greedy leaders are autocrats.
autocrat(X) :- greedy_leader(X).

% Rule: Autocrats are evil.
evil(X) :- autocrat(X).

% Facts: Shyam is a greedy leader.
greedy_leader(shyam).

% Facts: Gopal is an honest leader (not needed for this query but included for completeness).
honest_leader(gopal).

% Query: Is Shyam evil?
% ?- evil(shyam).