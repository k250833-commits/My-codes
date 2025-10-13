#include <stdio.h>

int main() {
    int arr[7] = {1, 1, 2, 2, 2, 3, 4};
    int n = 7;
    int uniqueIndex = 0;
    printf("Array before removing duplicates:");
    for (int i=0; i<=6; i++) {
    	printf(" %d", arr[i]);
	}
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }

    int uniqueCount = uniqueIndex + 1;

    printf("\nArray after removing duplicates:");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

