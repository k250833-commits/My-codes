#include <stdio.h>
int main() {
    int base, exponent, power = 1;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    for (int i = 1; i <= exponent; i++) {
        power = power * base;
    }

    printf("%d^%d = %d\n", base, exponent, power);
    return 0;
}

