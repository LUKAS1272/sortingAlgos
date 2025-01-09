#include <stdio.h>
#include <stdlib.h>

void itemsMove(int fromIndex, int toIndex, int target[]) {
    for (int i = fromIndex; i > toIndex; i--) {
        int numMemory = target[i];
        target[i] = target[i - 1];
        target[i - 1] = numMemory;
    }
}

int main() {
    int num = 0, arrLen = 0;
    int *numArr = calloc(arrLen, sizeof(int));

    while (scanf("%d", &num) != EOF) { // Scans for input
        numArr = realloc(numArr, sizeof(int) * ++arrLen);
        numArr[arrLen - 1] = num;
    }

    int index = 1;
    while (arrLen > 0) {
        // printf("%d\n", index);
        if (index == arrLen) {
            break;
        } else if (numArr[index - 1] <= numArr[index]) {
            index++;
        } else { // Zjisti s cim swapnout
            int subIndex = index - 1;
            while (1) {
                if (numArr[subIndex] < numArr[index]) {
                    // printf("   -\n");
                    itemsMove(index, subIndex + 1, numArr);
                    index++;

                    break;
                } else if (subIndex == 0) {
                    itemsMove(index, 0, numArr);
                    index++;

                    break;
                } else {
                    subIndex--;
                }
            }
        }
    }

    printf("----------\n");

    for (int i = 0; i < arrLen; i++) { printf("%d\n", numArr[i]); } // Writes out sorted array
    free(numArr); // Frees dynamic array
    return 0;
}