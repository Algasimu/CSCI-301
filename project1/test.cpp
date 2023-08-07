#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor with default arguments
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    // Set functions
    void setNumerator(int num) { numerator = num; }
    void setDenominator(int denom) { denominator = denom; }

    // Get functions
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Function to display the fraction
    void display() const {
        std::cout << numerator << "/" << denominator;
    }
};

// Function to perform addition of two fractions
Fraction addFractions(const Fraction& f1, const Fraction& f2) {
    int resultNum = f1.getNumerator() * f2.getDenominator() + f2.getNumerator() * f1.getDenominator();
    int resultDenom = f1.getDenominator() * f2.getDenominator();
    return Fraction(resultNum, resultDenom);
}

// Function to perform multiplication of two fractions
Fraction multiplyFractions(const Fraction& f1, const Fraction& f2) {
    int resultNum = f1.getNumerator() * f2.getNumerator();
    int resultDenom = f1.getDenominator() * f2.getDenominator();
    return Fraction(resultNum, resultDenom);
}

// Function to perform division of two fractions
Fraction divideFractions(const Fraction& f1, const Fraction& f2) {
    int resultNum = f1.getNumerator() * f2.getDenominator();
    int resultDenom = f1.getDenominator() * f2.getNumerator();
    return Fraction(resultNum, resultDenom);
}

int main() {
    Fraction fraction1, fraction2;

    // Prompt the user to enter the first fraction
    std::cout << "Enter the first fraction (a/b): ";
    std::cin >> fraction1;

    // Prompt the user to enter the second fraction
    std::cout << "Enter the second fraction (a/b): ";
    std::cin >> fraction2;

    // Perform addition
    Fraction sum = addFractions(fraction1, fraction2);
    std::cout << "Sum: ";
    sum.display();
    std::cout << std::endl;

    // Perform multiplication
    Fraction product = multiplyFractions(fraction1, fraction2);
    std::cout << "Product: ";
    product.display();
    std::cout << std::endl;

    // Perform division
    Fraction quotient = divideFractions(fraction1, fraction2);
    std::cout << "Quotient: ";
    quotient.display();
    std::cout << std::endl;

    return 0;
}
