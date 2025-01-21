#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to get the maximum number in the array (for Radix Sort)
uint32_t getMaxUInt32(uint32_t numArr[], int arrLen) {
    uint32_t max = 0;
    for (int i = 0; i < arrLen; i++) {
        if (numArr[i] > max) {
            max = numArr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on the digit represented by exp
void countingSortUInt32(uint32_t numArr[], int arrLen, uint32_t exp) {
    uint32_t *output = malloc(arrLen * sizeof(uint32_t));
    if (!output) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int count[10];
    memset(count, 0, sizeof(count));

    // Store count of occurrences in count[]
    for (int i = 0; i < arrLen; i++) {
        int digit = (numArr[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    // Iterate from end to maintain stability
    for (int i = arrLen - 1; i >= 0; i--) {
        int digit = (numArr[i] / exp) % 10;
        output[count[digit] - 1] = numArr[i];
        count[digit]--;
    }

    // Copy the output array to numArr[], so that numArr[] now contains sorted numbers
    for (int i = 0; i < arrLen; i++) {
        numArr[i] = output[i];
    }

    free(output);
}

// Radix Sort function for uint32_t
void radixSortUInt32(uint32_t numArr[], int arrLen) {
    // Find the maximum number to know the number of digits
    uint32_t max = getMaxUInt32(numArr, arrLen);

    // Do counting sort for every digit. Note that instead of passing digit number,
    // exp is passed. exp is 10^i where i is current digit number
    for (uint32_t exp = 1; max / exp > 0; exp *= 10) {
        countingSortUInt32(numArr, arrLen, exp);
    }
}

// Function to reverse an array in place
void reverseArray(uint32_t numArr[], int arrLen) {
    uint32_t temp;
    for (int i = 0; i < arrLen / 2; i++) {
        temp = numArr[i];
        numArr[i] = numArr[arrLen - 1 - i];
        numArr[arrLen - 1 - i] = temp;
    }
}

// Function to convert float to sortable uint32_t
uint32_t floatToSortableUInt32(float f) {
    uint32_t bits;
    memcpy(&bits, &f, sizeof(float));
    if (bits & 0x80000000) { // If negative
        bits = ~bits;
    } else { // If positive
        bits ^= 0x80000000;
    }
    return bits;
}

// Function to convert sortable uint32_t back to float
float sortableUInt32ToFloat(uint32_t bits) {
    if (bits & 0x80000000) { // If originally positive
        bits ^= 0x80000000;
    } else { // If originally negative
        bits = ~bits;
    }
    float f;
    memcpy(&f, &bits, sizeof(float));
    return f;
}

int main() {
    float num = 0.0f;
    int arrLen = 0;
    float *numArr = NULL;

    // Read floats from standard input until EOF
    while (scanf("%f", &num) != EOF) {
        float *temp = realloc(numArr, sizeof(float) * (arrLen + 1));
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
        if (numArr[i] < 0.0f) {
            negCount++;
        } else {
            posCount++;
        }
    }

    // Allocate memory for negative and positive arrays
    float *negArr = malloc(sizeof(float) * negCount);
    float *posArr = malloc(sizeof(float) * posCount);

    if ((negCount > 0 && !negArr) || (posCount > 0 && !posArr)) {
        fprintf(stderr, "Memory allocation failed\n");
        free(numArr);
        free(negArr);
        free(posArr);
        return EXIT_FAILURE;
    }

    // Populate negative and positive arrays
    int ni = 0, pi = 0;
    for (int i = 0; i < arrLen; i++) {
        if (numArr[i] < 0.0f) {
            negArr[ni++] = numArr[i];
        } else {
            posArr[pi++] = numArr[i];
        }
    }

    // Transform negative floats to sortable uint32_t
    uint32_t *negTransformed = NULL;
    if (negCount > 0) {
        negTransformed = malloc(sizeof(uint32_t) * negCount);
        if (!negTransformed) {
            fprintf(stderr, "Memory allocation failed\n");
            free(numArr);
            free(negArr);
            free(posArr);
            return EXIT_FAILURE;
        }
        for (int i = 0; i < negCount; i++) {
            negTransformed[i] = floatToSortableUInt32(negArr[i]);
        }

        // Sort negative numbers using radix sort
        radixSortUInt32(negTransformed, negCount);

        // Reverse the sorted array to get correct order for negatives
        reverseArray(negTransformed, negCount);
    }

    // Transform positive floats to sortable uint32_t
    uint32_t *posTransformed = NULL;
    if (posCount > 0) {
        posTransformed = malloc(sizeof(uint32_t) * posCount);
        if (!posTransformed) {
            fprintf(stderr, "Memory allocation failed\n");
            free(numArr);
            free(negArr);
            free(posArr);
            free(negTransformed);
            return EXIT_FAILURE;
        }
        for (int i = 0; i < posCount; i++) {
            posTransformed[i] = floatToSortableUInt32(posArr[i]);
        }

        // Sort positive numbers using radix sort
        radixSortUInt32(posTransformed, posCount);
    }

    // Allocate memory for the sorted array
    float *sortedArr = malloc(sizeof(float) * arrLen);
    if (!sortedArr && arrLen > 0) {
        fprintf(stderr, "Memory allocation failed\n");
        free(numArr);
        free(negArr);
        free(posArr);
        free(negTransformed);
        free(posTransformed);
        return EXIT_FAILURE;
    }

    // Populate the sorted array with sorted negative numbers
    for (int i = 0; i < negCount; i++) {
        sortedArr[i] = sortableUInt32ToFloat(negTransformed[i]);
    }

    // Populate the sorted array with sorted positive numbers
    for (int i = 0; i < posCount; i++) {
        sortedArr[negCount + i] = sortableUInt32ToFloat(posTransformed[i]);
    }

    // Print the sorted array
    for (int i = 0; i < arrLen; i++) {
        printf("%f\n", sortedArr[i]);
    }

    // Free allocated memory
    free(numArr);
    free(negArr);
    free(posArr);
    free(negTransformed);
    free(posTransformed);
    free(sortedArr);

    return 0;
}