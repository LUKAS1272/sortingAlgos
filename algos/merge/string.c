#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char *targetArr[], int leftIndex, int midIndex, int rightIndex) {
    int leftSize = midIndex - leftIndex + 1;
    int rightSize = rightIndex - midIndex;

    // Temporary arrays
    char **leftTemp = malloc(leftSize * sizeof(char*));
    char **rightTemp = malloc(rightSize * sizeof(char*));

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
        // Compare strings lexicographically
        if (strcmp(leftTemp[i], rightTemp[j]) <= 0) {
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

void mergeSort(char *targetArr[], int lowIndex, int highIndex) {
    if (lowIndex < highIndex) {
        int midIndex = (lowIndex + highIndex) / 2;
        mergeSort(targetArr, lowIndex, midIndex);
        mergeSort(targetArr, midIndex + 1, highIndex);
        merge(targetArr, lowIndex, midIndex, highIndex);
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
        // Copy from buffer into newly allocated string
        strArr[arrLen] = malloc(strlen(buffer) + 1);
        strcpy(strArr[arrLen], buffer);
        arrLen++;
    }

    // Sort using Merge Sort
    mergeSort(strArr, 0, arrLen - 1);

    // Print sorted strings
    for (int i = 0; i < arrLen; i++) {
        printf("%s\n", strArr[i]);
        free(strArr[i]); // Free each string
    }

    free(strArr); // Free the array of pointers
    return 0;
}