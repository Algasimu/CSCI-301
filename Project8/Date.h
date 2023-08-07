/**
 * problem description: Write a program that maintains a database 
 * containing person’s name and birthday
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 08/01/2023
*/


#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @class Date
 * @brief Represents a date with month, day, and year components.
 */
class Date {
private:
    int month; /**< The month component of the date. */
    int day;   /**< The day component of the date. */
    int year;  /**< The year component of the date. */

public:
    /** 
     * @brief Default constructor. Initializes date to all zeros.
     */
    Date() {}

    /**
     * @brief Parameterized constructor to initialize a Date object.
     * @param m The month component of the date.
     * @param d The day component of the date.
     * @param y The year component of the date.
     */
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    /**
     * @brief Sets the month component of the date.
     * @param m The month to set.
     */
    void setMonth(int m) { month = m; }

    /**
     * @brief Sets the day component of the date.
     * @param d The day to set.
     */
    void setDay(int d) { day = d; }

    /**
     * @brief Sets the year component of the date.
     * @param y The year to set.
     */
    void setYear(int y) { year = y; }

    /**
     * @brief Gets the month component of the date.
     * @return The month component.
     */
    int getMonth() const { return month; }

    /**
     * @brief Gets the day component of the date.
     * @return The day component.
     */
    int getDay() const { return day; }

    /**
     * @brief Gets the year component of the date.
     * @return The year component.
     */
    int getYear() const { return year; }

    /**
     * @brief Overloaded output stream operator to print the date in "MM DD YYYY" format.
     * @param os The output stream object.
     * @param date The Date object to be printed.
     * @return The output stream after printing the date.
     */
    friend ostream& operator<<(ostream& os, const Date& date) {
        os << date.month << " " << date.day << " " << date.year;
        return os;
    }

    /**
     * @brief Overloaded input stream operator to read the date in "MM DD YYYY" format.
     * @param is The input stream object.
     * @param date The Date object to store the read date.
     * @return The input stream after reading the date.
     */
    friend istream& operator>>(istream& is, Date& date) {
        is >> date.month >> date.day >> date.year;
        return is;
    }
};

#endif
