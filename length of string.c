#include<stdio.h>
void func(char *n) {
	int length=0;
	char *ptr=n;
	while (*ptr !='\0') {
		length++;
		(ptr)++;
	}
	printf("%d", length);
}
int main() {
	char n[100];
	printf(" Enter a string: ");
	fgets(n, sizeof(n), stdin);
	func(n);
	return 0;
}
