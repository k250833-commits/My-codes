#include <stdio.h>
int main () {
	int seats[10]={1,0,0,1,1,0,1,0,0,1};
	int seatno;
	int bookedcount=0;
	printf("                                                  Online Bus Booking System\n");
	while (bookedcount<5) {
	printf("Enter seat no. (0-9):");
	scanf(" %d", &seatno);
	if (seatno < 0 || seatno > 9) {
     printf("? Invalid seat number! Please enter between 0 and 9.\n");
            continue;
        }
	if (seats[seatno]==1) {
	 printf("\nSeat Already Booked!\n");	
	}
	else {
		seats[seatno]=1;
		bookedcount++;
		printf("seat no. %d is now booked successfully!", seatno);
	}
	printf("\nCurrent Seat Status:\n");
        for (int i = 0; i < 10; i++) {
    printf("%d ", seats[i]);
        }
    printf("\n");
    }
	printf("\n=== Final Seat Status ===\n");
    for (int i = 0; i < 10; i++) {
        printf("Seat %d: %d\n", i, seats[i]);
    }
    return 0;
}
