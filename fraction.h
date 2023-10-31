#ifndef FRACTION_H
#define STOREITEM_H

#include <iostream>

/*
 * Name: Talon Bragg
 * Class: CS10B
 * Date: 09/30/2023
 * Filename: Fraction.h
 * Description: This program
 * defines a class Fraction that
 * is used to create an instance
 * of a fraction object with many methods
 * to add, subtract, multiply, and divide 
 * two Fractions. This class also features
 * a simplify function which simplifies the fraction
 * using a (hopefully) unique algorithm.
 * 
 * Class description: This class represents a fraction
 * of with a numerator > -1 and a denominator > 0. This class
 * has numerous arithmetic operation functions that act on
 * the fraction.
 * 
 * Function prototypes pre/post conditions:
 * 
 * Fraction();
 * postcondition: default constructor sets numerator
 * data member to 0 and denominator to 1
 * 
 * Fraction(int initNumerator, int initDenominator);
 * precondition: initDenominator is a non zero positive integer
 * postcondition: numerator and denominator data members are set to
 * initNumerator and initDenominator respectively.
 * 
 * friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
 * precondition: The fraction object does not exist in the output stream
 * postcondition: The fraction object does exist in the output stream
 * 
 * friend std::istream& operator>>(std::istream& in, Fraction& right);
 * precondition: the fraction object does not exist in the input stream
 * postcondition: the fraction object does exist in the input stream
 * 
 * friend bool operator<(const Fraction& left, const Fraction& right);
 * precondition: Two fractions, or a fraction and an integer are set in a comparison expression
 * postcondition: The less than comparison operator is overloaded and the fraction and integer or
 * the fraction and fraction are compared and a boolean is returned
 * 
 * friend bool operator<=(const Fraction& left, const Fraction& right);
 * precondition: Two fractions, or a fraction and an integer are set in a comparison expression
 * postcondition: The less than or equal to comparison operator is overloaded and the fraction and integer or
 * the fraction and fraction are compared and a boolean is returned
 * 
 * friend bool operator>(const Fraction& left, const Fraction& right);
 * precondition: Two fractions, or a fraction and an integer are set in a comparison expression
 * postcondition: The greater than comparison operator is overloaded and the fraction and integer or
 * the fraction and fraction are compared and a boolean is returned
 * 
 * friend bool operator>=(const Fraction& left, const Fraction& right);
 * precondition: Two fractions, or a fraction and an integer are set in a comparison expression
 * postcondition: The greater than or equal to comparison operator is overloaded and the fraction and integer or
 * the fraction and fraction are compared and a boolean is returned
 * 
 * friend bool operator==(const Fraction& left, const Fraction& right);
 * precondition: Two fractions, or a fraction and an integer are set in a comparison expression
 * postcondition: The equality comparison operator is overloaded and the fraction and integer or
 * the fraction and fraction are compared and a boolean is returned
 * 
 * friend bool operator!=(const Fraction& left, const Fraction& right);
 * precondition: Two fractions, or a fraction and an integer are set in a comparison expression
 * postcondition: The not-equal-to comparison operator is overloaded and the fraction and integer or
 * the fraction and fraction are compared and a boolean is returned
 * 
 * friend Fraction operator+(const Fraction& f1, const Fraction& f2);
 * precondition: Two fractions, or a fraction and an integer are set in a binary arithmetic
 * expression.
 * postcondition: The addition operator is overloaded and the two fractions (or fraction and integer) are added, 
 * and a Fraction object is returned as the result of the expression.
 * 
 * friend Fraction operator-(const Fraction& f1, const Fraction& f2);
 * precondition: Two fractions, or a fraction and an integer are set in a binary arithmetic
 * expression.
 * postcondition: The subtraction operator is overloaded and the two fractions (or fraction and integer) are subtracted, 
 * and a Fraction object is returned as the result of the expression.
 * 
 * friend Fraction operator*(const Fraction& f1, const Fraction& f2);
 * precondition: Two fractions, or a fraction and an integer are set in a binary arithmetic
 * expression.
 * postcondition: The multiplication operator is overloaded and the two fractions (or fraction and integer) are multiplied, 
 * and a Fraction object is returned as the result of the expression.
 * 
 * friend Fraction operator/(const Fraction& f1, const Fraction& f2);
 * precondition: Two fractions, or a fraction and an integer are set in a binary arithmetic
 * expression.
 * postcondition: The division operator is overloaded and the two fractions (or fraction and integer) are divided, 
 * and a Fraction object is returned as the result of the expression.
 * 
 * friend Fraction operator+=(Fraction& leftSide, const Fraction& rightSide);
 * precondition: A fraction is placed on the left side of the shorthand addition operator
 * and a Fraction or integer is placed on the right side of the shorthand addition operator
 * postcondition: The shorthand addition operator is overloaded and a Fraction object is returned
 * as the result
 * 
 * friend Fraction operator-=(Fraction& leftSide, const Fraction& rightSide);
 * precondition: A fraction is placed on the left side of the shorthand subtraction operator
 * and a Fraction or integer is placed on the right side of the shorthand subtraction operator
 * postcondition: The shorthand subtraction operator is overloaded and a Fraction object is returned
 * as the result
 * 
 * friend Fraction operator*=(Fraction& leftSide, const Fraction& rightSide);
 * precondition: A fraction is placed on the left side of the shorthand multiplication operator
 * and a Fraction or integer is placed on the right side of the shorthand multiplication operator
 * postcondition: The shorthand multiplication operator is overloaded and a Fraction object is returned
 * as the result
 * 
 * friend Fraction operator/=(Fraction& leftSide, const Fraction& rightSide);
 * precondition: A fraction is placed on the left side of the shorthand multiplication operator
 * and a Fraction or integer is placed on the right side of the shorthand multiplication operator
 * postcondition: The shorthand multiplication operator is overloaded and a Fraction object is returned
 * as the result
 * 
 * Fraction operator++();
 * precondition: A fraction is placed on the left side of the pre increment operator
 * postcondition: The fraction is incremented
 * 
 * Fraction operator++(int);
 * precondition: A fraction is placed on the left side of the post increment operator
 * postcondition: The fraction is incremented
 * 
 * Fraction operator--();
 * precondition: A fraction is placed on the left side of the pre decrement operator
 * postcondition: The fraction is incremented
 * 
 * Fraction operator--(int);
 * precondition: A fraction is placed on the left side of the post decrement operator
 * postcondition: The fraction is incremented
 * 
 * int GetNumerator() const;
 * precondition: GetNumerator is called
 * postcondition: numerator data member is returned
 * 
 * int GetDenominator() const;
 * precondition: GetDenominator is called
 * postcondition: denominator data member is returned
 */

namespace cs_fraction {
    class Fraction {
            int numerator;
            int denominator;
        public:
            Fraction();
            Fraction(int initNumerator);
            Fraction(int initNumerator, int initDenominator);
            friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
            friend std::istream& operator>>(std::istream& in, Fraction& right);
            friend bool operator<(const Fraction& left, const Fraction& right);
            friend bool operator<=(const Fraction& left, const Fraction& right);
            friend bool operator>(const Fraction& left, const Fraction& right);
            friend bool operator>=(const Fraction& left, const Fraction& right);
            friend bool operator==(const Fraction& left, const Fraction& right);
            friend bool operator!=(const Fraction& left, const Fraction& right);
            friend Fraction operator+(const Fraction& f1, const Fraction& f2);
            friend Fraction operator-(const Fraction& f1, const Fraction& f2);
            friend Fraction operator*(const Fraction& f1, const Fraction& f2);
            friend Fraction operator/(const Fraction& f1, const Fraction& f2);
            friend Fraction operator+=(Fraction& leftSide, const Fraction& rightSide);
            friend Fraction operator-=(Fraction& leftSide, const Fraction& rightSide);
            friend Fraction operator*=(Fraction& leftSide, const Fraction& rightSide);
            friend Fraction operator/=(Fraction& leftSide, const Fraction& rightSide);
            Fraction operator++();
            Fraction operator++(int);
            Fraction operator--();
            Fraction operator--(int);
            int GetNumerator() const;
            int GetDenominator() const;
        private:
            void simplify();
    };
}

#endif