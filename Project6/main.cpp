/**
 * problem description:  Design the following classes: FrontListIsA, FrontListHasA, FrontListAsA.
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/19/2023
*/

#include <iostream>
#include "LinkedList.h"
#include "FrontListAsA.h"
#include "FrontListHasA.h"
#include "FrontListIsA.h"



int main() {
    int choice;
    std::cout << "Choose the FrontList implementation:" << std::endl;
    std::cout << "1. Composition (Approach 1)" << std::endl;
    std::cout << "2. Public Inheritance (Approach 2)" << std::endl;
    std::cout << "3. Private Inheritance (Approach 3)" << std::endl;
    std::cout << "Enter your choice (1, 2, or 3): ";
    std::cin >> choice;

    FrontListInterface<int>* frontList = nullptr;

    switch (choice) {
        case 1:
            frontList = new FrontListComposition<int>();
            break;
        case 2:
            frontList = new FrontListPublicInheritance<int>();
            break;
        case 3:
            frontList = new FrontListPrivateInheritance<int>();
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
    }

    // Test FrontList operations
    int item;
    char continueChoice;

    do {
        std::cout << "Enter an item to insert: ";
        std::cin >> item;

        if (frontList->insert(item)) {
            std::cout << "Item inserted successfully." << std::endl;
        } else {
            std::cout << "Item insertion failed." << std::endl;
        }

        std::cout << "Front item: " << frontList->retrieve() << std::endl;

        if (frontList->remove()) {
            std::cout << "Item removed successfully." << std::endl;
        } else {
            std::cout << "Item removal failed." << std::endl;
        }

        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> continueChoice;
    } while (continueChoice == 'y' || continueChoice == 'Y');

    delete frontList; // Clean up memory

    return 0;
}
