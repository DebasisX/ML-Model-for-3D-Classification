
#include <stdio.h>

// Function that takes an integer as an argument
void processElement(int element) {
    printf("The element is: %d\n", element);
}

int main() {
    int arr[3] = {10, 20, 30};

    // Pass arr[2] to the function
    processElement(arr[2]);

    return 0;
}
