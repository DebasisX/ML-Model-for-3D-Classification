#include <stdio.h>
#include <stdbool.h>

// Function to check if an element exists in an array
bool exists(double arr[], int size, double element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}

int main() {
    double arr[] = {1.5, 1.5, 2.323, 5.120, 5.12, 3.7, 4.2, 2.323};
    int n = sizeof(arr) / sizeof(arr[0]);

    double uniqueArr[n];
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        if (!exists(uniqueArr, uniqueCount, arr[i])) {
            uniqueArr[uniqueCount++] = arr[i];
        }
    }

    // Print the unique elements
    printf("Unique elements: ");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%f ", uniqueArr[i]);
    }
    printf("\n");

    return 0;
}
