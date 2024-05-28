#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>
#include "../lib/ll.h"
#include "../lib/heirarchy.h"

#define _MAX_ 100000000

double accuracy(double target, double estimate)
{
    return 0;
};

int main()
{
    // Read I/O from dataset.csv ../dataset/dataset.csv
    
    // Split the data.

    // Train.

    node *list = NULL;
    double output = 0;
    int no_of_output = 0;
    printf("Enter no. of outputs F(x) can take: \n");
    // Storing the output values the inputs can take.
    scanf("%d", &no_of_output);
    printf("Enter outputs: \n");
    for(int i = 0; i < no_of_output; i++)
    {
        scanf("%lf", &output);
        insert(&list, output);
    }
    display(&list);
    // The list contains the output values that F(x) can take. 
    // Now each node of the list will have an underlying BST.
    // Enter no of inputs as X.
    htree* root[no_of_output];
    for(int i = 0; i < no_of_output; i++)
    {
        root[i] = NULL;
    }
    int x = 2; // Suppose X = 5.
    double input = 0;
    output = 0;
    printf("Enter Inputs: \n");
    while(x > 0)
    {
        scanf("%lf %lf", &input, &output);
        x--;
        for(int i = 0; i < no_of_output; i++)
        {
            if(output == element(&list, i)) {
            root[i] = tree_insert(root[i], input, output); // Will be a function to map the inputs in the Tree structure. 
            // "i" is the array position to be mapped.  
            }
        }
    } 

    // Test. 

    // Determine accuracy.

    // Display results.
    
    // Print the BST in-order
    printf("In-order traversal: \n");
    for(int i = 0; i < no_of_output; i++)
    {
        Traversal(root[i]);
    }
    for(int i = 0; i < no_of_output; i++)
    {   
        printf("Closest: %lf\n", lowest_probability(root[i], 32)); // Updated.
    }
}