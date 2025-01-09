#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STRINGS 1000000
#define MIN_STRING_LENGTH 5
#define MAX_STRING_LENGTH 10

// Function to generate a random string of a length between MIN_STRING_LENGTH and MAX_STRING_LENGTH
void generateRandomString(char *str) {
    int length = MIN_STRING_LENGTH + rand() % (MAX_STRING_LENGTH - MIN_STRING_LENGTH + 1);  // Random length between 5 and 10

    for (int i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;  // Random character between 'a' and 'z'
    }
    str[length] = '\0';  // Null-terminate the string
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for each random string
    char str[MAX_STRING_LENGTH + 1];  // Maximum possible string length is 10, plus null terminator

    // Generate and print 1 million random strings with lengths from 5 to 10
    for (int i = 0; i < NUM_STRINGS; i++) {
        generateRandomString(str);
        printf("%s\n", str);  // Print the string followed by a newline
    }

    return 0;
}
