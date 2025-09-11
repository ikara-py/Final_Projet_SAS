#include <stdio.h>
#include <string.h>

#define MAX_AIRPLANES 200
#define inner_string_size 50
extern int count;
extern int total_airplanes;
extern int aviable;
extern int under_maintenance;
extern int in_flight;

int count = 0;
int total_airplanes = 0;
int aviable = 0;
int under_maintenance = 0;
int in_flight = 0;

typedef struct {
    char modele[50];
    int id;
    int capacite;
    char statut[20];
} airplanes;
airplanes newairplan[100];

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

int main() {
    int choice;
    do {
        Menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
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
    printf("\n Airplane Management\n");
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
            printf("Airport Information\n");
            break;
        case 3:
            printf("Park Occupancy Calculation\n");
            break;
        case 4:
            printf("Statistics\n");
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
    if (count >= 100) {
        printf("\nNo space available.\n");
        return;
    }
    printf("\nAirplane id is #%d\n", count + 1);
    newairplan[count].id = count + 1;
    while (getchar() != '\n');
    printf("Enter the modele of the plane: ");
    fgets(newairplan[count].modele, inner_string_size, stdin);
    newairplan[count].modele[strcspn(newairplan[count].modele, "\n")] = 0;
    printf("Enter the capacite: ");
    scanf("%d", &newairplan[count].capacite);
    while (getchar() != '\n');
    aviability();
    printf("Enter the statut: ");
    scanf("%d", &choice);
    if(choice == 1){
        strcpy(newairplan[count].statut, "Available");
        aviable++;
    }
    else if(choice == 2){
        strcpy(newairplan[count].statut, "Under maintenance");
        under_maintenance++;
    }
    else if (choice == 3){
        strcpy(newairplan[count].statut, "In flight");
        in_flight++;
    }
    
    // fgets(newairplan[count].statut, inner_string_size, stdin);
    // newairplan[count].statut[strcspn(newairplan[count].statut, "\n")] = 0;
    

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
        printf("\nairplane #%d\n", i + 1);
        printf("ID: %d\n", newairplan[i].id);
        printf("Modele: %s\n", newairplan[i].modele);
        printf("Statut: %s\n", newairplan[i].statut);
        printf("Capacite: %d\n", newairplan[i].capacite);
    }
}

void deletAirplanes() {
    int search_id;
    int found = 0;
    printf("Enter the ID to delete: ");
    scanf("%d", &search_id);
    for (int i = 0; i < count; i++) {
        if (newairplan[i].id == search_id) {
            for (int j = i; j < count - 1; j++) {
                newairplan[j] = newairplan[j + 1];
            }
            printf("Airplane with ID %d deleted successfully.\n", search_id);
            found = 1;
            total_airplanes--;
            break;
        }
    }
    if (!found) {
        printf("There is no airplane with that id %d\n", search_id);
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
    int found = 0;
    printf("Enter the ID: ");
    scanf("%d", &search_id);
    while (getchar() != '\n');
    for (int i = 0; i < count; i++) {
        if (newairplan[i].id == search_id) {
            char new_modele[50];
            printf("Enter the new modele: ");
            fgets(new_modele, 50, stdin);
            new_modele[strcspn(new_modele, "\n")] = 0;
            strcpy(newairplan[i].modele, new_modele);
            found = 1;
            printf("\nUpdated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("There is no airplane with that id %d\n", search_id);
    }
}

void update_statut() {
    int search_id;
    int found = 0;
    printf("Enter the ID: ");
    scanf("%d", &search_id);
    while (getchar() != '\n');
    for (int i = 0; i < count; i++) {
        if (newairplan[i].id == search_id) {
            int choice = 0;
            aviability();
            printf("Enter your choice: ");
            scanf("%d", &choice);
            if (choice == 1) {
                strcpy(newairplan[i].statut, "Available");
                aviable++;
            } else if (choice == 2) {
                strcpy(newairplan[i].statut, "under maintenance");
                under_maintenance++;
            } else if (choice == 3) {
                strcpy(newairplan[i].statut, "in flight");
                in_flight++;
            }
            found = 1;
            printf("\nUpdated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("There is no airplane with that id %d\n", search_id);
    }
}

void update_capacity() {
    int search_id;
    int found = 0;
    printf("Enter the ID: ");
    scanf("%d", &search_id);
    for (int i = 0; i < count; i++) {
        if (newairplan[i].id == search_id) {
            int new_capacity;
            printf("Enter the new capacity: ");
            scanf("%d", &new_capacity);
            newairplan[i].capacite = new_capacity;
            found = 1;
            printf("\nUpdated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("There is no airplane with that id %d\n", search_id);
    }
}

void aviability() {
    
    printf("1. Available\n");
    printf("2. Under maintenance\n");
    printf("3. In flight\n");
    printf("Enter the statut: ");
}

void statistics(){

    
}