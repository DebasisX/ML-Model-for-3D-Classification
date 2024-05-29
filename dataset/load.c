#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100  // Adjust this based on your expected line length

int main() {
  FILE *fp;
  char line[MAX_LINE_LENGTH];
  char *value, *category;

  // Open the CSV file for reading
  fp = fopen("dataset.csv", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Skip the header row (assuming there's one)
  fgets(line, MAX_LINE_LENGTH, fp);

  // Initialize size for arrays (can be dynamically allocated later)
  int size = 0;
  int *inputs = NULL;
  int *outputs = NULL;

  // Read each line
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    // Remove trailing newline (if present)
    line[strcspn(line, "\n")] = 0;

    // Separate value and category using strtok (modify based on delimiter)
    value = strtok(line, ",");
    category = strtok(NULL, ",");

    // Convert strings to integers (modify if data types are different)
    int input_value = atoi(value);
    int output_category = atoi(category);

    // Reallocate arrays if needed (dynamic allocation)
    size++;
    inputs = realloc(inputs, size * sizeof(int));
    outputs = realloc(outputs, size * sizeof(int));

    // Store values in arrays
    inputs[size - 1] = input_value;
    outputs[size - 1] = output_category;
  }

  // Close the file
  fclose(fp);

  // Display the data
  printf("Loaded data:\n");
  for (int i = 0; i < size; i++) {
    printf("Value: %d, Category: %d\n", inputs[i], outputs[i]);
  }

  // Free the allocated memory (if dynamically allocated)
  free(inputs);
  free(outputs);

  return 0;
}
