/**
 * problem description: Implement an event-driven similation of a bank maintaining the arrival 
 * events and the departure events.
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/26/2023
*/

#include <iostream>
#include <fstream>
#include <queue>
#include "event.h"

int main() {
     
     string fileName;
    cout << "Enter the name of the file: ";
    cin >> fileName;

    // Call the bankSimulation function with the input file name
    bankSimulation(fileName);
    return 0;
}
