//
// Created by konstantin on 10.02.19.
//

#include "QuotientOfPolynomials.h"
#include <iostream>
using namespace std;

QuotientOfPolynomials::QuotientOfPolynomials(QuotientOfPolynomials& q){
    this->numerator = new Polynomial(*q.numerator);
    this->denominator = new Polynomial(*q.denominator);
}

QuotientOfPolynomials::QuotientOfPolynomials(Polynomial &numerator, Polynomial &denominator){
    this->numerator = new Polynomial(numerator);
    this->denominator = new Polynomial(denominator);
};

QuotientOfPolynomials::~QuotientOfPolynomials(){
    delete numerator;
    delete denominator;
}
//!
//!    если функция не определена в точке х, возвращается -123(мусор) и errorCode = 1
//!    иначе возвращается значение функции в точке х и errorCode = 0
//!
double QuotientOfPolynomials::getFunctionValue(double x, int &errorCode){
    double numeratorValue = (*numerator)(x);
    double denominatorValue = (*denominator)(x);

    if(denominatorValue == 0){
        errorCode = 1;
        return -123;
    }
    errorCode = 0;
    return numeratorValue/denominatorValue;
};

int QuotientOfPolynomials::getFunctionAppearance(string & buffer){
    string numString;
    string denString;
    numerator->getFunctionAppearance(numString);
    denominator->getFunctionAppearance(denString);

    if(denString == "0") {
        buffer = "infinity";
        return 0;
    }
    buffer = "( " + numString + " )/( " + denString + " )";

    return 0;
}

QuotientOfPolynomials& QuotientOfPolynomials::operator=(QuotientOfPolynomials const& q){
    if(this == &q) return *this;
//!
//!    здесь вызываются перегруженные операторы =()
//!    так что присваивание безопасное
//!
    *numerator = *q.numerator;
    *denominator = *q.denominator;

    return *this;
}

bool QuotientOfPolynomials::operator==(QuotientOfPolynomials const&q){
//!
//!    если числители и знаменатели совпадают,
//!    то функции считаются одинаковыми
//!
    if(this == &q) return true;
    if( *this->numerator != *q.numerator ) return false;

    return !( *this->denominator != *q.denominator );
}

bool QuotientOfPolynomials::operator!=(QuotientOfPolynomials const&q){
    return !( *this == q );
}

QuotientOfPolynomials* QuotientOfPolynomials::clone(){
    return new QuotientOfPolynomials(*this);
}
