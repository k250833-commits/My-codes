#include <stdio.h>

void moveZeroes(int a[], int n) {
    int pos = 0;   // next position for a non-zero number

    // Step 1: Move all non-zero elements forward
    int i;
    for ( i = 0; i < n; i++) {
        if (a[i] != 0) {
            a[pos++] = a[i];
        }
    }

    // Step 2: Fill remaining positions with zero
    while (pos < n) {
        a[pos++] = 0;
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    moveZeroes(arr, n);

    printf("Output: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
