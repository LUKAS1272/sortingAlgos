#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int assignPair(char *arr[], int currentIndex) {
    if (strcmp(arr[currentIndex], arr[currentIndex + 1]) > 0) { // Compares two strings
        char *temp = arr[currentIndex];
        arr[currentIndex] = arr[currentIndex + 1];
        arr[currentIndex + 1] = temp;
        return 1; // Return one mistake
    }
    return 0; // Return zero mistakes
}

int main() {
    char word[100];  // Fixed buffer of 100 chars
    int arrLen = 0, indexesDone = 0;
    char **wordsArr = NULL;

    // Read input words with a buffer limit of 100 characters
    while (scanf("%99s", word) != EOF) { // Reads a word up to 99 chars (100 includes the null terminator)
        wordsArr = realloc(wordsArr, sizeof(char*) * ++arrLen);
        wordsArr[arrLen - 1] = strdup(word); // Copies the word into the array
    }

    while (1) { // Sorts the array
        int mistakes = 0;
        for (int index = 0; index < arrLen - indexesDone - 1; index++) {
            mistakes += assignPair(wordsArr, index); // Assigns pair and swaps words, if needed
        }
        if (mistakes > 0) {
            indexesDone++; // If there were mistakes, the sorted array shortens
        } else {
            break; // If there were no mistakes, the sort ends
        }
    }

    // Output sorted words
    for (int i = 0; i < arrLen; i++) { 
        printf("%s\n", wordsArr[i]); 
    }

    // Free memory
    for (int i = 0; i < arrLen; i++) { 
        free(wordsArr[i]); 
    }
    free(wordsArr); // Frees dynamic array
    return 0;
}
