#include <stdio.h>
int main() {
	int price[]={100,200,50,500,350,650};
	int budget, found=0;
	printf("Enter Budget:\n");
	scanf(" %d", &budget);
	for (int i=0; i<6; i++) {
		for (int j=i+1; j<6; j++) {
			if (price[i]+price[j] == budget) {
			printf("The sum of Rs. %d and Rs. %d equals the budget\n",price[i],price[j]);
			found = 1;	
			}	
		}
	}
	if (!found) {
		printf("No two prices add up to the budget.\n");
	}
	return 0;
}
