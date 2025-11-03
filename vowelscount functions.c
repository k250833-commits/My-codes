#include<stdio.h>
void func(char *n, int *consonants, int *vowels) {
	*consonants=0;
	*vowels=0;
	char *ptr=n;
	while (*ptr != '\0') {
		if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) {
            if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' ||
                *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') {
			(*vowels)++;
		}
		else {
			(*consonants)++;
		}
	}
	(ptr)++;
	}
}
int main () {
	int a,b;
	char n[100];
	printf("Enter a string: "); 
	fgets(n, sizeof(n), stdin);
	func(n, &a, &b);
	printf("\n There are %d consonants and %d vowels in this string", a,b);
	return 0;
}
