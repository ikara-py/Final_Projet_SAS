#include "airport.h"
#include <stdio.h>

int main() {
    newAirport.count = 0;
    newAirport.total_airplanes = 0;
    newAirport.aviable = 0;
    newAirport.under_maintenance = 0;
    newAirport.in_flight = 0;
    newAirport.id_counter = 0;
    strcpy(newAirport.name, "Default Airport");
    newAirport.max_capacity = MAX_AIRPLANES;
    int choice;
    do {     //main menu loop
        Menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        UserChoice(choice);
    } while (choice != 0);

    return 0;
}

