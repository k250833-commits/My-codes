#include <stdio.h>
#include <math.h>
int main() {


int radius;
float pi = 3.14159;
float area;
float circumference;
float sqrtofradius;

printf("Enter Radius of Circular Water Tank:\n");
scanf(" %d", &radius);

area = pi * pow(radius,2);
circumference = 2 * pi * radius;
sqrtofradius = sqrt(radius);

printf("The Area of the Circular Water Tank is %.2f\n",area);
printf("The Circumfernce of the Circular Water Tank is %.2f\n",circumference);
printf("The Square Root of Radius of the Circular Water Tank is %.2f\n",sqrtofradius);

return 0;

}
