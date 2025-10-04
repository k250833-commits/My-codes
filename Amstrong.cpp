#include <stdio.h>

int main() {
    int num, originalNum, remainder, result = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    originalNum = num; 
    while (num != 0) {
        remainder = num % 10;          
        result = result + (remainder * remainder * remainder); 
        num = num / 10;                
    }
    if (result == originalNum)
        printf("%d is an Armstrong number.\n", originalNum);
    else
        printf("%d is NOT an Armstrong number.\n", originalNum);

    return 0;
}

