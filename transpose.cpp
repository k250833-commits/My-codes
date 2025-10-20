#include<stdio.h> 
int main () {
	int r,c;
	printf("Enter number of scores of students:");
	scanf(" %d", &r);
	// 1: maths, 2: english, 3:urdu, 4:chemistry, 5:physics
	printf("\nEnter how many subjects(1-5):");
	scanf(" %d", &c);
	printf("Enter the elements of your matrix:\n");
	int a[r][c];
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			scanf(" %d", &a[i][j]);
		}
	}
	printf("\n Your matrix:\n");
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("                                Transpose of this matrix:\n");
	for (int i=0; i<c; i++) {
		for (int j=0; j<r; j++) {
			printf(" %d", a[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}
