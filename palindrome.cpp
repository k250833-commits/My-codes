#include <stdio.h>
int main() {
int num;
int rev = 0, rem, x;
printf("Enter any number:");
scanf(" %d", &num);
x=num;
while (x>0) {
rem = x%10;
rev = rev*10 + rem;
x= x/10;
}
if(rev == num) {
	printf("%d is a Palindrome", num);
}
else {
	printf("%d is not a Palindrome",num);
}
return 0;
}
