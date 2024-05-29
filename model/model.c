#include <stdio.h>
#include <pthread.h> // for multi-thread support to improve runtime. Not implemeted yet.
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include "../lib/ll.h"
#include "../lib/heirarchy.h"

#define MAX_LINE_LENGTH 100
#define _MAX_ 100000000



double accuracy(double total, double no_of_correct)
{
    return ((total - no_of_correct) / total) * 100;
};
// Function to check if an element exists in an array
bool exists(double arr[], int size, double element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}
int main()
{
    // Read I/O from dataset.csv ../dataset/dataset.csv
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *value, *category;

    // Open the CSV file for reading
    fp = fopen("../dataset/dataset.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Skip the header row (assuming there's one)
    fgets(line, MAX_LINE_LENGTH, fp);

    // Initialize size for arrays (can be dynamically allocated later)
    int size = 0;
    double *inputs = NULL;
    double *outputs = NULL;

    // Read each line
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Remove trailing newline (if present)
        line[strcspn(line, "\n")] = 0;

        // Separate value and category using strtok (modify based on delimiter)
        value = strtok(line, ",");
        category = strtok(NULL, ",");

        // Convert strings to integers (modify if data types are different)
        double input_value = atof(value);
        double output_category = atof(category);

        // Reallocate arrays if needed (dynamic allocation)
        size++;
        inputs = realloc(inputs, size * sizeof(double));
        outputs = realloc(outputs, size * sizeof(double));

        // Store values in arrays
        inputs[size - 1] = input_value;
        outputs[size - 1] = output_category;
    }

    // Close the file
    fclose(fp);

    // Display the data
    printf("Loaded data.\n");
    
    // Train. 
    node *list = NULL;
    double output = 0;
    
    double uniqueArr[size];
    int uniqueCount = 0;

    for (int i = 0; i < size; i++) {

        if (!exists(uniqueArr, uniqueCount, outputs[i])) {
            uniqueArr[uniqueCount++] = outputs[i];
        }
    }

    // Print the unique elements
    printf("Output elements: ");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%f ", uniqueArr[i]);
    }
    printf("\n");


    int no_of_output = uniqueCount;
    for(int i = 0; i < no_of_output; i++)
    {
        output = uniqueArr[i];
        insert(&list, output);
    }
    display(&list);

    // The list now contains the output values that F(x) can take. 

    // Now each node of the list will have an underlying BST.
    // Enter no of inputs as X.
    htree* root[no_of_output];
    for(int i = 0; i < size; i++)
    {
        root[i] = NULL;
    }
    int x = size; // Suppose X = 5.
    double input = 0;
    output = 0;
    printf("Enter Inputs: \n");
    for(int i = 0; i < size; i++) {
        input = inputs[i];
        output = outputs[i];
        for(int i = 0; i < no_of_output; i++)
        {
            if(output == element(&list, i)) {
            root[i] = tree_insert(root[i], input, output); // Will be a function to map the inputs in the Tree structure. 
            // "i" is the array position to be mapped.  
            }
        }
    }

    // Test. 
    printf("In-order traversal: \n");
    for(int i = 0; i < no_of_output; i++)
    {
        Traversal(root[i]);
    }
    printf("Enter an Input to TEST: ");
    double test_input = 0;
    scanf("%lf", &test_input);
    double closest = _MAX_;
    for(int i = 0; i < no_of_output; i++)
    {  
        double temp = lowest_probability(root[i], test_input);
        if(closest >= temp) 
        {
            closest = temp;
        }
    }
    printf("Closest: %lf\n", closest); // Updated.
    
    // Determine accuracy.
    
    
    // For testing accuracy for a batch use accuracy().
    // Display results.
    
    // Free the allocated memory 
    free(inputs);
    free(outputs);
}