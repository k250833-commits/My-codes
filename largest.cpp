#include <stdio.h>

int main(){
int st1,st2,st3,highest;
printf("Enter Marks of First student=\n");
scanf(" %d",&st1);

printf("Enter Marks of Second student=\n");
scanf(" %d",&st2);

printf("Enter Marks of Third student=\n");
scanf(" %d",&st3);

highest = (st1 > st2)? (st1 > st3 ? st1:st3) : (st2 > st3 ? st2 : st3); 

printf("The Highest Mark is: %d\n", highest);
return 0;

}
