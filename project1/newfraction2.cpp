/**
 * Name: Algassimou Diallo
 * starID: el8524jv
 * Due: 06/30/2023
 * Instructor: Meichsner Jie
 */

#include <iostream>
#include "newfraction2.h"




int main() {
//    Fraction fraction1(3, 4);
//    Fraction fraction2(1, 2);
    
    int numerator1, denominator1;
    std::cout << "Enter the numerator and denominator of the first fraction in the format a b: ";
    std::cin >> numerator1 >> denominator1;
    Fraction fraction1(numerator1, denominator1);

    int numerator2, denominator2;
    std::cout << "Enter the numerator and denominator of the Second fraction in the format a b: ";
    std::cin >> numerator2 >> denominator2;
    Fraction fraction2(numerator2, denominator2);


    
    Fraction sum = fraction1 + fraction2;
    Fraction difference = fraction1 - fraction2;
    Fraction product = fraction1 * fraction2;
    Fraction quotient = fraction1 / fraction2;

    std::cout << "Sum: " << sum << std::endl;                  
    std::cout << "Difference: " << difference << std::endl;    
    std::cout << "Product: " << product << std::endl;          
    std::cout << "Quotient: " << quotient << std::endl;       


    return 0;
}
