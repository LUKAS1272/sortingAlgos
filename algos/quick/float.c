#include <stdio.h>
#include <stdlib.h>

// Swap function
void swap(float target[], int first, int second) {
    float memory = target[first];
    target[first] = target[second];
    target[second] = memory;
}

// Function to find the median of three elements (low, mid, high)
int medianOfThree(float arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    // Compare and order the three elements: low, mid, high
    if (arr[low] > arr[mid]) swap(arr, low, mid);
    if (arr[low] > arr[high]) swap(arr, low, high);
    if (arr[mid] > arr[high]) swap(arr, mid, high);

    // Return the index of the median element
    return mid;
}

// Partition function using median of three pivoting
int partition(float arr[], int lowIndex, int highIndex) {
    // Choose the pivot using the median of three
    int pivotIndex = medianOfThree(arr, lowIndex, highIndex);
    float pivotNum = arr[pivotIndex];

    // Move pivot to the end of the array for partitioning
    swap(arr, pivotIndex, highIndex);

    int i = lowIndex - 1;

    // Partition the array based on the pivot
    for (int j = lowIndex; j < highIndex; j++) {
        if (arr[j] <= pivotNum) {
            i++;
            swap(arr, i, j);
        }
    }

    // Move the pivot to its correct position
    swap(arr, i + 1, highIndex);

    return i + 1;
}

// QuickSort function
void quickSort(float targetArr[], int lowIndex, int highIndex) {
    if (lowIndex < highIndex) {
        int pIndex = partition(targetArr, lowIndex, highIndex);
        quickSort(targetArr, lowIndex, pIndex - 1); // Sort left subarray
        quickSort(targetArr, pIndex + 1, highIndex); // Sort right subarray
    }
}

int main() {
    float num;
    int arrLen = 0;
    float *numArr = calloc(arrLen, sizeof(float));

    // Read input from stdin
    while (scanf("%f", &num) != EOF) {
        numArr = realloc(numArr, sizeof(float) * ++arrLen);
        numArr[arrLen - 1] = num;
    }

    // Sort the array using QuickSort
    quickSort(numArr, 0, arrLen - 1);

    // Print the sorted array with 5 decimal places
    for (int i = 0; i < arrLen; i++) {
        printf("%.5f\n", numArr[i]);
    }

    // Free dynamically allocated memory
    free(numArr);

    return 0;
}
