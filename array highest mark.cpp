#include <stdio.h>

int main() {
    int marks[6];
    int n;
    int highest_mark;
    printf("Enter marks of 6 students:\n");
    for (int i=1; i<=5;i++) {
    	 scanf(" %d", &marks[i]);
	}
    
    for (int i = 1; i <=6; i++) {
        if (marks[i] > highest_mark) {
            highest_mark = marks[i]; 
        }
    }

    printf("The highest mark is: %d\n", highest_mark);

    return 0;
}
