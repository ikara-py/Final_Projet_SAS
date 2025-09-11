#include <stdio.h>
#include <string.h>

#define MAX_AIRPLANES 200
#define inner_string_size 50

int count = 0;
int total_airplanes = 0;
int aviable = 0;
int under_maintenance = 0;
int in_flight = 0;
int id_counter = 0;

typedef struct {
    char modele[50];
    int id;
    int capacite;
    char statut[20];
} airplanes;
airplanes newairplan[MAX_AIRPLANES];

typedef struct {
    char name[50];
    airplanes flotte[MAX_AIRPLANES];
    int nbairplanes;
} airport;

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

int main() {
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
    printf("4. Delete Airplane\n");
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
            printf("nothing!!!!!!!!!!.\n");
            break;
        case 3:
            printf("Nothing!!!!!!!!!.\n");
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
    if (count >= MAX_AIRPLANES) {
        printf("\nNo space available. Maximum capacity reached.\n");
        return;
    }
    
    id_counter++;
    newairplan[count].id = id_counter;
    printf("\nAirplane id is #%d\n", newairplan[count].id);
    
    printf("Enter the modele of the plane: ");
    fgets(newairplan[count].modele, inner_string_size, stdin);
    newairplan[count].modele[strcspn(newairplan[count].modele, "\n")] = 0;

    printf("Enter the capacite: ");
    scanf("%d", &newairplan[count].capacite);
    while (getchar() != '\n');

    aviability();
    scanf("%d", &choice);
    while (getchar() != '\n');

    if (choice == 1) {
        strcpy(newairplan[count].statut, "Available");
        aviable++;
    } else if (choice == 2) {
        strcpy(newairplan[count].statut, "Under maintenance");
        under_maintenance++;
    } else if (choice == 3) {
        strcpy(newairplan[count].statut, "In flight");
        in_flight++;
    } else {
        printf("Invalid choice. Setting it to 'Unknown'.\n");
        strcpy(newairplan[count].statut, "Unknown");
    }

    printf("\nAdded successfully!\n");
    count++;
    total_airplanes++;
}

void viewAirplanes() {
    if (count == 0) {
        printf("\nNo Airplanes available.\n");
        return;
    }
    printf("\nAvailable airplanes\n");
    for (int i = 0; i < count; i++) {
        printf("airplane #%d\n", i + 1);
        printf("ID: %d\n", newairplan[i].id);
        printf("Modele: %s\n", newairplan[i].modele);
        printf("Statut: %s\n", newairplan[i].statut);
        printf("Capacite: %d\n", newairplan[i].capacite);
    }
}

void deletAirplanes() {
    int search_id;
    int found_index = -1;
    if (count == 0) {
        printf("No airplanes to delete.\n");
        return;
    }
    printf("Enter the ID to delete: ");
    scanf("%d", &search_id);
    while (getchar() != '\n');

    for (int i = 0; i < count; i++) {
        if (newairplan[i].id == search_id) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        if (strcmp(newairplan[found_index].statut, "Available") == 0) {
            aviable--;
        } else if (strcmp(newairplan[found_index].statut, "Under maintenance") == 0) {
            under_maintenance--;
        } else if (strcmp(newairplan[found_index].statut, "In flight") == 0) {
            in_flight--;
        }

        for (int j = found_index; j < count - 1; j++) {
            newairplan[j] = newairplan[j + 1];
        }
        count--;
        total_airplanes--;
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
    
    for (int i = 0; i < count; i++) {
        if (newairplan[i].id == search_id) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        char new_modele[50];
        printf("Enter the new modele: ");
        fgets(new_modele, 50, stdin);
        new_modele[strcspn(new_modele, "\n")] = 0;
        strcpy(newairplan[found_index].modele, new_modele);
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
    
    for (int i = 0; i < count; i++) {
        if (newairplan[i].id == search_id) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        int choice = 0;
        char old_statut[20];
        strcpy(old_statut, newairplan[found_index].statut);
        
        aviability();
        scanf("%d", &choice);
        while (getchar() != '\n');

        if (choice == 1) {
            strcpy(newairplan[found_index].statut, "Available");
            if (strcmp(old_statut, "Under maintenance") == 0) under_maintenance--;
            else if (strcmp(old_statut, "In flight") == 0) in_flight--;
            aviable++;
        } else if (choice == 2) {
            strcpy(newairplan[found_index].statut, "Under maintenance");
            if (strcmp(old_statut, "Available") == 0) aviable--;
            else if (strcmp(old_statut, "In flight") == 0) in_flight--;
            under_maintenance++;
        } else if (choice == 3) {
            strcpy(newairplan[found_index].statut, "In flight");
            if (strcmp(old_statut, "Available") == 0) aviable--;
            else if (strcmp(old_statut, "Under maintenance") == 0) under_maintenance--;
            in_flight++;
        } else {
            printf("Invalid choice. Status not updated.\n");
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
    
    for (int i = 0; i < count; i++) {
        if (newairplan[i].id == search_id) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        int new_capacity;
        printf("Enter the new capacity: ");
        scanf("%d", &new_capacity);
        while (getchar() != '\n');
        newairplan[found_index].capacite = new_capacity;
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
    printf("Total Airplanes: %d\n", total_airplanes);
    printf("Available: %d\n", aviable);
    printf("Under Maintenance: %d\n", under_maintenance);
    printf("In Flight: %d\n", in_flight);
}

void sort(){
    
}