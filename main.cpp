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
// fixed getIntInput to validate user input and prevent invalid integers from crashing the program
int getIntInput(string prompt) {
    int val;
    cout << prompt;
    while(!(cin >> val)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Try again: ";
    }
    cin.ignore(1000, '\n');
    return val;
}
// fixed getDoubleInput to validate user input and prevent invalid doubles from causing errors
double getDoubleInput(string prompt) {
    double val;
    cout << prompt;
    while(!(cin >> val)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Try again: ";
    }
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
// displays each cars details and its maintenance history
void displayCarSummary() {
    for(int i=0; i<carCount; i++) {
        cout << "\nCar: " << cars[i].make << " " << cars[i].model << "\n";
        cout << "Year: " << cars[i].year << ", Mileage: " << cars[i].mileage << "\n";
        cout << "Fuel Eff: " << cars[i].fuelEfficiency << ", Top Speed: " << cars[i].topSpeed << "\n";
        cout << "Maintenance Records:\n";
        for(int j=0; j<cars[i].numMaint; j++) {
            cout << j+1 << ". " << cars[i].maints[j].type << " - " << cars[i].maints[j].date << " $" << cars[i].maints[j].cost << "\n";
        }
    }
}
// sorts all cars by year in ascending order
void sortCarsByYear() {
    for(int i=0; i<carCount-1; i++) {
        for(int j=i+1; j<carCount; j++) {
            if(cars[i].year > cars[j].year) {
                Car temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
            }
        }
    }
    cout << "Cars sorted by year.\n";
}
// sorts all cars by mileage in ascending order
void sortCarsByMileage() {
    for(int i=0; i<carCount-1; i++) {
        for(int j=i+1; j<carCount-2; j++) { 
            if(cars[i].mileage > cars[j].mileage) {
                Car temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
            }
        }
    }
    cout << "Cars sorted by mileage.\n";
}
// saves car details to an external file for later retrieval
void saveData() {
    ofstream carFile("cars.txt");
    for(int i=0; i<carCount; i++) {
        carFile << cars[i].make << "," << cars[i].model << "," << cars[i].year << ",";
        carFile << cars[i].mileage << "," << cars[i].fuelEfficiency << "," << cars[i].topSpeed << "\n";
    }
    carFile.close();
    cout << "Data saved to file.\n";
}
// loads car details from file into the program for use at runtime
void loadData() {
    ifstream carFile("cars.txt");
    if(!carFile) return;

    carCount = 0;
    while(!carFile.eof() && carCount < MAX_CARS) {
        Car c;
        string line;
        if(!getline(carFile, line)) break;
        sscanf(line.c_str(), "%[^,],%[^,],%d,%lf,%lf,%lf",
               &c.make[0], &c.model[0], &c.year, &c.mileage, &c.fuelEfficiency, &c.topSpeed);
        cars[carCount++] = c;
    }
    carFile.close();
}








