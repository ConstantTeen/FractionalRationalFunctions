//
// Created by konstantin on 10.02.19.
//

#ifndef UNTITLED_POOL_H
#define UNTITLED_POOL_H

#include "Function.h"
#include "Polynomial.h"
#include "Quotient.h"


//!
//!   Циклический список, содержащий указатели на
//!   дробно-рациональные функции
//!
struct list{
    unsigned int index;
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
//!    удаляет элемент списка
//!    возвращает 0 при успешном удалении
//!    и 1, если функции с таким инексом нет в списке
//!
    int deleteElement(unsigned int index);
//!
//!    находит значение функции
//!    с индексом functionIndex в точке х
//!
    double findValue(double x, unsigned int functionIndex, int& errorCode);
//!
//!    выводит индексы всех функций в хранилище
//!    не определенных в точке х
//!
    void undefinedFunctionsSet(double x);


private:
    unsigned int counter = 1;//! хранит последний индекс
    struct list *root = nullptr;//! указатель на корневой элемент списка
//!
//!     создаёт первый элемент(корень) списка
//!
    void init(const Function *function);
};


#endif //UNTITLED_POOL_H
