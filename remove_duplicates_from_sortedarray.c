#include <stdio.h>

int removeDuplicates(int nums[], int n) {
	int i;
    if (n == 0) return 0;

    int k = 1;  // index for unique elements

    for (i = 1; i < n; i++) {
        if (nums[i] != nums[k - 1]) {  // new unique element
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter %d sorted integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int k = removeDuplicates(nums, n);

    printf("\nNumber of unique elements: %d\n", k);
    printf("Array after removing duplicates:\n");

    for (i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
