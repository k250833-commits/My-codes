#include <stdio.h>
int main() {
    int r;
    printf("How many rows do you want? ");
    scanf("%d", &r);
 
    char letters[r];

    printf("Enter %d alphabets:\n", r);
    for (int i = 0; i < r; i++) {
        scanf(" %c", &letters[i]);
    }
    printf("\n");
    int index = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c ", letters[j]);  
        }
        printf("\n");
    }

    return 0;
}

