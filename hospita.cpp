#include <stdio.h>
int main() {
	int wards, patients, signs;
	printf("Enter number of wards:");
	scanf(" %d", &wards);
	printf("Enter number of patients:");
	scanf(" %d", &patients);
	printf("Enter number of signs:");
	scanf(" %d", &signs);
	
	int hospital[wards][patients][signs];
	for (int i=0; i<wards; i++) {
		for (int j=0; j<patients; j++) {
			for (int k=0; k<signs; k++) {
				scanf(" %d", &hospital[i][j][k]);
			}
		}
	}
	
	for (int i=0; i<wards; i++) {
		for (int j=0; j<patients; j++) {
			for (int k=0; k<signs; k++) {
				printf(" %d",hospital[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	for (int i = 0; i < wards; i++) {
        printf("\nWard %d - Total readings per patient:\n", i + 1);
        for (int j = 0; j < patients; j++) {
            int row_sum = 0;
            for (int k = 0; k < signs; k++) {
                row_sum += hospital[i][j][k];
            }
            printf("Patient %d: %d\n", j + 1, row_sum);
        }
    }

    for (int i = 0; i < wards; i++) {
        printf("\nWard %d - Total readings per vital sign:\n", i + 1);
        for (int k = 0; k < signs; k++) {
            int col_sum = 0;
            for (int j = 0; j < patients; j++) {
                col_sum += hospital[i][j][k];
            }
            printf("Vital %d: %d\n", k + 1, col_sum);
        }
    }
	return 0;
}
