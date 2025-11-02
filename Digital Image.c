#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
int i, j;
void displayMatrix(int arr[SIZE][SIZE]) {
    for ( i = 0; i < SIZE; i++) {
        for ( j = 0; j < SIZE; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }
}

int main() {
    int image[SIZE][SIZE], bright[SIZE][SIZE];
    srand(time(0));

    // Generate random pixel values
    for (i = 0; i < SIZE; i++)
        for ( j = 0; j < SIZE; j++)
            image[i][j] = rand() % 256;

    // Brighten image
    for ( i = 0; i < SIZE; i++)
        for ( j = 0; j < SIZE; j++)
            bright[i][j] = (image[i][j] + 20 > 255) ? 255 : image[i][j] + 20;

    printf("Original Image:\n");
    displayMatrix(image);

    printf("\nBrightened Image:\n");
    displayMatrix(bright);

    return 0;
}

