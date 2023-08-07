/**
 * problem description:  Design the following classes: FrontListIsA, FrontListHasA, FrontListAsA.
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/19/2023
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename ItemType>
class LinkedList {
private:
    struct Node {
        ItemType data;
        Node* next;

        Node(const ItemType& item) : data(item), next(nullptr) {}
    };

    Node* head; // Pointer to the head of the linked list
    int itemCount; // Number of items in the linked list

public:
    // Default constructor
    LinkedList();

    // Copy constructor
    LinkedList(const LinkedList<ItemType>& otherList);

    // Destructor
    ~LinkedList();

    // Inserts a new node with the given item at the specified position in the linked list
    bool insert(int position, const ItemType& newItem);

    // Removes the node at the specified position in the linked list
    bool remove(int position);

    // Retrieves the item at the specified position in the linked list
    ItemType getEntry(int position) const;

    // Checks if the linked list is empty
    bool isEmpty() const;

    // Clears the linked list
    void clear();
};

#include "LinkedList.cpp" // Include the implementation file
#endif
