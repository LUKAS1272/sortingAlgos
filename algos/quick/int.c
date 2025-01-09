#include <stdio.h>
#include <stdlib.h>

// Swap function
void swap(int target[], int first, int second) {
    int memory = target[first];
    target[first] = target[second];
    target[second] = memory;
}

// Median of Three function to return the pivot index
int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    // Compare the elements at low, mid, and high
    if (arr[low] > arr[mid]) swap(arr, low, mid);
    if (arr[low] > arr[high]) swap(arr, low, high);
    if (arr[mid] > arr[high]) swap(arr, mid, high);

    // The median is at the middle index after sorting low, mid, high
    return mid;
}

// Partition function with median of three pivoting
int partition(int arr[], int lowIndex, int highIndex) {
    int pivotIndex = medianOfThree(arr, lowIndex, highIndex);
    int pivotNum = arr[pivotIndex];
    
    // Move pivot to the end of the array for partitioning
    swap(arr, pivotIndex, highIndex);
    
    int i = lowIndex - 1;
    
    // Partitioning step
    for (int j = lowIndex; j < highIndex; j++) {
        if (arr[j] <= pivotNum) {
            i++;
            swap(arr, i, j);
        }
    }
    
    // Place pivot in the correct position
    swap(arr, i + 1, highIndex);
    
    return i + 1;
}

// QuickSort function
void quickSort(int targetArr[], int lowIndex, int highIndex) {
    printf("%d %d\n", lowIndex, highIndex);
    if (lowIndex < highIndex) {
        int pIndex = partition(targetArr, lowIndex, highIndex);  // Partitioning index
        quickSort(targetArr, lowIndex, pIndex - 1);               // Sort left subarray
        quickSort(targetArr, pIndex + 1, highIndex);              // Sort right subarray
    }
}

int main() {
    int num, arrLen = 0;
    int *numArr = calloc(arrLen, sizeof(int));

    // Read input
    while (scanf("%d", &num) != EOF) {
        numArr = realloc(numArr, sizeof(int) * ++arrLen);
        numArr[arrLen - 1] = num;
    }

    // Sort the array using QuickSort
    quickSort(numArr, 0, arrLen - 1);

    // Print the sorted array
    for (int i = 0; i < arrLen; i++) {
        printf("%d\n", numArr[i]);
    }

    // Free dynamically allocated memory
    free(numArr);
    
    return 0;
}
