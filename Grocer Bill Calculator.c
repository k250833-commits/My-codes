#include <stdio.h>

float total(float qty, float price) {
    return qty * price;
}

int main() {
    char name[50], item[50];
    int n;
    int i;
    float qty, price, totalAmount = 0;

    printf("Enter customer name: ");
    gets(name);
    printf("Enter number of items: ");
    scanf("%d", &n);

    for ( i = 1; i <= n; i++) {
        printf("\nEnter item name: ");
        scanf("%s", item);
        printf("Enter quantity: ");
        scanf("%f", &qty);
        printf("Enter price per unit: ");
        scanf("%f", &price);
        totalAmount += total(qty, price);
    }

    printf("\nTotal bill for %s is: %.2f\n", name, totalAmount);
    return 0;
}

