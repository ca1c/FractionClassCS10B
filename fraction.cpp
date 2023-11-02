#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

#include "fraction.h"

/*
 * Class invariant:
 * numerator data member used as numerator of fraction
 * denominator data member used a denominator of fraction
 * fractions will always be returned in simplest form
 * the denominator of the class will always be > 0
 * the numerator of the class will always be > -1
*/

namespace cs_fraction {

    /**
    * Default constructor that sets numerator data member to 0
    * and denominator to 1
    */
    Fraction::Fraction() {
        numerator = 0;
        denominator = 1;
    }

    /**
     * Overload constructor for one integer parameter
     * This constructor sets numerator to initNumerator and
     * denominator to 1
    */
    Fraction::Fraction(int initNumerator) {
        numerator = initNumerator;
        denominator = 1;
    }

    /**
    * Overload constructor that sets numerator to int initNumerator
    * and sets denominator data member to initDenominator
    */
    Fraction::Fraction(int initNumerator, int initDenominator) {
        assert(initDenominator != 0);
        numerator = initNumerator;
        denominator = initDenominator;
    }

    /**
     * Friend function to overload the stream insertion operator to insert a fraction into
     * the output stream.
    */
    std::ostream& operator<<(std::ostream& out, const Fraction& right) {
        int wholeNumber = right.GetNumerator() / right.GetDenominator();
        Fraction newFraction(right.GetNumerator() % right.GetDenominator(), right.GetDenominator());
        newFraction.simplify();
        if(wholeNumber == 0 && newFraction.GetNumerator() != 0) {
            out << newFraction.GetNumerator() << "/" << newFraction.GetDenominator();
        }
        else if(newFraction.GetNumerator() == 0) {
            out << wholeNumber;
        }
        else {
            out << wholeNumber << "+" << abs(newFraction.numerator) << "/" << abs(newFraction.denominator);
        }
        return out;
    }

    /**
     * Friend function to overload the extraction operator to extract a fraction from input
    */
    std::istream& operator>>(std::istream& in, Fraction& right) {
        string inString;
        in >> inString;
        stringstream ss;
        ss << inString;
        char tempChar;
        int tempInt;
        ss >> tempInt >> tempChar;
        if(tempChar == '+') {
            ss >> right.numerator >> tempChar >> right.denominator;
            right.numerator += abs(tempInt * right.denominator);
            if(tempInt < 0) {
                right.numerator *= -1;
            }
        }
        else if(tempChar == '/') {
            right.numerator = tempInt;
            ss >> right.denominator;
        }
        else {
            right.numerator = tempInt;
            right.denominator = 1;
        }

        return in;
    }

    /**
     * Friend function to overloads the less than comparison operator to compare two fractions
    */
    bool operator<(const Fraction& left, const Fraction& right) {
        double leftFraction = static_cast<double>(left.GetNumerator()) / left.GetDenominator();
        double rightFraction = static_cast<double>(right.GetNumerator()) / right.GetDenominator();

        return leftFraction < rightFraction;
    }

    /**
     * Friend function to overloads the less than or equal to operator to compare two fractions
    */
    bool operator<=(const Fraction& left, const Fraction& right) {
        double leftFraction = static_cast<double>(left.GetNumerator()) / left.GetDenominator();
        double rightFraction = static_cast<double>(right.GetNumerator()) / right.GetDenominator();

        return leftFraction <= rightFraction || abs(leftFraction - rightFraction) < 0.00000001;
    }

    /**
     * Friend function to overloads the greater than comparison operator to compare two fractions
    */
    bool operator>(const Fraction& left, const Fraction& right) {
        double leftFraction = static_cast<double>(left.GetNumerator()) / left.GetDenominator();
        double rightFraction = static_cast<double>(right.GetNumerator()) / right.GetDenominator();

        return leftFraction > rightFraction;
    }

    /**
     * Friend function to overloads the greater than or equal to operator to compare two fractions
    */
    bool operator>=(const Fraction& left, const Fraction& right) {
        double leftFraction = static_cast<double>(left.GetNumerator()) / left.GetDenominator();
        double rightFraction = static_cast<double>(right.GetNumerator()) / right.GetDenominator();

        return leftFraction > rightFraction || abs(leftFraction - rightFraction) < 0.00000001;
    }

    /**
     * Friend function to overloads the equality comparison operator to compare two fractions
    */
    bool operator==(const Fraction& left, const Fraction& right) {
        double leftFraction = static_cast<double>(left.GetNumerator()) / left.GetDenominator();
        double rightFraction = static_cast<double>(right.GetNumerator()) / right.GetDenominator();

        return abs(leftFraction - rightFraction) < 0.00000001;
    }

    /**
     * Friend function to overloads the not-equal-to comparison operator to compare two fractions
    */
    bool operator!=(const Fraction& left, const Fraction& right) {
        double leftFraction = static_cast<double>(left.GetNumerator()) / left.GetDenominator();
        double rightFraction = static_cast<double>(right.GetNumerator()) / right.GetDenominator();

        return !(abs(leftFraction - rightFraction) < 0.00000001);
    }
    /*
    * overloads additions operator
    * Adds the current Fraction instance and another fraction object together
    * and returns a Fraction object;
    * this takes one parameter f2 of type Fraction
    */
    Fraction operator+(const Fraction& f1, const Fraction& f2) {
        int commonDenominator = f2.GetDenominator() * f1.GetDenominator();
        int newNumerator1 = f2.GetDenominator() * f1.GetNumerator();
        int newNumerator2 = f1.GetDenominator() * f2.GetNumerator();
        Fraction newFraction(newNumerator1 + newNumerator2, commonDenominator);
        return newFraction;
    }

    /*
    * overloads the subtraction operator
    * Subtracts another Fraction object from the current Fraction instance
    * and returns a Fraction object
    * this takes one parameter f2 of type Fraction
    */
    Fraction operator-(const Fraction& f1, const Fraction& f2) {
        int commonDenominator = f2.GetDenominator() * f1.GetDenominator();
        int newNumerator1 = f2.GetDenominator() * f1.GetNumerator();
        int newNumerator2 = f1.GetDenominator() * f2.GetNumerator();
        Fraction newFraction(newNumerator1 - newNumerator2, commonDenominator);
        return newFraction;
    }

    /*
    * Overloads the multiplication operator
    * Multiplies current Fraction instance by another Fraction object
    * and returns a Fraction object
    * this takes one parameter
    */
    Fraction operator*(const Fraction& f1, const Fraction& f2) {
        Fraction newFraction(f1.GetNumerator() * f2.GetNumerator(), f1.GetDenominator() * f2.GetDenominator());
        return newFraction;
    }


    /*
    * Overloads the division operator
    * Divides current Fraction instance by another Fraction object
    * and returns a Fraction object
    * this takes one parameter f2 of type Fraction
    */
    Fraction operator/(const Fraction& f1, const Fraction& f2) {
        Fraction tempFraction(f2.GetDenominator(), f2.GetNumerator());
        Fraction newFraction(f1.GetNumerator(), f1.GetDenominator());
        newFraction = newFraction * tempFraction;
        return newFraction;
    }

    /*
    * Overloads the shorthand addition operator for fraction addition
    */
    Fraction operator+=(Fraction& leftSide, const Fraction& rightSide) {
        leftSide = leftSide + rightSide;
        return leftSide;
    }

    /*
    * Overloads the shorthand subtraction operator for fraction subtraction
    */
    Fraction operator-=(Fraction& leftSide, const Fraction& rightSide) {
        leftSide = leftSide - rightSide;
        return leftSide;
    }

    /*
    * Overloads the shorthand multiplication operator for fraction multiplication
    */
    Fraction operator*=(Fraction& leftSide, const Fraction& rightSide) {
        leftSide = leftSide * rightSide;
        return leftSide;
    }

    /*
    * Overloads the shorthand division operator for fraction division
    */
    Fraction operator/=(Fraction& leftSide, const Fraction& rightSide) {
        leftSide = leftSide / rightSide;
        return leftSide;
    }

    /*
    * Overloads the pre increment operator to increment fractions
    */
    Fraction Fraction::operator++() {
        numerator += denominator;
        return *this;
    }

    /*
    * Overloads the post increment operator to increment fractions
    */
    Fraction Fraction::operator++(int) {
        Fraction tempFraction(numerator, denominator);
        numerator += denominator;
        return tempFraction;
    }

    /*
    * Overloads the pre decrement operator to decrement fractions
    */
    Fraction Fraction::operator--() {
        numerator -= denominator;
        return *this;
    }

    /*
    * Overloads the post decrement operator to decrement fractions
    */
    Fraction Fraction::operator--(int) {
        Fraction tempFraction(numerator, denominator);
        numerator -= denominator;
        return tempFraction;
    }

    /*
    * Getter member function for the numerator data member
    */
    int Fraction::GetNumerator() const {
        return numerator;
    }

    /*
    * Getter member function for the denominator data member
    */
    int Fraction::GetDenominator() const {
        return denominator;
    }

    /*
    * Simplifies the acting class'
    * fraction using a while loop that
    * starts a divisor at the numerator and divides
    * the numerator and denominator by this value
    * any time both the numerator and denominator
    * both divide evenly by this number.
    * Eventually the divisor gets to 2 and the loop
    * stops. 
    */

    void Fraction::simplify() {
        bool isNegative = numerator < 0 || denominator < 0;
        numerator = abs(numerator);
        denominator = abs(denominator);

        if(numerator == denominator) {
            numerator = 1;
            denominator = 1;
            return;
        }

        int divisor = numerator;

        while(divisor > 1) {
            bool numDividesEvenly = numerator % divisor == 0;
            bool denDividesEvenly = denominator % divisor == 0; 
            if(numDividesEvenly && denDividesEvenly) {
                numerator = numerator / divisor;
                denominator = denominator / divisor;
                divisor = numerator;
            }
            else {
                divisor--;
            }
        }

        if(isNegative) {
            numerator *= -1;
        }
    }
}
