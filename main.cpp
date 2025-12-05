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

// Maximum number of cars and maintenance records
const int MAX_CARS = 50;
const int MAX_MAINT = 100;

// structs
struct Maintenance {
    string type;
    string date;
    double cost;
};
