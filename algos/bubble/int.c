#include <stdio.h>
#include <stdlib.h>

int assignPair(int numArr[], int currentIndex) {
    int numPair[2] = { numArr[currentIndex], numArr[currentIndex + 1] }; // Sets compared pair values

    if (numPair[0] > numPair[1]) { // Compares pair values
        numArr[currentIndex] = numPair[1]; // Swaps pair values
        numArr[currentIndex + 1] = numPair[0]; // Swaps pair values

        return 1; // Return one mistake
    }
    
    return 0; // Return zero mistakes
}

int main() {
    int num = 0, arrLen = 0, indexesDone = 0;
    int *numArr = calloc(arrLen, sizeof(int));

    while (scanf("%d", &num) != EOF) { // Scans for input
        numArr = realloc(numArr, sizeof(int) * ++arrLen);
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


    for (int i = 0; i < arrLen; i++) { printf("%d\n", numArr[i]); } // Writes out sorted array
    free(numArr); // Frees dynamic array
    return 0;
}