#include<stdio.h>
void multiply_matrices(int a, int b, int c, int A[a][b], int B[b][c], int C[a][c]) {
    int i, j, k;
    for (i = 0; i < a; i++) {
        for (j = 0; j < c; j++) {
            int sum = 0;
            for (k = 0; k < b; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void display_matrices (int a, int b, int c, int A[a][b], int B[b][c]) {
	printf("\nMatrix A:\n");
	int i,j;
	for (i=0; i<a; i++) {
		for(j=0; j<b; j++)
		printf(" %d", A[i][j]);
		printf("\n");
	}
	printf("\nMatrix B:\n");
	for (i=0; i<b; i++) {
		for(j=0; j<c; j++)
		printf(" %d", B[i][j]);
		printf("\n");
	}
}
int main() {
	int a,b,c;
	printf("******************************    Multiplying Two Matrices   **************************\n");
	printf("Enter number of rows in Matrix A:");
	scanf(" %d", &a);
	printf("Enter number of columns in Matrix A:");
	scanf(" %d", &b);
	int A[a][b];
	int i,j;
	printf("\nEnter %d values for Matrix A: ", a*b);
	for (i=0; i<a; i++) {
		for(j=0; j<b; j++)
		scanf(" %d", &A[i][j]);
	}
	
	printf("\nEnter number of rows in Matrix B (this number must be same as the number of columns of matrix A): ");
	scanf(" %d", &b);
	printf("\nEnter number of columns in Matrix B:");
	scanf(" %d", &c);
	int B[b][c];
	printf("\nEnter %d values for Matrix B: ", b*c);
	for (i=0; i<b; i++) {
		for(j=0; j<c; j++)
		scanf(" %d", &B[i][j]);
	}
    display_matrices(a,b,c,A,B);
    int C[a][c];  
    multiply_matrices(a,b,c,A,B,C);
    printf("\nProduct matrix (A x B):\n");
    for ( i = 0; i < a; i++) {
    for ( j = 0; j < c; j++) {
        printf("%d ", C[i][j]);
    }
    printf("\n");
}
	return 0;
}
