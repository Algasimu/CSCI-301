/**
 * problem: When shopping online, you select items and add them to a shopping cart. Duplicate items
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

#ifndef SHORPCART_H
#define SHORPCART_H
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "item.h"

/**
 * Represents a shopping cart.
 */
class ShoppingCart {
private:
    std::vector<Item> items;

public:
    /**
     * Add an item to the shopping cart.
     * @param item The item to add
     */
    void addItem(const Item& item) {
        items.push_back(item);
    }
     /**
     * Remove an item from the shopping cart.
     * @param item The item to remove
     */   
    void removeItem(const Item& item) {
        for (auto i = items.begin(); i != items.end(); ++i) {
            if (i->getName() == item.getName() && i->getUnitPrice() == item.getUnitPrice()) {
                items.erase(i);
                break;
            }
        }
    }
    /**
     * Change the quantity of an item in the shopping cart.
     * @param item        The item to modify
     * @param newQuantity The new quantity
     */
    void changeQuantity(const Item& item, int newQuantity) {
        for (auto it : items) {
            if (it.getName() == item.getName() && it.getUnitPrice() == item.getUnitPrice()) {
                it = Item(it.getName(), it.getUnitPrice(), newQuantity);
                break;
            }
        }
    }
     /**
     * Get the total charge for the items in the shopping cart.
     * @return The total charge
     */
    double getTotalCharge() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.getUnitPrice() * item.getQuantity();
        }
        return total;
    }
    /**
     * Display the order summary.
     */
    void displayOrder() const {
        std::cout << "Here is your order:" << std::endl;
        std::cout << "-------------------------------------------------" << std::endl;
        std::cout << "Name" << std::setw(12) << "Unit_Price" << std::setw(9) << "Quantity" << std::endl;
        for (const auto& item : items) {
            std::cout << item.getName() << std::setw(6) << "$" << item.getUnitPrice() << std::setw(9) << item.getQuantity() << std::endl;
        }
        std::cout << "The total charge is $" << std::fixed << std::setprecision(2) << getTotalCharge() << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
    }
};
#endif