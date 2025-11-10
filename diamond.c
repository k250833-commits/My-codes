#include<stdio.h>

int main() {
	int i,j;
	int r;
	printf("Enter rows: ");
	scanf("%d", &r);
	for(i=1; i<=r; i++) {
		for(j=i; j<r ;j++) {
			printf(" ");
		}
		for (j=1; j<= (2*i-1); j++){
			printf("*");
		}
		printf("\n");
	}
	
	for(i=r-1; i>=1; i--) {
		for(j=r;j>i ;j--) {
			printf(" ");
		}
		for (j=1; j<=(2*i-1) ; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
