/**
 * This class represents the ADT Bag implemented using a doubly-linked list.
 * A bag is an unordered collection that allows duplicate elements.
 */

#ifndef LINKEDBAG_H
template<class ItemType>
class DoublyLinkedBag {
private:
    /**
     * This inner class represents a node in the doubly-linked list.
     * Each node contains the data element and pointers to the previous and next nodes.
     */
    class Node {
    public:
        int data;       // The data element
        Node* prev;     // Pointer to the previous node
        Node* next;     // Pointer to the next node

        /**
         * Node constructor.
         * @param value The value to be stored in the node.
         */
        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* first;        // Pointer to the first node in the bag
    int size;           // Current size of the bag

public:
    /**
     * Bag constructor.
     * Initializes an empty bag.
     */
    DoublyLinkedBag() : first(nullptr), size(0) {}

    /**
     * Checks if the bag is empty.
     * @return True if the bag is empty, false otherwise.
     */
    bool isEmpty() const {
        return size == 0;
    }

    /**
     * Returns the current size of the bag.
     * @return The size of the bag.
     */
    int getSize() const {
        return size;
    }

    /**
     * Adds a new element to the bag.
     * @param value The value to be added.
     */
    bool add(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            first = newNode;
        } else {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
        size++;
    }

    /**
     * Removes an element from the bag.
     * @param value The value to be removed.
     * @return True if the value was found and removed, false otherwise.
     */
    bool remove(int value) {
        Node* current = first;
        while (current != nullptr) {
            if (current->data == value) {
                if (current == first) {
                    first = current->next;
                } else {
                    current->prev->next = current->next;
                    if (current->next != nullptr) {
                        current->next->prev = current->prev;
                    }
                }
                delete current;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    /**
     * Checks if a specific element exists in the bag.
     * @param value The value to search for.
     * @return True if the value is found, false otherwise.
     */
    bool contains(int value) const {
        Node* current = first;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
   // vector<ItemType> toVector() const;
};
#endif
