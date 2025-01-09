#include <stdio.h>
#include <stdlib.h>

void itemsMove(int fromIndex, int toIndex, float **target) {
    for (int i = fromIndex; i > toIndex; i--) {
        float temp = (*target)[i]; // Dereference target to get the value
        (*target)[i] = (*target)[i - 1];
        (*target)[i - 1] = temp;
    }
}

int main() {
    float num = 0;
    int arrLen = 0;
    float *numArr = calloc(arrLen, sizeof(float)); // Array of floats

    // Read floats until EOF
    while (scanf("%f", &num) != EOF) {
        float *tempArr = realloc(numArr, sizeof(float) * (++arrLen));
        if (tempArr == NULL) { // Check if realloc succeeded
            free(numArr); // Free previously allocated memory
            printf("Memory allocation failed.\n");
            return 1;
        }
        numArr = tempArr;
        numArr[arrLen - 1] = num; // Store the float value
    }

    int index = 1;
    while (arrLen > 0) {
        // printf("%d\n", index);
        if (index == arrLen) {
            break;
        } else if (numArr[index - 1] < numArr[index]) {
            index++;
        } else { // Swap logic
            int subIndex = index - 1;
            while (1) {
                if (numArr[subIndex] <= numArr[index]) {
                    itemsMove(index, subIndex + 1, &numArr); // Pass a pointer to the array
                    index++;
                    break;
                } else if (subIndex == 0) {
                    itemsMove(index, 0, &numArr); // Pass a pointer to the array
                    index++;
                    break;
                } else {
                    subIndex--;
                }
            }
        }
    }

    // Print sorted floats
    for (int i = 0; i < arrLen; i++) {
        printf("%.5f\n", numArr[i]);
    }

    free(numArr); // Free the array of floats
    return 0;
}
