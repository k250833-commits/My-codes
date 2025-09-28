
#include <stdio.h>
int main(){
	
	int x=2,y=4,z=5;
    
	printf("The expression used is \n         x + y * z > 10 && x - z < y || !(y % z) \n(Considering x = 2 , y = 4 , z = 5)\n");
	printf("Step by step evaluation is a follows : \n");
	printf("Step 1 : y * z = 4 * 5 = %d\n", y*z);
	printf("Step 2 : x + (y * z) = 2 + %d = %d\n", y*z, x+(y*z));
	printf("Step 3 : x + y * z > 10 = %d > 10 = %d\n", x+(y*z), x+y*z>10);
	printf("Step 4 : x - z = 2 - 5 = %d\n", x-z);
	printf("Step 5 : x - z < y = %d < 4 = %d\n", x-z, x-z<y);
	printf("Step 6 : (x + y * z > 10) && (x - z < y) =  %d\n", x+ y*z>10 && x-z<y);
	printf("Step 7 : y %% z = 4 %% 5 = %d\n", y%z);
	printf("Step 8 : !(y %% z) = !(4) =  %d\n", !(y % z));
	printf("Final Step : (x + y * z > 10) && (x - z < y) || !(y % z) = 1 || 0 = %d\n", x + y * z > 10 && x - z < y || !(y % z));
		
	return 0;
}
