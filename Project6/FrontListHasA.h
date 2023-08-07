
/**
 * problem description:  Design the following classes: FrontListIsA, FrontListHasA, FrontListAsA.
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/19/2023
*/

#include <iostream>
#include <stdexcept>
#include "LinkedList.h"// Assuming LinkedList class is defined
#include "FrontListInterface.h"

#ifndef FRONTLIST_HAS_A
#define FRONTLIST_HAS_A

// Implementation of FrontList using LinkedList (Approach 1: Composition)
template <typename ItemType>
class FrontListComposition : public FrontListInterface<ItemType> {
private:
    // Implementation using LinkedList (private member)
    LinkedList<ItemType> list;

public:
    bool insert(const ItemType& newEntry) override {
        // Insert at the front of the list
        return list.insert(1, newEntry);
    }

    bool remove() override {
        // Remove the first item in the list
        return list.remove(1);
    }

    ItemType retrieve() const override {
        // Retrieve the first item in the list
        return list.getEntry(1);
    }
};
#endif
