#include <stdio.h>
int main() {
	int rooms, floors, beds;
	int empty=0;
	printf("Enter number of floors:");
	scanf(" %d", &floors);
	printf("Enter number of rooms:");
	scanf(" %d", &rooms);
	printf("Enter number of beds:");
	scanf(" %d", &beds);
	// enter 0 or 1 for empty or occupied beds respectively
	printf("Enter 0 or 1 for each bed in each of the rooms on each floor:\n");
	printf("   Room   Room ");
	int building[floors][rooms][beds];
	for (int i = 0; i < floors; i++)
      for (int j = 0; j < rooms; j++)
        for ( int k = 0; k < beds; k++)
      scanf(" %d", &building[i][j][k]);
      printf("\n");
      
    for (int i = 0; i < floors; i++) {
    	for (int j = 0; j < rooms; j++) {
    		for ( int k = 0; k < beds; k++) {
    			if ( building[i][j][k]==0) {
    				empty++;
				}
			}
		}
	}
	printf("There are total %d empty beds in the building", empty);  
    return 0;
}
