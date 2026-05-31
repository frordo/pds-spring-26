
#include <stdio.h>
#include <stdlib.h>

int main(){
	//getting user input
	int n, choice;
	printf("Enter number of seats: ");
	scanf("%d", &n);
	int *seats = (int *) calloc(0, n*sizeof(int)); //calloc'ing as seats are initially zero (empty)

	while (1){
		//printing menu
		printf("\nMenu:\n1. Display seats\n2. Book a seat\n3. Cancel booking\n4. First available seat\n5. Exit\n\n");

		//getting user choice
		printf("Enter choice: ");
		scanf("%d", &choice);

		if (choice == 1){
			//displaying seats
			printf("Seats: ");
			for (int i = 0; i < n; i++) printf("%d ", seats[i]);
			printf("\n");
		}

		if (choice == 2){
			int seat_no;
			printf("Enter seat number: ");
			scanf("%d", &seat_no);
			seat_no = seat_no - 1; //seats are one-indexed

			//checking if valid seat number
			if (seat_no < 0 || seat_no >= n){
				printf("Invalid seat number\n");
				continue;
			}
			if (seats[seat_no]){
				//checking if seat is already booked
				printf("Seat already booked\n");
			}
			else{
				//updating booking record
				printf("Booking successful\n");
				seats[seat_no] = 1;
			}
		}

		if (choice == 3){
			int seat_no;
			printf("Enter seat number: ");
			scanf("%d", &seat_no);
			seat_no = seat_no - 1; //seats are one-indexed

			//checking valid seat number
			if (seat_no < 0 || seat_no >= n){
				printf("Invalid seat number\n");
				continue;
			}
			if (seats[seat_no]){
				//checking if booked already, updating seating records
				printf("Cancellation successful\n");
				seats[seat_no] = 0;
			}
			else{
				//not booked
				printf("Seat was already empty\n");
			}
		}

		if (choice == 4){
			//finding first zero
			int available = 0;
			for (int i = 0; i < n; i++){
				if (!seats[i]){
					printf("First available seat: %d", i+1); //i+1 as seats are zero-indexed
					available = 1;
					break;
				}
			}
			//if no seats are available
			if (!available)
				printf("No seats are available");
			printf("\n");
			
		}

		if (choice == 5){
			break; //exit if 5
		}
	}
	free (seats); //returning allocated memory
	return 0;
}
