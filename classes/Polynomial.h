//
// Created by konstantin on 10.02.19.
//

#ifndef UNTITLED_POLYNOMIAL_H
#define UNTITLED_POLYNOMIAL_H

#include <stdexcept>
#include <math.h>
#include <memory>
#include "Function.h"


class Polynomial: public Function{
private:
    char type = 'P';
//!
//!    степень многочлена
//!
    unsigned int degree;
//!
//!    указатель на массив коэффициентов полинома
//!
    double *coefficients;

public:
    Polynomial(const double *coefficients, unsigned int degree);
    Polynomial(const Polynomial&);
    ~Polynomial()override;
//!
//!    возвращает степень полинома
//!
    inline unsigned int getDegree(){ return degree; };
//!
//!    перегруженный оператор () служит для нахождения
//!    значения полинома в точке
//!
    double operator()(double x)const;
//!
//!    перегруженный оператор [] возвращает
//!    коэффициент при мономе степени monomialDegree
//!
    double operator[](unsigned int monomialDegree)const;
//!
//!    ищет значение полинома в точке x
//!
    inline double getFunctionValue(double x, int& ) const override { return (*this)(x); }
//!
//!    кладет в buffer строку с явным видом полинома
//!    и возвращает код ошибки
//!
    int getFunctionAppearance(string &buffer)const override;
//!
//!    присваивание полиномов
//!
    Polynomial& operator=(Polynomial const&);
//!
//!    создаёт и возвращает копию объекта
//!
    Polynomial* clone() const override;
//!
//!    сравнение полиномов
//!
    bool operator!=(Polynomial const&);
    bool operator==(Polynomial const &);
    char getType()const override {return type;}
};


#endif //UNTITLED_POLYNOMIAL_H
