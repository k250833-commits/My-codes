#include <stdio.h> 
int main () {
	int r,c;
	printf("Enter Number of Rows your matrices will be having:");
	scanf(" %d", &r);
	printf("\nEnter Number of Columns your matrices will be having:");
	scanf(" %d", &c);
	int Matrix1[r][c];
	int Matrix2[r][c];
	printf("\nEnter %d elements for Matrix 1:", r*c);
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			scanf(" %d", &Matrix1[i][j]);
		}
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			printf(" %d", Matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter %d elements for Matrix 2:", r*c);
		for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			scanf(" %d", &Matrix2[i][j]);
		}
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			printf(" %d", Matrix2[i][j]);
		}
		printf("\n");	
	} printf("\n");
	
	int Result[r][c];
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			Result[i][j]= Matrix1[i][j] + Matrix2[i][j];
			printf(" %d", Result[i][j]);
		}
		printf("\n");	
	}
	return 0;
}
