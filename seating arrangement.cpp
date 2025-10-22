#include <stdio.h>
int main () {
	int r;
	int wrong=0;
	printf("Enter number of rows and columns as both have to be same: ");
	scanf(" %d", &r);
	
	int a[r][r];
	printf("\nEnter 0s or 1s as per the seating arrangement: ");
	for (int i=0; i<r; i++) {
		for (int j=0; j<r; j++) {
			scanf(" %d", &a[i][j]);
		}
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<r; j++) {
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}
	
	for (int i=0; i<r; i++) {
		for (int j=0; j<r; j++) {
		if (i == j && a[i][j] != 1) {
    wrong = 1;
        }
        else if (i != j && a[i][j] != 0) {
    wrong = 1;
         }
	}
}
    
    if(wrong==1) {
    	printf("\nWrong seating arrangement");
	}
	else {
		printf("\nWoah the seating arrangement is perfect");
	}
	return 0;
}
