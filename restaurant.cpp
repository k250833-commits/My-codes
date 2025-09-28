#include <stdio.h>
int main() {


    char Order, CoffeeSize, CoffeeType;
    int CoffeeNo;
    float price1 = 0, total = 0, price2 = 0, price = 0,a = 0;

    printf("Place your order (C = Coffee Shop, B = Burger Hub, I = Ice Cream Parlour):\n");
    scanf(" %c", &Order);  

    if (Order == 'B' || Order == 'I') {
        printf("Order will be handled by that section.\n");
    }
    else if (Order == 'C') {
        printf("Order = Coffee Shop\n");

        
        printf("Choose your Coffee Size (S, M, L):\n");
        scanf(" %c", &CoffeeSize);

        if (CoffeeSize == 'S')      price1 = 200;
        else if (CoffeeSize == 'M') price1 = 300;
        else if (CoffeeSize == 'L') price1 = 400;
        else {
            printf("Invalid size selected.\n");
            return 0;
        }


        printf("Choose the number of coffees:\n");
        scanf("%d", &CoffeeNo);

        if (CoffeeNo > 1) {
            printf("Check our combo offers!\n");
        if (CoffeeNo == 2) a = price1 - 50;
        if (CoffeeNo == 3) a = price1 - 70;
        if (CoffeeNo == 4) a = price1 - 90;
        if (CoffeeNo > 4) a = price1 - 170;
		    
        }

        
        printf("Choose your coffee type (R = Regular, C = Cappuccino, L = Latte):\n");
        scanf(" %c", &CoffeeType);

        if (CoffeeType == 'R') price2 = 20;
        else if (CoffeeType == 'C') price2 = 50;
        else if (CoffeeType == 'L') price2 = 100;
        else {
            printf("Invalid type selected.\n");
            return 0;
        }

        price = a + price2;   

        // Final Bill
        total = price * CoffeeNo;
        printf("\n--- Final Bill ---\n");
        printf("Price per coffee: %.2f\n", price);
        printf("Quantity: %d\n", CoffeeNo);
        printf("Total Bill: %.2f\n", total);
    }
    else {
        printf("Invalid option selected.\n");
    }

    return 0;

}
