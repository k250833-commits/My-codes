#include <stdio.h>
int main() {
	int pin,balance=50000,withdraw,remainingbalance;
	printf("Enter your 4-digit pin=\n");
	scanf(" %d", &pin);
	if(pin != 2413) {
		printf("Invalid pin\n");
		return 0;
	} 
	printf("How much you want to withdraw?");
	scanf(" %d", &withdraw);
	if(withdraw >= balance) {
		printf("Insufficient Balance\n");
		return 0;
	}
	remainingbalance = balance - withdraw;
	printf("Your remaining balance is %d", remainingbalance);
	return 0;
	
}
