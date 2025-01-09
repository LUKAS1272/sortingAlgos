#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itemsMove(int fromIndex, int toIndex, char *target[]) {
    for (int i = fromIndex; i > toIndex; i--) {
        char *temp = target[i];
        target[i] = target[i - 1];
        target[i - 1] = temp;
    }
}

int main() {
    char word[100]; // Buffer to hold each word temporarily
    int arrLen = 0;
    char **wordArr = calloc(arrLen, sizeof(char *)); // Array of strings (char pointers)

    // Read words until EOF
    while (scanf("%99s", word) != EOF) {
        wordArr = realloc(wordArr, sizeof(char *) * ++arrLen);
        wordArr[arrLen - 1] = strdup(word); // Copy the word to a new string in the array
    }

    int index = 1;
    while (arrLen > 0) {
        // printf("%d\n", index);
        if (index == arrLen) {
            break;
        } else if (strcmp(wordArr[index - 1], wordArr[index]) <= 0) {
            index++;
        } else { // Swap logic
            int subIndex = index - 1;
            while (1) {
                if (strcmp(wordArr[subIndex], wordArr[index]) < 0) {
                    itemsMove(index, subIndex + 1, wordArr);
                    index++;
                    break;
                } else if (subIndex == 0) {
                    itemsMove(index, 0, wordArr);
                    index++;
                    break;
                } else {
                    subIndex--;
                }
            }
        }
    }

    printf("----------\n");

    // Print sorted words
    for (int i = 0; i < arrLen; i++) {
        printf("%s\n", wordArr[i]);
        free(wordArr[i]); // Free each individual string
    }

    free(wordArr); // Free the array of pointers
    return 0;
}
