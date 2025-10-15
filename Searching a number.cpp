#include <stdio.h>
int main () {
	int list[10];
	int search, found=0;
	printf("Enter the list of integers:\n");
	for (int i=0; i<10; i++) {
		scanf(" %d", &list[i]);
	} 
	printf("\nEnter the Number you want to search:");
	scanf(" %d", &search);
	for (int i=0; i<10; i++) {
		if (list[i]==search) {
			found=1;
			printf(" %d lies at index %d", search,i);
			break;	
		}	
	}
	if (found==0) {
		printf("This number is not present in the list of integers\n Kindly enter another number");
	}
	return 0;
}
