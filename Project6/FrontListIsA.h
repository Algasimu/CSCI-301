/**
 * problem description:  Design the following classes: FrontListIsA, FrontListHasA, FrontListAsA.
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/19/2023
*/

#include <iostream>
#include <stdexcept>
#include "LinkedList.h" // Assuming LinkedList class is defined
#include "FrontListInterface.h"
#ifndef FRONTLIST_IS_A
#define FRONTLIST_IS_A

// Implementation of FrontList using LinkedList (Approach 2: Public Inheritance)
template <typename ItemType>
class FrontListPublicInheritance : public LinkedList<ItemType>, public FrontListInterface<ItemType> {
public:
    bool insert(const ItemType& newEntry) override {
        // Insert at the front of the list
        return LinkedList<ItemType>::insert(1, newEntry);
    }

    bool remove() override {
        // Remove the first item in the list
        return LinkedList<ItemType>::remove(1);
    }

    ItemType retrieve() const override {
        // Retrieve the first item in the list
        return LinkedList<ItemType>::getEntry(1);
    }
};
#endif