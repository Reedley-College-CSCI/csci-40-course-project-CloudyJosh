// CSCI-40 Final Project
// Author: [Joshua Montoya]

/* 
 * Description: Car Maintenance and Performance Tracker.
   A C++ program that lets users store car details, log maintenance records, and track performance statistics.
   Features include adding, searching, and sorting cars, logging maintenance events with dates and costs, 
   displaying organized summaries, and saving/loading data to ensure persistence between program runs.
   Designed to help car owners stay organized and monitor car performance over time.
 *
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// maximum number of cars and maintenance records
const int MAX_CARS = 50;
const int MAX_MAINT = 100;

// structs
struct Maintenance {
    string type;
    string date;
    double cost;
};
struct Car {
    string make;
    string model;
    int year;
    double mileage;
    double fuelEfficiency;
    double topSpeed;
    int numMaint;
    Maintenance maints[10];
};
// global arrays
Car cars[MAX_CARS];
int carCount = 0;

// Function declarations
void loadData();
void saveData();
void addCar();
void addMaintenance();
void displayCarSummary();
int searchCar(string make, string model);
void sortCarsByYear();
void sortCarsByMileage();
void showMenu();
int getIntInput(string prompt);
double getDoubleInput(string prompt);
string getStringInput(string prompt);

// main
int main() {
    loadData();

    int choice;
    do {
        showMenu();
        choice = getIntInput("Enter your choice: ");
        switch(choice) {
            case 1: addCar(); break;
            case 2: addMaintenance(); break;
            case 3: displayCarSummary(); break;
            case 4: sortCarsByYear(); break;
            case 5: sortCarsByMileage(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 6);

    saveData();
    return 0;
}
// function implementations 
void showMenu(){
   cout <<"\nCar Maintenance Tracker Menu\n";
cout << "1. Add Car\n";
    cout << "2. Log Maintenance\n";
    cout << "3. Display Car Summary\n";
    cout << "4. Sort Cars by Year\n";
    cout << "5. Sort Cars by Mileage\n";
    cout << "6. Exit\n";
}
int getIntInput(string prompt) {
    int val;
    cout << prompt;
    cin >> val;
    cin.ignore(1000, '\n'); 
    return val;
}
double getDoubleInput(string prompt) {
    double val;
    cout << prompt;
    cin >> val;
    cin.ignore(1000, '\n'); 
    return val;
}
string getStringInput(string prompt) {
    string val;
    cout << prompt;
    getline(cin, val);
    return val;
}
string getStringInput(string prompt) {
   string val;
   cout << prompt;
   getline(cin,val);
   return val;
}
void addCar(){
   if(carCount >= MAX_CARS){
      cout << "Car limit reached.\n";
      return;
}
Car c;
    c.make = getStringInput("Enter car make: ");
    c.model = getStringInput("Enter car model: ");
    c.year = getIntInput("Enter car year: ");
    c.mileage = getDoubleInput("Enter mileage: ");
    c.fuelEfficiency = getDoubleInput("Enter fuel efficiency: ");
    c.topSpeed = getDoubleInput("Enter top speed: ");
    cars[carCount++] = c;
    cout << "Car added successfully.\n";
}
int searchCar(string make, string model) {
    for(int i=0; i<carCount; i++) {
        if(cars[i].make == make)   
            return i;
    }
    return -1;
}
// logs a maintenance record for a selected car and updates its maintenance list
void addMaintenance() {
    string make = getStringInput("Enter car make: ");
    string model = getStringInput("Enter car model: ");
    int idx = searchCar(make, model);
    if(idx == -1) {
        cout << "Car not found.\n";
        return;
    }
    if(cars[idx].numMaint >= 10) {
        cout << "Maintenance limit reached for this car.\n";
        return;
    }
    Maintenance m;
    m.type = getStringInput("Enter maintenance type: ");
    m.date = getStringInput("Enter maintenance date: ");
    m.cost = getDoubleInput("Enter cost: ");
    cars[idx].maints[cars[idx].numMaint++] = m;
    cout << "Maintenance logged.\n";
}





