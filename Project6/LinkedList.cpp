/**
 * problem description:  Design the following classes: FrontListIsA, FrontListHasA, FrontListAsA.
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/19/2023
*/

#include "LinkedList.h"
#include <stdexcept>

template <typename ItemType>
LinkedList<ItemType>::LinkedList() : head(nullptr), itemCount(0) {}

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& otherList) : head(nullptr), itemCount(0) {
    Node* otherCurrent = otherList.head;
    while (otherCurrent != nullptr) {
        insert(itemCount + 1, otherCurrent->data);
        otherCurrent = otherCurrent->next;
    }
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

template <typename ItemType>
bool LinkedList<ItemType>::insert(int position, const ItemType& newItem) {
    if (position < 1 || position > itemCount + 1) {
        return false;
    }

    Node* newNode = new Node(newItem);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    itemCount++;
    return true;
}

template <typename ItemType>
bool LinkedList<ItemType>::remove(int position) {
    if (position < 1 || position > itemCount) {
        return false;
    }

    Node* nodeToDelete;
    if (position == 1) {
        nodeToDelete = head;
        head = head->next;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        nodeToDelete = current->next;
        current->next = nodeToDelete->next;
    }

    delete nodeToDelete;
    itemCount--;
    return true;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    if (position < 1 || position > itemCount) {
        throw std::out_of_range("Invalid position.");
    }

    Node* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }

    return current->data;
}

template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template <typename ItemType>
void LinkedList<ItemType>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    itemCount = 0;
}
