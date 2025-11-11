#include <stdio.h>
int *sort(int n, int array[]) {
	int i, j, temp;
	for (i=0; i<n-1; i++) {
		for ( j=0; j<n-i-1; j++) {
			if (array[j]>array[j+1]) {
			     temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	return *array;
}
int main() {
    int n,i,j;
    int temp;
    printf("How many nums do you want?: ");
    scanf("%d", &n);
    printf("Input nums: ");
    int final[n];
    int array[n];
    for (i=0; i<n; i++) {
    	scanf("%d", &array[i]);
	}
	for (i=0; i<n; i++) {
		if (array[i]%2 == 0) {
			array[i]=0;
		}
		else {
			array[i]=1;
		}
	}
	printf("\n");
	sort(n, array);
	for (i=0; i<n; i++) {
	    printf(" %d ", array[i]);	
	}
    return 0;
}

