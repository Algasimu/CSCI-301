/**
 * problem description: this program about dictionary check. It reads a word in an inputed file from the user
 * and compares it with the saved disctionary and display the list of the misspelled words.
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/11/2023
*/

#ifndef LINKEDBAG_H

using namespace std;

/**
 * This class represents a Bag implemented using a doubly-linked list.
 * It stores a collection of words as the dictionary.
 */
class Dictionary {
private:
    class Node {
    public:
        string data;
        Node* prev;
        Node* next;

        Node(const string& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* first;
    int size;

public:
    Dictionary() : first(nullptr), size(0) {}

    /**
     * Adds a new word to the dictionary.
     * @param word The word to add.
     */
    void addWord(const string& word) {
        Node* newNode = new Node(word);
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
     * Checks if a word is contained in the dictionary.
     * @param word The word to check.
     * @return True if the word is in the dictionary, false otherwise.
     */
    bool contains(const string& word) const {
        Node* current = first;
        while (current != nullptr) {
            if (current->data == word) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    /**
     * Checks if the dictionary is empty.
     * @return True if the dictionary is empty, false otherwise.
     */
    bool isEmpty() const {
        return size == 0;
    }
};
#endif