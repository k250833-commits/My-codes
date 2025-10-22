#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int image[rows][cols][3]; // 3D array: [row][col][RGB]

    printf("\nEnter RGB values for each pixel:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Pixel[%d][%d] (R G B): ", i, j);
            scanf("%d %d %d", &image[i][j][0], &image[i][j][1], &image[i][j][2]);
        }
    }

    int totalR = 0, totalG = 0, totalB = 0;
    int totalPixels = rows * cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            totalR += image[i][j][0];
            totalG += image[i][j][1];
            totalB += image[i][j][2];
        }
    }

    float avgR = totalR / (float) totalPixels;
    float avgG = totalG / (float) totalPixels;
    float avgB = totalB / (float) totalPixels;

    printf("\nAverage RGB color intensity:\n");
    printf("R = %.2f, G = %.2f, B = %.2f\n", avgR, avgG, avgB);

    return 0;
}

