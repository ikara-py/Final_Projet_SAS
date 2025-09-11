#include <stdio.h>
#include <string.h>

#define MAX_AIRPLANES 200
#define inner_string_size 50

typedef struct {
    int day;
    int month;
    int year;
} date;

typedef struct {
    date entryDate;
    char modele[50];
    int id;
    int capacite;
    char statut[20];
} airplanes;

typedef struct {
    char name[100];
    int max_capacity;
    int count;
    int total_airplanes;
    int aviable;
    int under_maintenance;
    int in_flight;
    int id_counter;
    airplanes newairplan[MAX_AIRPLANES];
} airport;
airport newAirport;

void Menu();
void UserChoice(int choice);
void AirplaneMenu();
void addAirplane();
void viewAirplanes();
void deletAirplanes();
void update_Airplane();
void update_statut();
void update_capacity();
void aviability();
void update_modele();
void statistics();
void sort();
double Fleet_Occupancy();
void airPort();

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
    do {
        Menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        UserChoice(choice);
    } while (choice != 0);

    return 0;
}

void Menu() {
    printf("\nAirport Management System\n");
    printf("1. Airplane Management\n");
    printf("2. Airport Information\n");
    printf("3. Park Occupancy Calculation\n");
    printf("4. Statistics\n");
    printf("0. Exit\n");
}

void AirplaneMenu() {
    printf("\nAirplane Management\n");
    printf("1. Add New Airplane\n");
    printf("2. View All Airplanes\n");
    printf("3. Update Airplane\n");
    printf("4. Sort airplanes\n");
    printf("5. Delete Airplane\n");
    printf("0. Back to Main Menu\n");
}

void UserChoice(int choice) {
    int airplaneChoice;
    switch (choice) {
        case 1:
            do {
                AirplaneMenu();
                printf("Enter your choice for Airplane Management: ");
                scanf("%d", &airplaneChoice);
                while (getchar() != '\n');
                switch (airplaneChoice) {
                    case 1:
                        printf("\nAdding a new airplane\n");
                        addAirplane();
                        break;
                    case 2:
                        printf("Viewing all airplanes\n");
                        viewAirplanes();
                        break;
                    case 3:
                        update_Airplane();
                        break;
                    case 4:
                        sort();
                        break;
                    case 5:
                        printf("Deleting an airplane\n");
                        deletAirplanes();
                        break;
                    case 0:
                        printf("Returning to main menu\n");
                        break;
                    default:
                        printf("Invalid choice for Airplane Management. Please try again.\n");
                        break;
                }
            } while (airplaneChoice != 0);
            break;
        case 2:
            printf("Airport Name: %s\n", newAirport.name);
            printf("Max Capacity: %d\n", newAirport.max_capacity);
            break;
        case 3:
            printf("Fleet Occupancy Coefficient: %.2f%%\n", Fleet_Occupancy());
            break;
        case 4:
            statistics();
            break;
        case 0:
            printf("Exiting application. Thank you!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

void addAirplane() {
    int choice;
    if (newAirport.count >= newAirport.max_capacity) {
        printf("\nNo space available. Maximum capacity reached.\n");
        return;
    }

    newAirport.id_counter++;
    newAirport.newairplan[newAirport.count].id = newAirport.id_counter;
    printf("\nAirplane id is #%d\n", newAirport.newairplan[newAirport.count].id);
    
    printf("\nEnter the entry date\n");
    printf("\nEnter the day : ");
    scanf("%d", &newAirport.newairplan[newAirport.count].entryDate.day);
    printf("\nEnter the month : ");
    scanf("%d", &newAirport.newairplan[newAirport.count].entryDate.month);
    printf("\nEnter the year : ");
    scanf("%d", &newAirport.newairplan[newAirport.count].entryDate.year);
    while (getchar() != '\n');
    printf("Enter the modele of the plane: ");
    fgets(newAirport.newairplan[newAirport.count].modele, inner_string_size, stdin);
    newAirport.newairplan[newAirport.count].modele[strcspn(newAirport.newairplan[newAirport.count].modele, "\n")] = 0;

    printf("Enter the capacite: ");
    scanf("%d", &newAirport.newairplan[newAirport.count].capacite);
    while (getchar() != '\n');

    aviability();
    scanf("%d", &choice);
    while (getchar() != '\n');

    if (choice == 1) {
        strcpy(newAirport.newairplan[newAirport.count].statut, "Available");
        newAirport.aviable++;
    } else if (choice == 2) {
        strcpy(newAirport.newairplan[newAirport.count].statut, "Under maintenance");
        newAirport.under_maintenance++;
    } else if (choice == 3) {
        strcpy(newAirport.newairplan[newAirport.count].statut, "In flight");
        newAirport.in_flight++;
    } else {
        printf("Invalid choice. Setting it to 'Unknown'.\n");
        strcpy(newAirport.newairplan[newAirport.count].statut, "Unknown");
    }

    printf("\nAdded successfully!\n");
    newAirport.count++;
    newAirport.total_airplanes++;
}

void viewAirplanes() {
    if (newAirport.count == 0) {
        printf("\nNo Airplanes available.\n");
        return;
    }
    printf("\nAvailable airplanes\n");
    for (int i = 0; i < newAirport.count; i++) {
        printf("airplane #%d\n", i + 1);
        printf("ID: %d\n", newAirport.newairplan[i].id);
        printf("Date of entry: %d-%d-%d\n", newAirport.newairplan[i].entryDate.day, newAirport.newairplan[i].entryDate.month, newAirport.newairplan[i].entryDate.year);
        printf("Modele: %s\n", newAirport.newairplan[i].modele);
        printf("Statut: %s\n", newAirport.newairplan[i].statut);
        printf("Capacite: %d\n", newAirport.newairplan[i].capacite);
        printf("\n");
    }
}

void deletAirplanes() {
    int search_id;
    int found_index = -1;
    if (newAirport.count == 0) {
        printf("No airplanes to delete.\n");
        return;
    }
    printf("Enter the ID to delete: ");
    scanf("%d", &search_id);
    while (getchar() != '\n');

    for (int i = 0; i < newAirport.count; i++) {
        if (newAirport.newairplan[i].id == search_id) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        if (strcmp(newAirport.newairplan[found_index].statut, "Available") == 0) {
            newAirport.aviable--;
        } else if (strcmp(newAirport.newairplan[found_index].statut, "Under maintenance") == 0) {
            newAirport.under_maintenance--;
        } else if (strcmp(newAirport.newairplan[found_index].statut, "In flight") == 0) {
            newAirport.in_flight--;
        }

        for (int j = found_index; j < newAirport.count - 1; j++) {
            newAirport.newairplan[j] = newAirport.newairplan[j + 1];
        }
        newAirport.count--;
        newAirport.total_airplanes--;
        printf("Airplane with ID %d deleted successfully.\n", search_id);
    } else {
        printf("There is no airplane with that ID %d\n", search_id);
    }
}

void update_Airplane() {
    int update_choice;
    printf("\nUpdate Airplane Menu\n");
    printf("1. Update the modele\n");
    printf("2. Update the capacity\n");
    printf("3. Update status\n");
    printf("0. Back\n");
    printf("Enter your choice: ");
    scanf("%d", &update_choice);
    while (getchar() != '\n');
    switch (update_choice) {
        case 1:
            update_modele();
            break;
        case 2:
            update_capacity();
            break;
        case 3:
            update_statut();
            break;
        case 0:
            return;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void update_modele() {
    int search_id;
    int found_index = -1;
    printf("Enter the ID: ");
    scanf("%d", &search_id);
    while (getchar() != '\n');

    for (int i = 0; i < newAirport.count; i++) {
        if (newAirport.newairplan[i].id == search_id) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        char new_modele[50];
        printf("Enter the new modele: ");
        fgets(new_modele, 50, stdin);
        new_modele[strcspn(new_modele, "\n")] = 0;
        strcpy(newAirport.newairplan[found_index].modele, new_modele);
        printf("\nUpdated successfully!\n");
    } else {
        printf("There is no airplane with that ID %d\n", search_id);
    }
}

void update_statut() {
    int search_id;
    int found_index = -1;
    printf("Enter the ID: ");
    scanf("%d", &search_id);
    while (getchar() != '\n');

    for (int i = 0; i < newAirport.count; i++) {
        if (newAirport.newairplan[i].id == search_id) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        int choice = 0;
        char old_statut[20];
        strcpy(old_statut, newAirport.newairplan[found_index].statut);
        
        aviability();
        scanf("%d", &choice);
        while (getchar() != '\n');

        if (strcmp(old_statut, "Available") == 0) newAirport.aviable--;
        else if (strcmp(old_statut, "Under maintenance") == 0) newAirport.under_maintenance--;
        else if (strcmp(old_statut, "In flight") == 0) newAirport.in_flight--;

        if (choice == 1) {
            strcpy(newAirport.newairplan[found_index].statut, "Available");
            newAirport.aviable++;
        } else if (choice == 2) {
            strcpy(newAirport.newairplan[found_index].statut, "Under maintenance");
            newAirport.under_maintenance++;
        } else if (choice == 3) {
            strcpy(newAirport.newairplan[found_index].statut, "In flight");
            newAirport.in_flight++;
        } else {
            printf("Invalid choice. Status not updated.\n");
            strcpy(newAirport.newairplan[found_index].statut, old_statut); 
            if (strcmp(old_statut, "Available") == 0) newAirport.aviable++;
            else if (strcmp(old_statut, "Under maintenance") == 0) newAirport.under_maintenance++;
            else if (strcmp(old_statut, "In flight") == 0) newAirport.in_flight++;
        }
        printf("\nUpdated successfully!\n");
    } else {
        printf("There is no airplane with that ID : %d\n", search_id);
    }
}

void update_capacity() {
    int search_id;
    int found_index = -1;
    printf("Enter the ID: ");
    scanf("%d", &search_id);
    while (getchar() != '\n');
    for (int i = 0; i < newAirport.count; i++) {
        if (newAirport.newairplan[i].id == search_id) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        int new_capacity;
        printf("Enter the new capacity: ");
        scanf("%d", &new_capacity);
        while (getchar() != '\n');
        newAirport.newairplan[found_index].capacite = new_capacity;
        printf("\nUpdated successfully!\n");
    } else {
        printf("There is no airplane with that ID %d\n", search_id);
    }
}

void aviability() {
    printf("\nSelect the new status:\n");
    printf("1. Available\n");
    printf("2. Under maintenance\n");
    printf("3. In flight\n");
    printf("Enter your choice: ");
}

void statistics() {
    printf("\n Airport Statistics \n");
    printf("Total Airplanes: %d\n", newAirport.total_airplanes);
    printf("Available: %d\n", newAirport.aviable);
    printf("Under Maintenance: %d\n", newAirport.under_maintenance);
    printf("In Flight: %d\n", newAirport.in_flight);
    int total_fleet_capcity = 0;
    for(int i = 0; i < newAirport.count; i++){
        total_fleet_capcity = total_fleet_capcity + newAirport.newairplan[i].capacite;
    }
    printf("Total fleet capacity is %d.\n", total_fleet_capcity);
}

void sort() {
    int tempChoice;
    printf(" 1. sort by capacity \n");
    printf(" 2. sort alphabiticly \n");
    scanf("%d", &tempChoice);
    while (getchar() != '\n'); 
    
    if (tempChoice == 1) {
        airplanes swap;
        for (int i = 0; i < newAirport.count - 1; i++) {
            for (int j = 0; j < newAirport.count - 1 - i; j++) {
                if (newAirport.newairplan[j].capacite > newAirport.newairplan[j + 1].capacite) {
                    swap = newAirport.newairplan[j];
                    newAirport.newairplan[j] = newAirport.newairplan[j + 1];
                    newAirport.newairplan[j + 1] = swap;
                }
            }
        }
        printf("\nAirplanes sorted by capacity.\n");
    } else if (tempChoice == 2) {
        airplanes swap_alpha;
        for (int i = 0; i < newAirport.count - 1; i++) {
            for (int j = 0; j < newAirport.count - 1 - i; j++) {
                if (strcmp(newAirport.newairplan[j].modele, newAirport.newairplan[j + 1].modele) > 0) {
                    swap_alpha = newAirport.newairplan[j];
                    newAirport.newairplan[j] = newAirport.newairplan[j + 1];
                    newAirport.newairplan[j + 1] = swap_alpha;
                }
            }
        }
        printf("\nAirplanes sorted alphabetically by modele.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

void airPort(){
    int choice3;
    printf("\n 1. Calculate Fleet Occupancy Coefficient \n");
    printf(" 2. Add a new aircraft to the fleet \n");
    printf(" 3. Update an aircraft's status \n");
    printf(" 4. Display the status of all aircraft \n");
    printf("Enter your choice: ");
    scanf("%d", &choice3);
    while (getchar() != '\n');
    switch (choice3) {
        case 1:
            printf("Fleet Occupancy Coefficient: %.2f%%\n", Fleet_Occupancy());
            break;
        case 2:
            addAirplane();
            break;
        case 3:
            update_statut();
            break;
        case 4:
            if (newAirport.count == 0) {
                printf("No airplanes to display.\n");
                break;
            }
            for (int i = 0; i < newAirport.count; i++) {
                printf("airplane #%d\n", i + 1);
                printf("Modele: %s\n", newAirport.newairplan[i].modele);
                printf("Statut: %s\n", newAirport.newairplan[i].statut);
                printf("\n");
            }
            break;
        case 0:
            return;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

double Fleet_Occupancy() {
    if (newAirport.total_airplanes == 0) {
        printf("Total of airplanes is zero.\n");
        return 0;
    }
    double occupancy_co = ((double)newAirport.aviable / newAirport.total_airplanes) * 100;
    return occupancy_co;
}