#include <stdio.h>
int stairs(int n) {
	if(n<=2) return n;
	int totalways=stairs(n-1)+ stairs(n-2);
	return totalways;
}
int main () {
	int n;
	printf("Enter number of stairs: ");
	scanf("%d", &n);
	int ways=stairs(n);
	printf("Total number of ways: %d", ways);
	return 0;
}
