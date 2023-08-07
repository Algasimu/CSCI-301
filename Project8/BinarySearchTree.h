/**
 * problem description: Write a program that maintains a database 
 * containing person’s name and birthday
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 08/01/2023
*/


#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <functional>
#include <string>
using namespace std;


/**
 * @class BinarySearchTree
 * @brief A templated binary search tree data structure.
 * @tparam T The type of elements stored in the tree.
 */
template <class T>
class BinarySearchTree {
private:
/**
 * @struct Node
 * @brief Represents a node in the binary search tree.
 */
    struct Node {
        T data;         /**< The data stored in the node. */
        Node* left;     /**< Pointer to the left child node. */
        Node* right;    /**< Pointer to the right child node. */

        /**
         * @brief Constructor to create a new node with the given value.
         * @param val The value to be stored in the node.
         */
        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;     /**< Pointer to the root node of the binary search tree. */

    void insertNode(Node*& node, const T& value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insertNode(node->left, value);
        } else if (value > node->data) {
            insertNode(node->right, value);
        }
    }

    bool containsNode(const Node* node, const T& value) const {
        if (node == nullptr) {
            return false;
        } else if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return containsNode(node->left, value);
        } else {
            return containsNode(node->right, value);
        }
    }

    void removeNode(Node*& node, const T& value) {
        if (node == nullptr) {
            return;
        }

        if (value < node->data) {
            removeNode(node->left, value);
        } else if (value > node->data) {
            removeNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node* temp = findMinNode(node->right);
                node->data = temp->data;
                removeNode(node->right, temp->data);
            }
        }
    }

    Node* findMinNode(Node* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void traverseInorder(const Node* node, const function<void(const T&)>& visit) const {
        if (node != nullptr) {
            traverseInorder(node->left, visit);
            visit(node->data);
            traverseInorder(node->right, visit);
        }
    }

    void traversePreorder(const Node* node, const function<void(const T&)>& visit) const {
        if (node != nullptr) {
            visit(node->data);
            traversePreorder(node->left, visit);
            traversePreorder(node->right, visit);
        }
    }

public:
    /**
     * @brief Default constructor to create an empty binary search tree.
     */
    BinarySearchTree() : root(nullptr) {}

    /**
     * @brief Inserts a new value into the binary search tree.
     * @param value The value to be inserted.
     */
    void insert(const T& value) {
        insertNode(root, value);
    }

    /**
     * @brief Checks if the binary search tree contains a specific value.
     * @param value The value to search for.
     * @return True if the value is found; otherwise, false.
     */
    bool contains(const T& value) const {
        return containsNode(root, value);
    }

    /**
     * @brief Removes a value from the binary search tree.
     * @param value The value to be removed.
     */
    void remove(const T& value) {
        removeNode(root, value);
    }
    /**
     * @brief Traverses the binary search tree in inorder and performs an action on each node's value.
     * @param visit The function to be called on each node's value during the inorder traversal.
     */
    void traverseInorder(const function<void(const T&)>& visit) const {
        traverseInorder(root, visit);
    }

    /**
     * @brief Traverses the binary search tree in preorder and performs an action on each node's value.
     * @param visit The function to be called on each node's value during the preorder traversal.
     */
    void traversePreorder(const function<void(const T&)>& visit) const {
        traversePreorder(root, visit);
    }

    /**
     * @brief Destructor to deallocate memory used by the binary search tree.
     */
    ~BinarySearchTree() {
        clear(root);
    }

private:

    /**
     * @brief Recursively deallocates memory used by the binary search tree.
     * @param node The current node being considered during the deallocation process.
     */
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};
#endif