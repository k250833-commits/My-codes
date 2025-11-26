#include <stdio.h>
int tribo(int n) {
	if(n==1 || n==4) return n;
	if(n==2 || n==3) return n-1;
	return tribo(n-1)+ tribo(n-2)+ tribo(n-3);
}
int main () {
	int n;
	printf("Enter number of terms you want in tribonacci series: ");
	scanf("%d", &n);
	printf("The sum of Tribonacci series is : %d", tribo(n));
	return 0;
}
