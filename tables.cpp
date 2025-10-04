#include <stdio.h>
int main() {
	int a;
	int b;
	char d;
	int i;
	printf("Which number table do you want?\n");
	scanf(" %d",&a);
	for (i=1; i<=10; i++) {
		b= i*a;
	printf(" %d * %d = %d\n",a,i,b);
}
    printf("Do you want to print another table?  Y/N\n");
    scanf(" %c",&d);
    if (d == 'Y')
    {
    	main();
	}
	return 0;
}
