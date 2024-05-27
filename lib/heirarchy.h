#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int id;
    int input;
    int output;
    tree *lowest; // Treat as left branch.
    tree *highest; // Treat as right branch.
} tree;

// write code to insert nodes, 
// search for an input in range lowest->input and highest->input, 
// (also handle cases where in the initial stages the tree hasn't grown much). 
// if found return the output.