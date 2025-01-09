#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *targetArr[], int first, int second) {
    char *temp = targetArr[first];
    targetArr[first] = targetArr[second];
    targetArr[second] = temp;
}

void heapify(char *targetArr[], int heapSize, int rootIndex) {
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    // If left child is "greater" (lexicographically) than root
    if (leftChild < heapSize && strcmp(targetArr[leftChild], targetArr[largest]) > 0) {
        largest = leftChild;
    }

    // If right child is greater than largest so far
    if (rightChild < heapSize && strcmp(targetArr[rightChild], targetArr[largest]) > 0) {
        largest = rightChild;
    }

    // If largest is not root
    if (largest != rootIndex) {
        swap(targetArr, rootIndex, largest);
        // Recursively heapify the affected subtree
        heapify(targetArr, heapSize, largest);
    }
}

void heapSort(char *targetArr[], int arraySize) {
    // Build max heap
    for (int i = arraySize / 2 - 1; i >= 0; i--) {
        heapify(targetArr, arraySize, i);
    }

    // Extract elements from the heap one by one
    for (int i = arraySize - 1; i > 0; i--) {
        // Move current root to the end
        swap(targetArr, 0, i);
        // Call heapify on the reduced heap
        heapify(targetArr, i, 0);
    }
}

int main() {
    char buffer[256];
    int arrLen = 0;

    // Array of string pointers
    char **strArr = calloc(arrLen, sizeof(char*));

    // Read strings until EOF
    while (scanf("%255s", buffer) != EOF) {
        strArr = realloc(strArr, sizeof(char*) * (arrLen + 1));
        // Allocate and copy buffer
        strArr[arrLen] = malloc(strlen(buffer) + 1);
        strcpy(strArr[arrLen], buffer);
        arrLen++;
    }

    // Sort using Heap Sort
    heapSort(strArr, arrLen);

    // Print sorted strings
    for (int i = 0; i < arrLen; i++) {
        printf("%s\n", strArr[i]);
        free(strArr[i]); // Free each string
    }

    free(strArr); // Free array of pointers
    return 0;
}