#include <stdio.h>
#include <stdlib.h>

void swap(int target[], int first, int second) {
    int memory = target[first];

    target[first] = target[second];
    target[second] = memory;
}

int partition(int arr[], int lowIndex, int highIndex) {
    int pivotNum = arr[highIndex];
    int i = lowIndex - 1;
    
    for (int j = lowIndex; j < highIndex; j++) {
        if (arr[j] <= pivotNum) {
            swap(arr, ++i, j);
        }
    }
    swap(arr, ++i, highIndex);
    return i;
}

void quickSort(int targetArr[], int lowIndex, int highIndex) {
    if (lowIndex < highIndex) {
        int pIndex = partition(targetArr, lowIndex, highIndex);
        quickSort(targetArr, lowIndex, pIndex - 1);
        quickSort(targetArr, pIndex + 1, highIndex);
    }
}

int main() {
    int num, arrLen = 0;
    int *numArr = calloc(arrLen, sizeof(int));

    while (scanf("%d", &num) != EOF) { // Scans for input
        numArr = realloc(numArr, sizeof(int) * ++arrLen);
        numArr[arrLen - 1] = num;
    }

    quickSort(numArr, 0, arrLen - 1);

    for (int i = 0; i < arrLen; i++) { printf("%d\n", numArr[i]); } // Writes out sorted array
    free(numArr); // Frees dynamic array
    return 0;
}