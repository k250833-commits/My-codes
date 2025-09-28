#include <stdio.h>

int main() {
    int a, b, c, d, e;
    
    
    
    printf("Enter 5 cards (1-13): ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    
    int countA = (a==b) + (a==c) + (a==d) + (a==e) + 1; // include 'a' itself
    int countB = (b==a) + (b==c) + (b==d) + (b==e) + 1;
    int countC = (c==a) + (c==b) + (c==d) + (c==e) + 1;
    int countD = (d==a) + (d==b) + (d==c) + (d==e) + 1;
    int countE = (e==a) + (e==b) + (e==c) + (e==d) + 1;

    if ((countA == 3 && countB == 2) || (countA == 2 && countB == 3) || (countB == 3 && countC == 2) || (countB == 2 && countC == 3)
	|| (countC == 3 && countD == 2) || (countC == 2 && countD == 3) || (countD == 3 && countE == 2) || (countD == 2 && countE == 3
	|| (countE == 3 && countA == 2) || (countE == 2 && countA == 3) || (countA == 3 && countC == 2) || (countA == 2 && countC == 3)
	|| (countA == 3 && countD == 2) || (countA == 2 && countD == 3) || (countB == 3 && countD == 2) || (countB == 2 && countD == 3)
	|| (countB == 3 && countE == 2) || (countB == 2 && countE == 3) || (countC == 3 && countE == 2) || (countC == 2 && countE == 3))) {
        printf("Full House!\n");
    } else {
        printf("Not a Full House.\n");
    }

    return 0;
}

