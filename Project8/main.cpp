/**
 * problem description: Write a program that maintains a database 
 * containing person’s name and birthday
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 08/01/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Person.h"
#include "PeopleDB.h"
#include "BinarySearchTree.h"

using namespace std;

/** Main program */
int main() {
    cout << "Welcome to xxx database system. Please enter the file that contains the initial people list: ";
    string inputFileName;
    cin >> inputFileName;
    PeopleDB peopleDB(inputFileName);

    cout << "The initial database built from the input file is displayed by its original order:\n";
    peopleDB.displayOriginalOrder();

    int choice = 0;
    while (choice != 7) {
        cout << "Please enter your option\n"
             << "1. Add a new person\n"
             << "2. Remove a person\n"
             << "3. Modify the database\n"
             << "4. Search for a person in the database\n"
             << "5. Display the database\n"
             << "6. Display the database sorted by names\n"
             << "7. Quit and save the database to a file\n"
             << "-->";
        cin >> choice;
    
        switch (choice) {
            case 1: {
                Person person;
                cout << "To add, enter name and birthday (month day year):\n";
                cin >> person;
                peopleDB.addPerson(person);
                char addAnother;
                cout << "Add another one? ";
                cin >> addAnother;
                while (tolower(addAnother) == 'y') {
                    cout << "Enter name and birthday (month day year):\n";
                    cin >> person;
                    peopleDB.addPerson(person);
                    cout << "Add another one? ";
                    cin >> addAnother;
                }
                break;
            }
            case 2: {
                Person person;
                string name;
                cout << "Enter name to remove: ";
                cin >> name;
                person.setName(name);
                if (peopleDB.searchPerson(person)) {
                    peopleDB.removePerson(person);
                    cout << "Person removed.\n";
                } else {
                    cout << "Person not found.\n";
                }
                break;
            }
            case 3: {
                Person oldPerson, newPerson;
                string name;
                cout << "Enter name to modify: ";
                cin >> name;
                oldPerson.setName(name);
                if (peopleDB.searchPerson(oldPerson)) {
                    cout << "Enter new name and birthday (month day year): ";
                    cin >> newPerson;
                    peopleDB.modifyPerson(oldPerson, newPerson);
                    cout << "Person modified.\n";
                } else {
                    cout << "Person not found.\n";
                }
                break;
            }
            case 4: {
                Person person;
                string name;
                cout << "Enter name to search: ";
                cin >> name;
                person.setName(name);
                if (peopleDB.searchPerson(person)) {
                    cout << "Person found.\n";
                } else {
                    cout << "Person not found.\n";
                }
                break;
            }
            case 5: {
                cout << "Displaying the database:\n";
                peopleDB.displayOriginalOrder();
                break;
            }
            case 6: {
                cout << "Displaying the database sorted by names:\n";
                peopleDB.displaySortedOrder();
                break;
            }
            case 7: {
                cout << "Exiting and saving the database...\n";
                peopleDB.saveToFile(inputFileName);
                break;
            }
            default: {
                cout << "Invalid choice.\n";
                break;
            }
        }
    
    }

    return 0;
}
