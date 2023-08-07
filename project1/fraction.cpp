/**
 * Name: Algassimou Diallo
 * starID: el8524jv
 * Due: 06/30/2023
 * Instructor: Meichsner Jie
 */

#include <iostream>
#include "fraction.h"
//#include "newfraction.h"
#include <math.h>

int main() {
    // Fraction fraction1;  // Using default constructor
    // fraction1.setNumerator(3);
    // fraction1.setDenominator(4);
    // fraction1.display();  // Output: 3/4

    // Fraction fraction2(1, 2);  // Using constructor with arguments
    // fraction2.display();       // Output: 1/2

    // Prompt the user to enter the first fraction
    int numerator1, denominator1;
    std::cout << "Enter the numerator and denominator of the first fraction in the format a b: ";
    std::cin >> numerator1 >> denominator1;
    Fraction fraction1(numerator1, denominator1);

    // Prompt the user to enter the second fraction
    int numerator2, denominator2;
    std::cout << "Enter the numerator and denominator of the second fraction in the format a b: ";
    std::cin >> numerator2 >> denominator2;
    Fraction fraction2(numerator2, denominator2);

    int num1 = fraction1.getNumerator();
    int den1 = fraction1.getDenominator();
    std::cout << "Numerator of the first fraction: " << num1 << std::endl;       
    std::cout << "Denominator of the first fraction: " << den1 << std::endl;   
    fraction1.display();
    fraction2.display();


    return 0;
}
