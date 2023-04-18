# nfasimulator
-NFA(non-deterministic finite automaton) Simulator(C++): program that determines whether an NFA given by the user in a specified format will accept or reject a string given by the user. Not compatible with epsilon NFAs. Number of states may be no more than 64.
Specified example format is as follows:

Number of states: 8

Alphabet size: 2

Accepting states: 0 1 3 4 7


{} {2,5} {}


{} {2} {}


{} {} {3}


{} {2} {}


{} {5} {}


{} {} {6}


{} {7} {}


{} {5} {}

The brackets represent the rows and columns of possible transitions. In this example, the alphabet size is 2 (a,b). So their is three columns for epilson, a and b. Epilson will always contain no transitions as the program does not work for epilson nfas. The rows of brackets represent the states in ascending order. So in the first line of brackets, in state 0 on input a, we have transitions to 2 or 5. Empty brackets represent no transitions. Input strings from the user may only contain letters from the alphabet and the alphabet size is directly mapped to the order of letters in the latin alphabet. Alphabet size = 3 = a, b, c; 4 = a, b, c, d and so on. Once input is entered, output will be either accept or reject.
