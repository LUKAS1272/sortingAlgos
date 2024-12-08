#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *numArr[], int *arrLen) {
    int indexesDone = 0;

    while (1) { // Sorts the array
        int smallestNum = (*numArr)[indexesDone];
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

void arrayLoad(int *numArr[], int *arrLen) {
    int num = 0, indexesDone = 0;
    *arrLen = 0;
    *numArr = realloc(NULL, sizeof(int));

    while (scanf("%d", &num) != EOF) { // Scans for input
        (*numArr) = realloc((*numArr), sizeof(int) * (++(*arrLen)));
        (*numArr)[(*arrLen) - 1] = num;
    }
}

int main() {
    int *numArr;
    int arrLen = 0;

    arrayLoad(&numArr, &arrLen);
    selectionSort(&numArr, &arrLen);
    for (int i = 0; i < arrLen; i++) { printf("%d\n", numArr[i]); } // Writes out sorted array

    free(numArr); // Frees dynamic array
    return 0;
}