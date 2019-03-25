//
// Created by konstantin on 01.03.19.
//

#ifndef UNTITLED_FUNCTION_H
#define UNTITLED_FUNCTION_H
#include <iostream>
using namespace std;

class Function {
public:
    Function() = default;
    virtual ~Function() = default;
//!
//!    возвращает значение функции в точке х
//!    если функция в данной точке не определена,
//!    присваивает errorCode 1
//!    иначе 0
//!
    virtual double getFunctionValue(double x, int &errorCode) = 0;
//!
//!    служит для преобразования функции в строку для последующего вывода
//!    возвращает 0 в случае успеха и 1, если знаменатель тождественно = 0
//!
    virtual int getFunctionAppearance(string &) = 0;
//!
//!    создаёт и возвращает копию объекта
//!
    virtual Function* clone() = 0;
};


#endif //UNTITLED_FUNCTION_H
