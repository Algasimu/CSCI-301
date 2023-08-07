/**
 * problem description: Write a program that maintains a database 
 * containing person’s name and birthday
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 08/01/2023
*/

#ifndef PEOPLEDB_H
#define PEOPLEDB_H

#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

/**
 * @class PeopleDB
 * @brief Represents a database of people and their information.
 */
class PeopleDB {
private:
    BinarySearchTree<Person> db; /**< Binary search tree to store people data. */

public:
    /**
     * @brief Constructs a PeopleDB object and loads data from a file.
     * @param filename The name of the file containing initial people list.
     */
    PeopleDB(string filename) {
        ifstream file(filename);
        if (file.is_open()) {
            Person person;
            while (file >> person) {
                db.insert(person);
            }
            file.close();
        } else {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }

    /**
     * @brief Adds a new person to the database.
     * @param person The person to be added.
     */
    void addPerson(Person person) {
        db.insert(person);
    }

    /**
     * @brief Removes a person from the database.
     * @param person The person to be removed.
     */
    void removePerson(Person person) {
        db.remove(person);
    }

    /**
     * @brief Modifies a person's information in the database.
     * @param oldPerson The person to be modified.
     * @param newPerson The updated information for the person.
     */
    void modifyPerson(Person oldPerson, Person newPerson) {
        db.remove(oldPerson);
        db.insert(newPerson);
    }

    /**
     * @brief Searches for a person in the database.
     * @param person The person to search for.
     * @return True if the person is found, false otherwise.
     */
    bool searchPerson(Person person) {
        return db.contains(person);
    }

    /**
     * @brief Displays the database in its original order.
     */
    void displayOriginalOrder() const {
        db.traverseInorder([](const Person& person) {
            cout << person << endl;
        });
    }

    /**
     * @brief Displays the database sorted by names.
     */
    void displaySortedOrder() const {
        db.traverseInorder([](const Person& person) {
            cout << person << endl;
        });
    }

    /**
     * @brief Saves the database to a file.
     * @param filename The name of the file to save the data.
     */
    void saveToFile(string filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            db.traverseInorder([&](const Person& person) {
                file << person << endl;
            });
            file.close();
        } else {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }
};

#endif
