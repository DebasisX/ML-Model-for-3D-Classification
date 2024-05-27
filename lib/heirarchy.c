#define _MAX_ 100000000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Defining the BST node structure
typedef struct htree {
    int input;
    int output;
    struct htree *lowest; // Treat as left branch.
    struct htree *highest; // Treat as right branch.
} htree;

// written code to insert nodes, 
// search for an input in range lowest->input and highest->input, 
// (also handle cases where in the initial stages the tree hasn't grown much) 
// if found return the output.
int prob = _MAX_;
int node_value = _MAX_;
void reset() // Call this after a probability test. to re-initialize the global values.
{
    prob = _MAX_;
    node_value = _MAX_;
}
int lowest_probability(struct htree* root, int search)
{
    // Input to be matched with every node whichever node has the lowest difference gets to be the output. 
    if (root != NULL) {
        lowest_probability(root->lowest, search);
        if (abs(search - root->input) <= prob) 
        {
            prob = abs(search - root->input);
            node_value = root->input;
        }
        lowest_probability(root->highest, search);
    }
    
    return node_value;
}

// These are only functions we need for now. Scaling can be done later.

struct htree* createNode(int in, int out) {
    struct htree* newNode = (struct htree*)malloc(sizeof(struct htree));
    newNode->input = in;
    newNode->output = out;
    newNode->lowest = NULL;
    newNode->highest = NULL;
    return newNode;
}

// Function to insert a value into the htree
struct htree* insert(struct htree* root, int in, int out) {
    if (root == NULL) {
        return createNode(in, out);
    }

    if (in < root->input) {
        root->lowest = insert(root->lowest, in, out);
    } else if (in > root->input) {
        root->highest = insert(root->highest, in, out);
    }
    return root;
}

// Function to print the BST in-order
void Traversal(struct htree* root) {
    if (root != NULL) {
        Traversal(root->lowest);
        printf("%d -> %d\n", root->input, root->output);
        Traversal(root->highest);
    }
}

int main() {
struct htree* root = NULL;

// Example: Insert values into the BST
root = insert(root, 50, 43);
root = insert(root, 30, 34);
root = insert(root, 70, 67);
root = insert(root, 20, 22);
root = insert(root, 40, 43);

// Print the BST in-order
printf("In-order traversal: \n");
Traversal(root);
printf("Closest: %d\n", lowest_probability(root, 32));
return 0;
}
