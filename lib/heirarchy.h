#define _MAX_ 100000000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Defining the BST node structure
typedef struct htree {
    double input;
    double output;
    struct htree *lowest; // Treat as left branch.
    struct htree *highest; // Treat as right branch.
} htree;

// written code to insert nodes, 
// search for an input in range lowest->input and highest->input, 
// (also handle cases where in the initial stages the tree hasn't grown much) 
// if found return the output.
double prob = _MAX_;
double node_value = _MAX_;
double node_output = _MAX_;
void reset() // Call this after a probability test. to re-initialize the global values.
{
    prob = _MAX_;
    node_value = _MAX_;
    node_output = _MAX_;
}
double lowest_probability(struct htree* root, double search)
{
    // Input to be matched with every node whichever node has the lowest difference gets to be the output. 
    if (root != NULL) {
        lowest_probability(root->lowest, search);
        if (fabs(search - root->input) <= prob) 
        {
            prob = fabs(search - root->input);
            node_value = root->input;
            node_output = root->output;
        }
        lowest_probability(root->highest, search);
    }
    return node_output;
}

// These are only functions we need for now. Scaling can be done later.

struct htree* createNode(double in, double out) {
    struct htree* newNode = (struct htree*)malloc(sizeof(struct htree));
    newNode->input = in;
    newNode->output = out;
    newNode->lowest = NULL;
    newNode->highest = NULL;
    return newNode;
}

// Function to insert a value into the htree
struct htree* tree_insert(struct htree* root, double in, double out) {
    if (root == NULL) {
        return createNode(in, out);
    }

    if (in < root->input) {
        root->lowest = tree_insert(root->lowest, in, out);
    } else if (in > root->input) {
        root->highest = tree_insert(root->highest, in, out);
    }
    return root;
}

// Function to print the BST in-order
void Traversal(struct htree* root) {
    if (root != NULL) {
        Traversal(root->lowest);
        printf("%lf -> %lf\n", root->input, root->output);
        Traversal(root->highest);
    }
}

