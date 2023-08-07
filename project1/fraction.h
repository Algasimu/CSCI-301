
/**
 * Name: Algassimou Diallo
 * starID: el8524jv
 * Due: 06/30/2023
 * Instructor: Meichsner Jie
 */


#ifndef FRACT_H
#define FRACT_H

#include <iostream>
/**
 * Represents a fraction number in mathematics.
 * A fraction is defined as a/b, where a and b are integers
 * and called numerator and denominator, respectively.
 */

class Fraction {
private:
    int numerator;
    int denominator;

public:
    /**
     * Constructs a new Fraction object.
     * @param num The numerator of the fraction. Default is 0.
     * @param denom The denominator of the fraction. Default is 1.
     */
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    /**
     * Sets the numerator of the fraction.
     * @param num The numerator value to set.
     */
    void setNumerator(int num) { numerator = num; }
    /**
     * Sets the denominator of the fraction.
     * @param denom The denominator value to set.
     */
    void setDenominator(int denom) { denominator = denom; }

    /**
     * Retrieves the numerator of the fraction.
     * @return The numerator of the fraction.
     */
    int getNumerator() const { return numerator; }

    /**
     * Retrieves the denominator of the fraction.
     * @return The denominator of the fraction.
     */
    int getDenominator() const { return denominator; }

    /**
     * Displays the fraction in the format a/b.
     */
    void display() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};
#endif 
