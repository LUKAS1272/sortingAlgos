#include <stdio.h>
#include <stdlib.h>

void swapFloat(float targetArr[], int first, int second) {
    float temp = targetArr[first];
    targetArr[first] = targetArr[second];
    targetArr[second] = temp;
}

void heapify(float targetArr[], int heapSize, int rootIndex) {
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    // If left child is larger than root
    if (leftChild < heapSize && targetArr[leftChild] > targetArr[largest]) {
        largest = leftChild;
    }

    // If right child is larger than the current largest
    if (rightChild < heapSize && targetArr[rightChild] > targetArr[largest]) {
        largest = rightChild;
    }

    // If largest is not root
    if (largest != rootIndex) {
        swapFloat(targetArr, rootIndex, largest);
        heapify(targetArr, heapSize, largest);
    }
}

void heapSort(float targetArr[], int arraySize) {
    // Build max heap
    for (int i = arraySize / 2 - 1; i >= 0; i--) {
        heapify(targetArr, arraySize, i);
    }

    // Extract elements from the heap
    for (int i = arraySize - 1; i > 0; i--) {
        // Move current root to end
        swapFloat(targetArr, 0, i);
        // Call heapify on the reduced heap
        heapify(targetArr, i, 0);
    }
}

int main() {
    float num;
    int arrLen = 0;

    // Dynamic array for floats
    float *floatArr = calloc(arrLen, sizeof(float));

    // Read floats until EOF
    while (scanf("%f", &num) != EOF) {
        floatArr = realloc(floatArr, sizeof(float) * (arrLen + 1));
        floatArr[arrLen++] = num;
    }

    // Sort using Heap Sort
    heapSort(floatArr, arrLen);

    // Print sorted floats with 5 decimal places
    for (int i = 0; i < arrLen; i++) {
        printf("%.5f\n", floatArr[i]);
    }

    free(floatArr);
    return 0;
}