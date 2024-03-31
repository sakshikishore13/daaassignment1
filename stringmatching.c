#include <stdio.h>
#include <string.h>

int bruteForceStringMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;

    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i; // Return the index of the first occurrence
        }
    }

    return -1; // Pattern not found in the text
}

int main() {
    char text[1000], pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern to search for: ");
    scanf("%s", pattern);

    int index = bruteForceStringMatch(text, pattern);

    if (index != -1) {
        printf("Pattern found at index %d\n", index);
    } else {
        printf("Pattern not found in the text\n");
    }

    return 0;
}

