#include <stdio.h>
#include <string.h>
#include <ctype.h>

// return 1 if s is a palindrome, 0 otherwise
int is_palindrome(const char s[]) {
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

int main() {
    const char *arr[] = {"apple", "radar", "hello", "level"};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    for (k = 0; k < n; k++) {
        if (is_palindrome(arr[k])) {
            printf("First palindrome: %s\n", arr[k]);
            return 0; // stop after finding the first palindrome
        }
    }

    printf("No palindrome found\n");
    return 0;
}
