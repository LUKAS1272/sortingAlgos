#include <stdio.h>
#include <stdlib.h>

void swap(int target[], int first, int second) {
    int memory = target[first];
    target[first] = target[second];
    target[second] = memory;
}

void heapify(int targetArr[], int heapSize, int rootIndex) {
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    // If left child is larger than root
    if (leftChild < heapSize && targetArr[leftChild] > targetArr[largest]) {
        largest = leftChild;
    }

    // If right child is larger than largest so far
    if (rightChild < heapSize && targetArr[rightChild] > targetArr[largest]) {
        largest = rightChild;
    }

    // If largest is not root
    if (largest != rootIndex) {
        swap(targetArr, rootIndex, largest);
        // Recursively heapify the affected subtree
        heapify(targetArr, heapSize, largest);
    }
}

void heapSort(int targetArr[], int arraySize) {
    // Build max heap
    for (int i = arraySize / 2 - 1; i >= 0; i--) {
        heapify(targetArr, arraySize, i);
    }

    // One by one extract elements from the heap
    for (int i = arraySize - 1; i > 0; i--) {
        // Move current root to the end
        swap(targetArr, 0, i);
        // Call max-heapify on the reduced heap
        heapify(targetArr, i, 0);
    }
}

int main() {
    int num, arrLen = 0;
    int *numArr = calloc(arrLen, sizeof(int));

    // Scans for input, dynamically reallocating array
    while (scanf("%d", &num) != EOF) {
        numArr = realloc(numArr, sizeof(int) * ++arrLen);
        numArr[arrLen - 1] = num;
    }

    // Sort using Heap Sort
    heapSort(numArr, arrLen);

    // Print sorted array
    for (int i = 0; i < arrLen; i++) {
        printf("%d\n", numArr[i]);
    }

    // Free dynamic array
    free(numArr);
    return 0;
}