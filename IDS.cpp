#include <stdio.h>

int main() {
    int n;

    printf("Enter number of employee IDs: ");
    scanf("%d", &n);

    int arr[n];
    int temp[n];
    int index = 0;

    printf("Enter the employee IDs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    printf("Rearranged employee IDs (even first, then odd):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

