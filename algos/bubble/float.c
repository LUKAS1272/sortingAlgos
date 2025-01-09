#include <stdio.h>
#include <stdlib.h>

int assignPair(float numArr[], int currentIndex) {
    if (numArr[currentIndex] > numArr[currentIndex + 1]) { // Compares pair values
        float temp = numArr[currentIndex];
        numArr[currentIndex] = numArr[currentIndex + 1];
        numArr[currentIndex + 1] = temp;
        return 1; // Return one mistake
    }
    return 0; // Return zero mistakes
}

int main() {
    float num = 0.0f;
    int arrLen = 0, indexesDone = 0;
    float *numArr = calloc(arrLen, sizeof(float));

    while (scanf("%f", &num) != EOF) { // Scans for input
        numArr = realloc(numArr, sizeof(float) * ++arrLen);
        numArr[arrLen - 1] = num;
    }

    while (1) { // Sorts the array
        int mistakes = 0;
        for (int index = 0; index < arrLen - indexesDone - 1; index++) {
            mistakes += assignPair(numArr, index); // Assigns pair and swaps numbers, if needed
        }
        if (mistakes > 0) {
            indexesDone++; // If there were mistakes, the sorted array shortens
        } else {
            break; // If there were no mistakes, the sort ends
        }
    }

    for (int i = 0; i < arrLen; i++) { printf("%.5f\n", numArr[i]); } // Writes out sorted array
    free(numArr); // Frees dynamic array
    return 0;
}
