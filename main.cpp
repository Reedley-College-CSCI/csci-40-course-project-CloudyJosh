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


