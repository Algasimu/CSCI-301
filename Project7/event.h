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

#ifndef EVENT_H
#define EVENT_H

using namespace std;

/**
 * @brief Class to simulate an arrival or departure event.
 */
class Event {
public:
    char type;  // 'A' for arrival event, 'D' for departure event
    int time;   // The time of the event (arrival or departure)
    int transTime; // Transaction time for the customer

    /**
     * @brief Constructor for Event class.
     * @param eventType The type of the event (arrival or departure)
     * @param eventTime The time of the event (arrival or departure)
     * @param transactionTime The transaction time for the customer
     */
    Event(char eventType, int eventTime, int transactionTime) : type(eventType), time(eventTime), transTime(transactionTime) {}

    // Define comparison operators for priority queue (smallest time has highest priority)
    bool operator>(const Event& other) const {
        return time > other.time;
    }

    bool operator<(const Event& other) const {
        return time < other.time;
    }

    bool operator==(const Event& other) const {
        return time == other.time;
    }

    bool operator!=(const Event& other) const {
        return time != other.time;
    }
};

/**
 * @brief Function to simulate the bank's event-driven simulation.
 * @param inputFile The name of the input file containing arrival and transaction times.
 */
void bankSimulation(const string& inputFile) {
    priority_queue<Event, vector<Event>, greater<Event> > eventQueue; // Priority queue to store events

    int totalTime = 0; // Cumulative waiting time
    int totalCustomers = 0; // Total number of customers

    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        cerr << "Error opening file: " << inputFile << endl;
        return;
    }

    // Read the input file and add arrival events to the event queue
    int arrivalTime, transactionTime;
    while (inFile >> arrivalTime >> transactionTime) {
        eventQueue.push(Event('A', arrivalTime, transactionTime));
    }

    inFile.close();

    // Process the events in the event queue
    while (!eventQueue.empty()) {
        Event currentEvent = eventQueue.top();
        eventQueue.pop();

        if (currentEvent.type == 'A') {
            // Arrival event
            cout << "Processing an arrival event at time: " << currentEvent.time << endl;

            // Add the customer's transaction time to the total waiting time
            totalTime += currentEvent.transTime;

            // Increment the total number of customers
            totalCustomers++;

            // Create the corresponding departure event and add it to the event queue
            eventQueue.push(Event('D', currentEvent.time + currentEvent.transTime, 0));
        } else {
            // Departure event
            cout << "Processing a departure event at time: " << currentEvent.time << endl;
        }
    }

    // Compute the average waiting time
    double averageWaitingTime = static_cast<double>(totalTime) / totalCustomers;

    // Display the final statistics
    cout << "Simulation ends." << endl;
    cout << "Final Statistics:" << endl;
    cout << "Total number of customers processed: " << totalCustomers << endl;
    cout << "Average amount of time spent waiting: " << averageWaitingTime << endl;
}
#endif