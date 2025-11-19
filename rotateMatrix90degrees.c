#include <stdio.h>

void rotate(int n, int matrix[n][n]) {
    int i, j;

    // Step 1: Transpose
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}

void printMatrix(int n, int matrix[n][n]) {
	int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int i, j;
    printf("Enter the size of matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    // Taking matrix input
    printf("Enter %d elements:\n", n * n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Rotate the matrix
    rotate(n, matrix);

    // Print result
    printf("\nMatrix after 90 degree rotation:\n");
    printMatrix(n, matrix);

    return 0;
}
