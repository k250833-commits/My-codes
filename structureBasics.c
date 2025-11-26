#include <stdio.h>
typedef struct student{
	int age;
	char first_name[50];
	char last_name[50];
	int standard;
}student;
int main () {
	student st1;
	printf("Enter age of student: ");
	scanf("%d", &st1.age);
	printf("\nEnter first name of student: ");
	scanf(" %s", st1.first_name);
	printf("\nEnter last name of student: ");
	scanf(" %s", st1.last_name);
	printf("\nEnter standard of student: ");
	scanf("%d", &st1.standard);
	
	printf("%d  ",st1.age);
	printf("%s  ",st1.first_name);
	printf("%s  ",st1.last_name);
	printf("%d",st1.standard);
	return 0;
}
