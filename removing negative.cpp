#include <stdio.h>
#include <math.h>
int main () {
	int a[2][2][2]={1,2,-3,4,-5,6,7,-8};
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			for (int k=0; k<2; k++) {
			printf(" %d", a[i][j][k]);
		}
		printf("\n");
		}
	}
	printf("\n   After Removing negative values from the matrix:\n");
	
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			for (int k=0; k<2; k++) {
				if (a[i][j][k]<0) {
				a[i][j][k]=abs(a[i][j][k]);
		}
		printf(" %d", a[i][j][k]);
		}
		printf("\n");
		}
	}
	return 0;
}
