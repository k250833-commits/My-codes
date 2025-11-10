#include<stdio.h>
int main() {
	int i,j;
	int n;
	int sum[n];
	printf("How many elements do you want? ");
	scanf("%d", &n);
	printf("\nEnter the elements: ");
	int arr[n];
	for (i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i=0; i<n; i++) {
		sum[n]+=arr[i];
		printf("%d ", sum[n]);
	}
	return 0;
}
