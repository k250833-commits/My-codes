#include<stdio.h>

int main() {
	int r,c,n;
	printf("Enter nuber of rows: ");
	scanf("%d", &r);
	printf("\nEnter nuber of columns: ");
	scanf("%d", &c);
	printf("\nEnter %d elements: ", r*c);
	int matrix[r][c];
	int i,j;
	for (i=0; i<r; i++) {
		for (j=0; j<c; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\nYour matrix is: \n");
	for (i=0; i<r; i++) {
		for (j=0; j<c; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	int sum=0;
	for (i=0; i<r; i++) {
		for (j=0; j<c; j++) {
			sum+=matrix[i][j];
		}
	}
	printf("\nThe sum of all elements is: %d", sum);
	return 0;
}
