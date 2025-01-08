#include <stdio.h>
#include <stdlib.h>

void merge(int targetArr[], int leftIndex, int middleIndex, int rightIndex) {
    int leftSize = middleIndex - leftIndex + 1;
    int rightSize = rightIndex - middleIndex;

    // Create temporary arrays
    int *leftTemp = malloc(leftSize * sizeof(int));
    int *rightTemp = malloc(rightSize * sizeof(int));

    // Copy data to temp subarrays
    for (int i = 0; i < leftSize; i++) {
        leftTemp[i] = targetArr[leftIndex + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightTemp[j] = targetArr[middleIndex + 1 + j];
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

    // Copy the remaining elements (if any)
    while (i < leftSize) {
        targetArr[k++] = leftTemp[i++];
    }
    while (j < rightSize) {
        targetArr[k++] = rightTemp[j++];
    }

    free(leftTemp);
    free(rightTemp);
}

void mergeSort(int targetArr[], int lowIndex, int highIndex) {
    if (lowIndex < highIndex) {
        int middleIndex = (lowIndex + highIndex) / 2;
        mergeSort(targetArr, lowIndex, middleIndex);
        mergeSort(targetArr, middleIndex + 1, highIndex);
        merge(targetArr, lowIndex, middleIndex, highIndex);
    }
}

int main() {
    int num, arrLen = 0;
    int *numArr = calloc(arrLen, sizeof(int));

    while (scanf("%d", &num) != EOF) { // Scans for input
        numArr = realloc(numArr, sizeof(int) * ++arrLen);
        numArr[arrLen - 1] = num;
    }

    mergeSort(numArr, 0, arrLen - 1);

    for (int i = 0; i < arrLen; i++) {
        printf("%d\n", numArr[i]); // Writes out sorted array
    }
    free(numArr); // Frees dynamic array
    return 0;
}