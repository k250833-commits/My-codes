#include <stdio.h>
#include <string.h>
int isVowel(char c) {
    c = (c >= 'A' && c <= 'Z') ? c + 32 : c;  // convert to lowercase
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    int left = 0, right = 0;

    // find the length manually (no string library)
    while (str[right] != '\0') {
        right++;
    }
    right--; // point to last character (before '\0')

    // Two-pointer technique
    while (left < right) {

        // move left pointer forward until we find a vowel
        if (!isVowel(str[left])) {
            left++;
            continue;
        }

        // move right pointer backward until we find a vowel
        if (!isVowel(str[right])) {
            right--;
            continue;
        }

        // swap the vowels
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    printf("String after reversing vowels: %s", str);
    return 0;
}
