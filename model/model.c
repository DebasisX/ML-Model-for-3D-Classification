#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>
#include "../lib/ll.h"
// #include "../lib/heirarchy.h"

#define _MAX_ 1000000000

int main()
{
    // Read I/O from dataset.csv ../dataset/dataset.csv
    
    // Split the data.

    // Train.
    node *list = NULL;
    int output = 0;
    int no_of_input = 0;
    printf("Enter no. of outputs F(x) can take: \n");
    // Storing the output values the inputs can take.
    scanf("%d", &no_of_input);
    printf("Enter outputs: \n");
    for(int i = 0; i < no_of_input; i++)
    {
        scanf("%d", &output);
        insert(&list, output);
    }
    display(&list);

    // The list contains the output values that F(x) can take. 
    // Now each node of the list will have an underlying BST.
    // Enter no of inputs as X.
    
    int x = 20; // Suppose X = 20.
    printf("Enter Inputs: \n");
    while(x != 0)
    {
        scanf("%d", &input);

        insert_tree(); // Will be a function to map the inputs in the Tree structure.
        x--;
    } 


    // Test. 

    // Determine accuracy.

    // Display results.
    
}