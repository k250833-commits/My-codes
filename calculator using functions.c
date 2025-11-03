#include<stdio.h>
int add(int *x, int *y) {
	int f= *x + *y;
	return f;
}
int subtract(int *x, int *y) {
	int s= *x - *y;
	return s;
}
int multiply(int *x, int *y) {
	int m= *x  *  *y;
	return m;
}
int divide(int *x, int *y) {
	int i= *x / *y;
	return i;
}
int main () {
	int sum,diff,prod,quot;
	int a,b,choice;
	char c;
	printf(" *****************************           Performing Calculations          *******************************\n\n");
	printf("Note:\nEnter two numbers such that the first number is greater than the second one and the second number is exactly divisible by the first one.\n");
	printf("Enter first number: ");
	scanf(" %d", &a);
	printf("\nEnter second number: ");
	scanf(" %d", &b);
	printf("\nWanna perform calculations? (y/n): ");
	scanf(" %c", &c);
	if (c=='y') {
		do {
			printf("\nWhich operation do you want to perform? (1/2/3/4/5):\n");
			printf("1. Addition (+)\n");
			printf("2. Subtraction (-)\n");
			printf("3. Multiplication (*)\n");
			printf("4. Division (/)\n");
			printf("5. Exit\n\n");
			scanf(" %d", &choice);
		switch (choice) {
		case 1:
			sum= add(&a,&b);
			printf("\n The sum of both numbers is %d", sum);
			break;
		case 2:
			diff= subtract(&a,&b);
			printf("\n The difference of both numbers is %d", diff);
			break;
		case 3:
			prod= multiply(&a,&b);
			printf("\n The product of both numbers is %d", prod);
			break;
		case 4:
			quot= divide(&a,&b);
			printf("\n The quotient of both numbers is %d", quot);
			break;
		case 5:
			printf("\n\nExiting........ Goodbye!");
			break;
	}
		}
		while (choice!=5);
	}
	else {
		printf("\nOh! I see you aren't interested in calculations.");
	}
	
	return 0;
}
