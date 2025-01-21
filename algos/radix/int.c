#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the maximum absolute value in the array
int getMax(int numArr[], int arrLen) {
    int max = 0;
    for (int i = 0; i < arrLen; i++) {
        if (abs(numArr[i]) > max) {
            max = abs(numArr[i]);
        }
    }
    return max;
}

// Function to perform counting sort based on the digit represented by exp
void countingSort(int numArr[], int arrLen, int exp, int isNegative) {
    int *output = malloc(arrLen * sizeof(int));
    if (!output) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int count[10];
    memset(count, 0, sizeof(count));

    // Store count of occurrences in count[]
    for (int i = 0; i < arrLen; i++) {
        int digit = (abs(numArr[i]) / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    // Iterate from end to maintain stability
    for (int i = arrLen - 1; i >= 0; i--) {
        int digit = (abs(numArr[i]) / exp) % 10;
        output[count[digit] - 1] = numArr[i];
        count[digit]--;
    }

    // Copy the output array to numArr[], so that numArr[] now contains sorted numbers
    for (int i = 0; i < arrLen; i++) {
        numArr[i] = output[i];
    }

    free(output);
}

// Radix Sort function
void radixSort(int numArr[], int arrLen) {
    // Find the maximum number to know the number of digits
    int max = getMax(numArr, arrLen);

    // Do counting sort for every digit. Note that instead of passing digit number,
    // exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(numArr, arrLen, exp, 0);
    }
}

// Function to reverse an array in place
void reverseArray(int numArr[], int arrLen) {
    int temp;
    for (int i = 0; i < arrLen / 2; i++) {
        temp = numArr[i];
        numArr[i] = numArr[arrLen - 1 - i];
        numArr[arrLen - 1 - i] = temp;
    }
}

int main() {
    int num = 0, arrLen = 0;
    int *numArr = NULL;

    // Read integers from standard input until EOF
    while (scanf("%d", &num) != EOF) {
        int *temp = realloc(numArr, sizeof(int) * (arrLen + 1));
        if (!temp) {
            fprintf(stderr, "Memory allocation failed\n");
            free(numArr);
            return EXIT_FAILURE;
        }
        numArr = temp;
        numArr[arrLen++] = num;
    }

    // Separate negative and non-negative numbers
    int negCount = 0, posCount = 0;
    for (int i = 0; i < arrLen; i++) {
        if (numArr[i] < 0) {
            negCount++;
        } else {
            posCount++;
        }
    }

    int *negArr = malloc(sizeof(int) * negCount);
    int *posArr = malloc(sizeof(int) * posCount);
    if ((!negArr && negCount > 0) || (!posArr && posCount > 0)) {
        free(numArr);
        free(negArr);
        free(posArr);
        return EXIT_FAILURE;
    }

    int ni = 0, pi = 0;
    for (int i = 0; i < arrLen; i++) {
        if (numArr[i] < 0) {
            negArr[ni++] = -numArr[i]; // Make negatives positive for sorting
        } else {
            posArr[pi++] = numArr[i];
        }
    }

    // Sort negative numbers using radix sort
    if (negCount > 0) {
        radixSort(negArr, negCount);
        reverseArray(negArr, negCount); // Reverse to get correct order for negatives
        for (int i = 0; i < negCount; i++) {
            negArr[i] = -negArr[i]; // Restore negative values
        }
    }

    // Sort non-negative numbers using radix sort
    if (posCount > 0) {
        radixSort(posArr, posCount);
    }

    // Combine negative and non-negative arrays
    // Negative numbers come first
    int *sortedArr = malloc(sizeof(int) * arrLen);
    if (!sortedArr && arrLen > 0) {
        fprintf(stderr, "Memory allocation failed\n");
        free(numArr);
        free(negArr);
        free(posArr);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < negCount; i++) {
        sortedArr[i] = negArr[i];
    }
    for (int i = 0; i < posCount; i++) {
        sortedArr[negCount + i] = posArr[i];
    }

    // Print the sorted array
    for (int i = 0; i < arrLen; i++) {
        printf("%d\n", sortedArr[i]);
    }

    // Free allocated memory
    free(numArr);
    free(negArr);
    free(posArr);
    free(sortedArr);

    return 0;
}
