#include <stdio.h>

int main(){

int a;
char b,c,d,e;

 printf("What is your age?\n");
 scanf(" %d", &a);
  if(a < 18){
  	printf("You are ineligible to vote!\n");
  	
  	return 0;
  }
  
  printf("Have you passed (P) or failed (F )your eyesight exam?\n");
  scanf(" %c", &b);
  
  if(b == 'F'){
  	printf("You might need a prescription for glasses\n");
  	return 0;
  }
  printf("Have you passed (P) or failed (F) your written test?\n");
  scanf(" %c", &c);
  
  if(c == 'F'){
  	printf("You need to take retest\n");
  
    return 0;
}
  printf("Have you passed (P) or failed (F) your driving test?\n");
  scanf(" %c", &d);
  
  if(d == 'F'){
  	printf("Sorry you are not eligible to vote!\n");
  
    return 0;
}
  if(a < 60){
  	printf("You are eligible for the license\n");
  	return 0;
  }
  printf("Do you have medical fitness certificate or not?\n");
  scanf(" %c", &e);
  if(e == 'N'){
  	printf("You are not eligible for the license!\n");
  	return 0;
  }
  printf("You are eligible for the license!\n");
  return 0;
  }
  
