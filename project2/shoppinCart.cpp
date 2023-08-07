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


#include <iostream>
#include <iomanip>
#include <vector>
#include "item.h"
#include "shoppingCart.h"


int main() {
    std::cout << "Welcome to XXX SHOPPING CENTER." << std::endl;

    ShoppingCart cart;

    char continueShopping = 'y';

    while (continueShopping == 'y') {
        std::string name;
        double unitPrice;
        int quantity;

        std::cout << "Enter the item you selected as the following order:" << std::endl;
        std::cout << "name unitPrice quantity" << std::endl;
        std::cin >> name >> unitPrice >> quantity;

        Item item(name, unitPrice, quantity);
        cart.addItem(item);

        std::cout << "Want to continue y/n--> ";
        std::cin >> continueShopping;
    }

    cart.displayOrder();

    char modifyOrder = 'y';

    while (modifyOrder == 'y') {
        std::cout << "Want to modify your order? y/n--> ";
        std::cin >> modifyOrder;

        if (modifyOrder == 'y') {
            int option;
            std::cout << "What do you want? Enter 1: add 2: remove 3: change quantity" << std::endl;
            std::cin >> option;

            std::string name;
            double unitPrice;
            int quantity;

            if (option == 1) {
                std::cout << "Enter the item to add as the following order:" << std::endl;
                std::cout << "name unitPrice quantity" << std::endl;
                std::cin >> name >> unitPrice >> quantity;
                Item item(name, unitPrice, quantity);
                cart.addItem(item);
                std::cout << "The item has been added." << std::endl;
            }
            else if (option == 2) {
                std::cout << "Enter the item to remove as the following order:" << std::endl;
                std::cout << "name unitPrice quantity" << std::endl;
                std::cin >> name >> unitPrice >> quantity;
                Item item(name, unitPrice, quantity);
                cart.removeItem(item);
                std::cout << "The item has been removed." << std::endl;
            }
            else if (option == 3) {
                std::cout << "Enter the item to change as the following order:" << std::endl;
                std::cout << "name unitPrice quantity" << std::endl;
                std::cin >> name >> unitPrice >> quantity;
                Item item(name, unitPrice, quantity);
                int newQuantity;
                std::cout << "Enter a new quantity --> ";
                std::cin >> newQuantity;
                cart.changeQuantity(item, newQuantity);
                std::cout << "The quantity has been modified." << std::endl;
            }
        }
    }

    cart.displayOrder();

    std::cout << "Thanks for shopping in XXX SHOPPING CENTER." << std::endl;

    return 0;
}
