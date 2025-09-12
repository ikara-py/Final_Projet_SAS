#ifndef AIRPORT_H
# define AIRPORT_H

#include <stdio.h>
#include <string.h>
#include "airport.h"


#define MAX_AIRPLANES 200
#define inner_string_size 50
//functions
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
void searchAirplane();
void changeAirportName();

typedef struct {   //structure for date
    int day;
    int month;
    int year;
} date;

typedef struct {    //structure for airplanes
    date entryDate;
    char modele[50];
    int id;
    int capacite;
    char statut[20];
} airplanes;

typedef struct {    //structure for air port
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


#endif