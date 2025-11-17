#include<stdio.h>
int main() {
    char str[100], rev[100];
    int i, len = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate length of the string
    while (str[len] != '\0' && str[len] != '\n') {
        len++;
    }

    // Reverse the string
    for (i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0'; // Null-terminate the reversed string

    printf("Reversed string: %s\n", rev);
    return 0;
}