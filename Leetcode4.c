#include<stdio.h>
int convert (float *celsius) {
	float newx=*celsius + 273.15;
	return newx;
}
int convert2 (float *celsius) {
	float newy=*celsius * 1.80 +32.00;
	return newy;
}
int main() {
	float x, y;
	printf("Enter the temperature you want to convert in kelvin and Fahrenheit: ");
	scanf(" %f", &x);
	float Kelvin=convert(&x);
	float Fahrenheit=convert2(&x);
	printf("\nTemperaturem at %.2f Celsius converted in Kelvin is %.2f and converted in Fahrenheit is %.2f.", x,Kelvin,Fahrenheit);
	return 0;
}
