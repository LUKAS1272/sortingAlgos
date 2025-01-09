#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *target[], int first, int second) {
    char *memory = target[first];
    target[first] = target[second];
    target[second] = memory;
}

// Median of Three: choose pivot as median of first, middle, and last elements
int medianOfThree(char *arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    // Sort the three elements: arr[low], arr[mid], arr[high]
    if (strcmp(arr[low], arr[mid]) > 0) swap(arr, low, mid);
    if (strcmp(arr[low], arr[high]) > 0) swap(arr, low, high);
    if (strcmp(arr[mid], arr[high]) > 0) swap(arr, mid, high);

    // Return the index of the median
    return mid;
}

int partition(char *arr[], int lowIndex, int highIndex) {
    // Get the median of three as the pivot
    int pivotIndex = medianOfThree(arr, lowIndex, highIndex);
    char *pivotStr = arr[pivotIndex];
    
    // Move pivot to the end of the array
    swap(arr, pivotIndex, highIndex);
    
    int i = lowIndex - 1;
    
    // Partition the array around the pivot
    for (int j = lowIndex; j < highIndex; j++) {
        if (strcmp(arr[j], pivotStr) <= 0) {
            swap(arr, ++i, j);
        }
    }
    swap(arr, ++i, highIndex);  // Move pivot to its correct position
    return i;
}

void quickSort(char *targetArr[], int lowIndex, int highIndex) {
    if (lowIndex < highIndex) {
        int pIndex = partition(targetArr, lowIndex, highIndex);
        quickSort(targetArr, lowIndex, pIndex - 1);  // Sort left subarray
        quickSort(targetArr, pIndex + 1, highIndex);  // Sort right subarray
    }
}

int main() {
    char word[100];
    int arrLen = 0;
    char **wordsArr = NULL;

    // Read words until EOF
    while (scanf("%99s", word) != EOF) {
        wordsArr = realloc(wordsArr, sizeof(char*) * ++arrLen);  // Resize array
        wordsArr[arrLen - 1] = strdup(word);  // Duplicate word into array
    }

    // Sort the words array using QuickSort
    quickSort(wordsArr, 0, arrLen - 1);

    // Print the sorted words
    for (int i = 0; i < arrLen; i++) {
        printf("%s\n", wordsArr[i]);
        free(wordsArr[i]);  // Free each word after printing
    }

    free(wordsArr);  // Free the array of pointers
    return 0;
}
