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

#ifndef FRONTLIST_AS_A
#define FRONTLIST_AS_A

// Implementation of FrontList using LinkedList (Approach 3: Private Inheritance)
template <typename ItemType>
class FrontListPrivateInheritance : private LinkedList<ItemType>, public FrontListInterface<ItemType> {
public:
    using LinkedList<ItemType>::insert;
    using LinkedList<ItemType>::remove;
    using LinkedList<ItemType>::getEntry;

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