#include <stdio.h>

int main() {
	int a=5,b=3,step1,step2,result;
	
step1 = a&b;
printf("As a is 5 and b is 3 therefore a&b will be %d and in 001 binary\n",step1);
step2 = a^b;
printf("As a is 5 and b is 3 therefore a^b will be %d and in 110 binary\n",step2);	
result = (a&b)| (a^b);
printf("Result is %d and 111 in binary\n", result);
return 0;	
	
}
