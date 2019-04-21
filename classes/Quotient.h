//
// Created by konstantin on 10.02.19.
//

#ifndef UNTITLED_QUOTIENT_H
#define UNTITLED_QUOTIENT_H


#include <cstdlib>
#include "Polynomial.h"

class Quotient: public Function{
public:
//!
//!    копирующий конструктор
//!
    Quotient(const Quotient&);
//!
//!    обычный конструктор
//!
    Quotient(Polynomial &numerator, Polynomial &denominator);
    ~Quotient() override;
//!
//!    возвращает значение функции в точке х.
//!    если функция в данной точке неопределена,
//!    errorCode = 1(иначе = 0).
//!
    double getFunctionValue(double x, int &errorCode)const override;
//!
//!    кладет в str строковое представление функции.
//!    возвращает 0 в случае успешного завершения и
//!    и 1 в случае ошибки
//!
    int getFunctionAppearance(string &str)const override;
//!
//!    присваивание
//!
    Quotient& operator=(Quotient const&);
//!
//!    создаёт и возвращает копию объекта
//!
    Quotient* clone() const override;
//!
//!    сравнение
//!
    bool operator==(Quotient const&);
    bool operator!=(Quotient const&);

private:
    shared_ptr<Polynomial> numerator;
    shared_ptr<Polynomial> denominator;
};


#endif //UNTITLED_QUOTIENT_H
