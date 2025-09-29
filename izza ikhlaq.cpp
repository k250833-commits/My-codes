#include <stdio.h>
int main() {
	int n, factorial=1, i=1;
	printf("Enter a Non-Negative Number=\n");
	scanf(" %d", &n);
	if(n<0) {
		printf("Factorial is not defined for Negative Numbers\n");
	}
	else {
		while(i<=n) {
			factorial*=i;
			i++;
	
		}
		printf("Factorial of %d IS %d",n,factorial);
		}
		return 0;
}
