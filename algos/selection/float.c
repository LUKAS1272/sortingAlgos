#include <stdio.h>
#include <stdlib.h>

void selectionSort(float *numArr[], int *arrLen) {
    int indexesDone = 0;

    while (1) { // Sorts the array
        float smallestNum = (*numArr)[indexesDone];
        int smallestNumIndex = indexesDone;
        int isMistake = 0;

        for (int index = indexesDone + 1; index < (*arrLen); index++) {
            if ((*numArr)[index] < smallestNum) {
                smallestNum = (*numArr)[index];
                smallestNumIndex = index;
                isMistake = 1;
            }
        }

        if (isMistake == 1) {
            (*numArr)[smallestNumIndex] = (*numArr)[indexesDone];
            (*numArr)[indexesDone] = smallestNum;
        }

        indexesDone++;
        if (indexesDone >= (*arrLen) - 1) {
            break;
        }
    }
}

void arrayLoad(float *numArr[], int *arrLen) {
    float num = 0.0f;
    *arrLen = 0;
    *numArr = realloc(NULL, sizeof(float));

    while (scanf("%f", &num) != EOF) { // Scans for input
        (*numArr) = realloc((*numArr), sizeof(float) * (++(*arrLen)));
        (*numArr)[(*arrLen) - 1] = num;
    }
}

int main() {
    float *numArr;
    int arrLen = 0;

    arrayLoad(&numArr, &arrLen);
    selectionSort(&numArr, &arrLen);
    for (int i = 0; i < arrLen; i++) {
        printf("%.5f\n", numArr[i]); // Print floats with 5 precision points
    }

    free(numArr); // Frees dynamic array
    return 0;
}
