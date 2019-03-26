//
// Created by konstantin on 10.02.19.
//

#ifndef UNTITLED_QUOTIENTOFPOLYNOMIALS_H
#define UNTITLED_QUOTIENTOFPOLYNOMIALS_H


#include <cstdlib>
#include "Polynomial.h"

class QuotientOfPolynomials: public Function{
public:
//!
//!    копирующий конструктор
//!
    QuotientOfPolynomials(const QuotientOfPolynomials&);
//!
//!    обычный конструктор
//!
    QuotientOfPolynomials(Polynomial &numerator, Polynomial &denominator);
    ~QuotientOfPolynomials() override;
//!
//!    возвращает значение функции в точке х.
//!    если функция в данной точке неопределена,
//!    errorCode = 1(иначе = 0).
//!
    double getFunctionValue(double x, int &errorCode) override;
//!
//!    кладет в str строковое представление функции.
//!    возвращает 0
//!
    int getFunctionAppearance(string &str) override;
//!
//!    присваивание
//!
    QuotientOfPolynomials& operator=(QuotientOfPolynomials const&);
//!
//!    создаёт и возвращает копию объекта
//!
    QuotientOfPolynomials* clone() const override;
//!
//!    сравнение
//!
    bool operator==(QuotientOfPolynomials const&);
    bool operator!=(QuotientOfPolynomials const&);

private:
    Polynomial *numerator = nullptr;
    Polynomial *denominator = nullptr;
};


#endif //UNTITLED_QUOTIENTOFPOLYNOMIALS_H
