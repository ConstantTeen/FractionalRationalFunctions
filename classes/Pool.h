//
// Created by konstantin on 10.02.19.
//

#ifndef UNTITLED_POOL_H
#define UNTITLED_POOL_H

#include "Function.h"
#include "Polynomial.h"
#include "QuotientOfPolynomials.h"

//!
//!   Циклический список, содержащий указатели на
//!   дробно-рациональные функции
//!
struct list{
    int index;
    Function *function;
    struct list *next;
};

class Pool{
public:
    ~Pool();
//!
//!   печатает весь существующий список функций
//!
    void showEverything();
//!
//!    добавляет дробно-рациональную функцию в список
//!    либо если список пуст создает его
//!
    void addElement(const Function *function);
//!
//!    удаляет элемент списка(пока юзлес)
//!
    int deleteElement(int index);
//!
//!    находит значение функции
//!    с индексом functionIndex в точке х
//!
    double findValue(double x, int functionIndex, int& errorCode);
//!
//!    выводит индексы всех функций в хранилище
//!    не определенных в точке х
//!
    void undefinedFunctionsSet(double x);


private:
    int counter = 1;//! хранит последний индекс
    struct list *root = nullptr;//! указатель на корневой элемент списка
//!
//!     создаёт первый элемент(корень) списка
//!
    void init(const Function *function);
};


#endif //UNTITLED_POOL_H
