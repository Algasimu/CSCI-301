/**
 * Name: Algassimou Diallo
 * starID: el8524jv
 * Due: 06/30/2023
 * Instructor: Meichsner Jie
 */

#include <iostream>
#include "newfraction.h"
#include <iostream>



int main() {

    int numerator1, denominator1;
    std::cout << "Enter the numerator and denominator of the first fraction in the format (a b): ";
    std::cin >> numerator1 >> denominator1;
    Fraction fraction1(numerator1, denominator1);

    int numerator2, denominator2;
    std::cout << "Enter the numerator and denominator of the second fraction in the format (a b): ";
    std::cin >> numerator2 >> denominator2;
    Fraction fraction2(numerator2, denominator2);

    Fraction sum = addFractions(fraction1, fraction2);
    Fraction difference = subtractFractions(fraction1, fraction2);
    Fraction product = multiplyFractions(fraction1, fraction2);
    Fraction quotient = divideFractions(fraction1, fraction2);

   fraction1.display();
   fraction2.display();  
    sum.display();          
    difference.display();   
    product.display();
    quotient.display();
}
