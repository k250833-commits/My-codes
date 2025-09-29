#include <stdio.h>
int main() {
	int a = 4567;
	int password;
	
	do{
		printf("Kindly enter your 4-digit password=\n");
		scanf(" %d", &password);	
		if(password==a) {
			printf("You have entered correct password\n");
		}
		else {
			printf("Incorrect password try again!\n");
		}
	}
	while(password!=a);

return 0;
}
