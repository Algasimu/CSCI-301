/**
 * problem description: Write a program that maintains a database 
 * containing person’s name and birthday
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 08/01/2023
*/


#ifndef PERSON_H
#define PERSON_H

#include "Date.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @class Person
 * @brief Represents a person with a name and birthday.
 */
class Person {
private:
    string name;    /**< The name of the person. */
    Date birthday;  /**< The birthday of the person. */

public:
    /**
     * @brief Default constructor. Initializes name and birthday to empty.
     */
    Person() {}

    /**
     * @brief Parameterized constructor to initialize a Person object.
     * @param n The name of the person.
     * @param b The birthday of the person (as a Date object).
     */
    Person(string n, Date b) : name(n), birthday(b) {}

    /**
     * @brief Sets the name of the person.
     * @param n The name to set.
     */
    void setName(string n) { name = n; }

    /**
     * @brief Sets the birthday of the person.
     * @param b The birthday to set (as a Date object).
     */
    void setBirthday(Date b) { birthday = b; }

    /**
     * @brief Gets the name of the person.
     * @return The name of the person.
     */
    string getName() const { return name; }

    /**
     * @brief Gets the birthday of the person.
     * @return The birthday of the person (as a Date object).
     */
    Date getBirthday() const { return birthday; }

    /**
     * @brief Overloaded equality operator to compare two Person objects.
     * @param other The other Person object to compare with.
     * @return True if the names are equal; otherwise, false.
     */
    bool operator==(const Person& other) const { return name == other.name; }

    /**
     * @brief Overloaded less than operator to compare two Person objects.
     * @param other The other Person object to compare with.
     * @return True if the name of this person is less than the name of the other person; otherwise, false.
     */
    bool operator<(const Person& other) const { return name < other.name; }

    /**
     * @brief Overloaded greater than operator to compare two Person objects.
     * @param other The other Person object to compare with.
     * @return True if the name of this person is greater than the name of the other person; otherwise, false.
     */
    bool operator>(const Person& other) const { return name > other.name; }

    /**
     * @brief Overloaded output stream operator to print the person's name and birthday.
     * @param os The output stream object.
     * @param person The Person object to be printed.
     * @return The output stream after printing the person's name and birthday.
     */
    friend ostream& operator<<(ostream& os, const Person& person) {
        os << person.name << " " << person.birthday;
        return os;
    }

    /**
     * @brief Overloaded input stream operator to read the person's name and birthday.
     * @param is The input stream object.
     * @param person The Person object to store the read name and birthday.
     * @return The input stream after reading the person's name and birthday.
     */
    friend istream& operator>>(istream& is, Person& person) {
        is >> person.name >> person.birthday;
        return is;
    }
};

#endif
