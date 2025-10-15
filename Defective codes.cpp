#include <stdio.h>
int main () {
	int n;
	printf("Enter the number of items:");
	scanf(" %d", &n);
	int codes[n];
	for (int i=0; i<n; i++) {
		printf("\nCode of item %d:",i+1);
		scanf("%d", &codes[i]);
	}
	int defect;
	printf("\nEnter Defective item's code:");
	scanf(" %d", &defect);
	for (int i=0; i<n; i++) {
		if (codes[i]==defect) {
			for (int j = i; j < n - 1; j++) {
                codes[j] = codes[j + 1];  
            }
            n--; 
            i--;
		}
	}
	 printf("\nUpdated item codes:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", codes[i]);
    }

	return 0;
}
