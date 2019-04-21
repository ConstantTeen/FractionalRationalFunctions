//
// Created by konstantin on 10.02.19.
//

#include "Quotient.h"
#include <iostream>
using namespace std;

Quotient::Quotient(const Quotient& q){
//    this->numerator = new Polynomial(*q.numerator);
//    this->denominator = new Polynomial(*q.denominator);
    this->numerator = q.numerator;
    this->denominator = q.denominator;
}

Quotient::Quotient(Polynomial &numerator, Polynomial &denominator){
//    this->numerator = new Polynomial(numerator);
//    this->denominator = new Polynomial(denominator);
    this->numerator = make_shared<Polynomial>(numerator);
    this->denominator = make_shared<Polynomial>(denominator);
}

Quotient::~Quotient(){
//    delete numerator;
//    delete denominator;
}
//!
//!    если функция не определена в точке х, возвращается -123(мусор) и errorCode = 1
//!    иначе возвращается значение функции в точке х и errorCode = 0
//!
double Quotient::getFunctionValue(double x, int &errorCode)const{
    double numeratorValue = (*numerator)(x);
    double denominatorValue = (*denominator)(x);

    if(denominatorValue == 0){
        errorCode = 1;
        return -123;
    }
    errorCode = 0;
    return numeratorValue/denominatorValue;
};

int Quotient::getFunctionAppearance(string & buffer)const{
    string numString;
    string denString;
//!
//!    вызов фунций с проверкой того обе ли функции возвратили 0
//!
    if(numerator->getFunctionAppearance(numString) + denominator->getFunctionAppearance(denString) != 0) return 1;

    if(denString == "0") {
        buffer = "infinity";
        return 0;
    }
    buffer = "( " + numString + " )/( " + denString + " )";

    return 0;
}

Quotient& Quotient::operator=(Quotient const& q){
    if(this == &q) return *this;
////!
////!    здесь вызываются перегруженные операторы =()
////!    так что присваивание безопасное
////!
//    *numerator = *q.numerator;
//    *denominator = *q.denominator;
    numerator = q.numerator;
    denominator = q.denominator;

    return *this;
}

bool Quotient::operator==(Quotient const&q){
//!
//!    если числители и знаменатели совпадают,
//!    то функции считаются одинаковыми
//!
    if(this == &q) return true;
    if( *this->numerator != *q.numerator ) return false;

    return !( *this->denominator != *q.denominator );
}

bool Quotient::operator!=(Quotient const&q){
    return !( *this == q );
}

Quotient* Quotient::clone() const{
    return new Quotient(*this);
}
