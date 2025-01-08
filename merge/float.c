#include <stdio.h>
#include <stdlib.h>

void merge(float targetArr[], int leftIndex, int midIndex, int rightIndex) {
    int leftSize = midIndex - leftIndex + 1;
    int rightSize = rightIndex - midIndex;

    // Temporary arrays
    float *leftTemp = malloc(leftSize * sizeof(float));
    float *rightTemp = malloc(rightSize * sizeof(float));

    // Copy data to temp subarrays
    for (int i = 0; i < leftSize; i++) {
        leftTemp[i] = targetArr[leftIndex + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightTemp[j] = targetArr[midIndex + 1 + j];
    }

    // Merge the temp arrays back into targetArr
    int i = 0, j = 0, k = leftIndex;
    while (i < leftSize && j < rightSize) {
        if (leftTemp[i] <= rightTemp[j]) {
            targetArr[k++] = leftTemp[i++];
        } else {
            targetArr[k++] = rightTemp[j++];
        }
    }

    // Copy remaining elements
    while (i < leftSize) {
        targetArr[k++] = leftTemp[i++];
    }
    while (j < rightSize) {
        targetArr[k++] = rightTemp[j++];
    }

    free(leftTemp);
    free(rightTemp);
}

void mergeSort(float targetArr[], int lowIndex, int highIndex) {
    if (lowIndex < highIndex) {
        int midIndex = (lowIndex + highIndex) / 2;
        mergeSort(targetArr, lowIndex, midIndex);
        mergeSort(targetArr, midIndex + 1, highIndex);
        merge(targetArr, lowIndex, midIndex, highIndex);
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

    // Sort using Merge Sort
    mergeSort(floatArr, 0, arrLen - 1);

    // Print sorted floats with 5 decimal places
    for (int i = 0; i < arrLen; i++) {
        printf("%.5f\n", floatArr[i]);
    }

    free(floatArr);
    return 0;
}