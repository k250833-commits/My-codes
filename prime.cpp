#include <stdio.h>

int main() {
    int num, i, isPrime = 1;
    printf("Enter a number:");
    scanf("%d", &num7);

    if (num <= 1) {
        isPrime = 0;
    } else {   
        for (i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }
    if (isPrime == 1)
        printf("%d is a Prime Number.\n", num);
    else
        printf("%d is NOT a Prime Number.\n", num);

    return 0;
}

