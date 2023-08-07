//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "DoublyLinkedBag.h"

using namespace std;

void displayBag(DoublyLinkedBag<string>& bag)
{
	cout << "The bag contains " << bag.getSize()
        << " items:" << endl;
   vector<string> bagItems = bag.toVector();
   
   int numberOfEntries = (int) bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   }  // end for
	cout << endl << endl;
}  // end displayBag

void copyConstructorTester()
{
	DoublyLinkedBag<string> bag;
   string items[] = {"zero", "one", "two", "three", "four", "five"};
	for (int i = 0; i < 6; i++)
   {
		cout << "Adding " << items[i] << endl;
      bool success = bag.add(items[i]);
      if (!success)
         cout << "Failed to add " << items[i] << " to the bag." << endl;
	}
   displayBag(bag);

   DoublyLinkedBag<string> copyOfBag(bag);
   cout << "Copy of bag: ";
   displayBag(copyOfBag);
   
   cout << "The copied bag: ";
   displayBag(bag);
}  // end copyConstructorTester

void bagTester()
{
	DoublyLinkedBag<string> bag;
	cout << "Testing the Link-Based Bag:" << endl;
   cout << "isEmpty: returns " << bag.isEmpty()
   << "; should be 1 (true)" << endl;
   displayBag(bag);
   
	string items[] = {"one", "two", "three", "four", "five", "one"};
   cout << "Add 6 items to the bag: " << endl;
	for (int i = 0; i < 6; i++)
   {
		bag.add(items[i]);
	}  // end for
   
   displayBag(bag);
   
   cout << "isEmpty: returns " << bag.isEmpty()
   << "; should be 0 (false)" << endl;
	
   cout << "getCurrentSize: returns " << bag.getCurrentSize()
   << "; should be 6" << endl;
   
   cout << "Try to add another entry: add(\"extra\") returns "
   << bag.add("extra") << endl;
   
   cout << "contains(\"three\"): returns " << bag.contains("three")
   << "; should be 1 (true)" << endl;
   cout << "contains(\"ten\"): returns " << bag.contains("ten")
   << "; should be 0 (false)" << endl;
   cout << "getFrequencyOf(\"one\"): returns "
   << bag.getFrequencyOf("one") << " should be 2" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
   << "; should be 1 (true)" << endl;
   cout << "getFrequencyOf(\"one\"): returns "
   << bag.getFrequencyOf("one") << " should be 1" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
   << "; should be 1 (true)" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
   << "; should be 0 (false)" << endl;
   cout << endl;
   
   displayBag(bag);
   
   cout << "After clearing the bag, ";
   bag.clear();
   
   cout << "isEmpty: returns " << bag.isEmpty()
   << "; should be 1 (true)" << endl;
}  // end bagTester

int main()
{
   copyConstructorTester();
   bagTester();
   return 0;
}  // end main

/*
 Adding zero
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 The bag contains 6 items:
 five four three two one zero
 
 Copy of bag: The bag contains 6 items:
 five four three two one zero
 
 The copied bag: The bag contains 6 items:
 five four three two one zero
 
 Testing the Link-Based Bag:
 isEmpty: returns 1; should be 1 (true)
 The bag contains 0 items:
 
 
 Add 6 items to the bag:
 The bag contains 6 items:
 one five four three two one
 
 isEmpty: returns 0; should be 0 (false)
 getCurrentSize: returns 6; should be 6
 Try to add another entry: add("extra") returns 1
 contains("three"): returns 1; should be 1 (true)
 contains("ten"): returns 0; should be 0 (false)
 getFrequencyOf("one"): returns 2 should be 2
 remove("one"): returns 1; should be 1 (true)
 getFrequencyOf("one"): returns 1 should be 1
 remove("one"): returns 1; should be 1 (true)
 remove("one"): returns 0; should be 0 (false)
 
 The bag contains 5 items:
 five four three two extra
 
 After clearing the bag, isEmpty: returns 1; should be 1 (true)
*/
