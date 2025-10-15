#include <stdio.h>
int main () {
	int Employee_IDs[5];
	int k;
	printf("Enter the 5 IDs:\n");
	for (int i=0; i<5; i++) {
	scanf(" %d", &Employee_IDs[i]);
	}
	printf("Enter the value of k by which you want the IDs to shift right:\n");
	scanf(" %d", &k);
	k=k%5;
	int rotated[5];
    for (int i = 0; i < 5; i++) {
        rotated[(i + k) % 5] = Employee_IDs[i];
    }
	printf("The New Arrangement is:");
	for (int i=0; i<5; i++) {
		printf("%d",rotated[i] );
	}
	return 0;
}
