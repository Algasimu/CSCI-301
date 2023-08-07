/**
 * Name: Algassimou Diallo
 * starID: el8524jv
 * Due: 06/30/2023
 * Instructor: Meichsner Jie
 */

#include <iostream>
#ifndef NEWFRACT2_H
#define NEWFRACT2_H

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
     * Retrieves the denomirator of the fraction.
     * @return The numerator of the fraction.
     */
    int getDenominator() const { return denominator; }

    /**
     * Displays the fraction in the format a/b.
     */
    void display() const {
        std::cout << numerator << "/" << denominator;
    }
    /** Function to return the sum of two fractions
    /* @param f1 and f2 are fractions 
    /* @pre None
    /* @post The return value is the addition of f1 and f2*/
    //None Member functions.....
    // Operator overloading: Sum (+) as a member function
    Fraction operator+(const Fraction& other) const {
        int resultNum = numerator * other.denominator + other.numerator * denominator;
        int resultDenom = denominator * other.denominator;
        return Fraction(resultNum, resultDenom);
    }

    /** Function to return the difference of two fractions
    /* @param f1 and f2 are fractions 
    /* @pre None
    /* @post The return value is the sustraction of f1 and f2*/
    //None Member functions.....
    Fraction operator-(const Fraction& other) const {
        int resultNum = numerator * other.denominator - other.numerator * denominator;
        int resultDenom = denominator * other.denominator;
        return Fraction(resultNum, resultDenom);
    }
};
    /** Function to return the product of two fractions
    /* @param f1 and f2 are fractions 
    /* @pre None
    /* @post The return value is is the product of f1 and f2*/
    //None Member functions.....
    // Operator overloading: Product (*) as a non-member function
Fraction operator*(const Fraction& f1, const Fraction& f2) {
    int resultNum = f1.getNumerator() * f2.getNumerator();
    int resultDenom = f1.getDenominator() * f2.getDenominator();
    return Fraction(resultNum, resultDenom);
}
    /**  Function to return the quotient of two fractions
    /* @param f1 and f2 are fractions 
    /* @pre None
    /* @post The return value is is the quotient of f1 and f2*/
    //None Member functions.....
    // Operator overloading: Quotient (/) as a non-member function
Fraction operator/(const Fraction& f1, const Fraction& f2) {
    int resultNum = f1.getNumerator() * f2.getDenominator();
    int resultDenom = f1.getDenominator() * f2.getNumerator();
    return Fraction(resultNum, resultDenom);
}

// Operator overloading: Output (<<) as a non-member function
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.getNumerator() << "/" << fraction.getDenominator();
    return os;
}

// Operator overloading: Input (>>) as a friend function of the class fraction
std::istream& operator>>(std::istream& is, const Fraction& fraction) {
    char delimiter;
    is >> fraction.getNumerator() >> delimiter >> fraction.getDenominator();
    return is;
}

#endif
