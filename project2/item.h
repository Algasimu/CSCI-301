/**
 * Problem: When shopping online, you select items and add them to a shopping cart. Duplicate items
are permitted in a shopping cart, as you can purchase multiples of the same item. You
also can remove an item from a shopping cart, if you change your mind about buying it.
The shopping cart can show its current contents with their prices and the total cost of
these items. Design the ADT item and shopping cart.

 * startID: el8524jv
 * Name:Algassimou Diallo
 * Due: 07/03/2023
 * Instructor: Meichsner Jie
 * Comments:
*/
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

/**
 * Represents an item in the shopping center.
 */

class Item {
private:
    std::string name;
    double unitPrice;
    int quantity;

public:
    /**
     * Constructor with parameters.
     * @param itemName     Name of the item
     * @param itemPrice    Unit price of the item
     * @param itemQuantity Quantity of the item
     */
    Item(const std::string& itemName, double itemPrice, int itemQuantity)
        : name(itemName), unitPrice(itemPrice), quantity(itemQuantity) {}

    std::string getName() const { return name; }
    double getUnitPrice() const { return unitPrice; }
    int getQuantity() const { return quantity; }
};

#endif