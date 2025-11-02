#include <stdio.h>

int hcf(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / hcf(a, b);
}

int main() {
    int a, b, choice;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Press 1 for HCF\nPress 2 for LCM\n");
    scanf("%d", &choice);

    if (choice == 1)
        printf("HCF = %d\n", hcf(a, b));
    else if (choice == 2)
        printf("LCM = %d\n", lcm(a, b));
    else
        printf("Invalid choice!\n");

    return 0;
}

