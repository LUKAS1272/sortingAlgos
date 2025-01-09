#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(char *wordsArr[], int *arrLen) {
    int indexesDone = 0;

    while (1) { // Sorts the array
        char *smallestWord = wordsArr[indexesDone];
        int smallestWordIndex = indexesDone;
        int isMistake = 0;

        for (int index = indexesDone + 1; index < *arrLen; index++) {
            if (strcmp(wordsArr[index], smallestWord) < 0) {
                smallestWord = wordsArr[index];
                smallestWordIndex = index;
                isMistake = 1;
            }
        }

        if (isMistake == 1) {
            wordsArr[smallestWordIndex] = wordsArr[indexesDone];
            wordsArr[indexesDone] = smallestWord;
        }

        indexesDone++;
        if (indexesDone >= *arrLen - 1) {
            break;
        }
    }
}

void arrayLoad(char **wordsArr[], int *arrLen) {
    char word[100];
    *arrLen = 0;
    *wordsArr = realloc(NULL, sizeof(char*));

    while (scanf("%99s", word) != EOF) { // Scans for input
        *wordsArr = realloc(*wordsArr, sizeof(char*) * (++(*arrLen)));
        (*wordsArr)[*arrLen - 1] = strdup(word); // Copies word into the array
    }
}

int main() {
    char **wordsArr;
    int arrLen = 0;

    arrayLoad(&wordsArr, &arrLen);
    selectionSort(wordsArr, &arrLen);
    for (int i = 0; i < arrLen; i++) {
        printf("%s\n", wordsArr[i]); 
        free(wordsArr[i]); // Free each word
    }

    free(wordsArr); // Free the array of pointers
    return 0;
}
