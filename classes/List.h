//
// Created by konstantin on 11.04.19.
//

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

#include <memory>
#include <list>
#include <string>

#include"Function.h"
#include "Counter.h"

using namespace std;

class List {
public:
//!
//!    добавляет дробно-рациональную функцию в список
//!
    void addElement(shared_ptr<Function> &function);
//!
//!   печатает весь существующий список функций
//!
    void showEverything();
//!
//!    удаляет элемент списка
//!    возвращает 0 при успешном удалении
//!    1, если функции с таким инексом нет в списке
//!    -1 - неожиданное поведение
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

    const list< shared_ptr<Function> >& getList() const {
        return biList;
    }

private:
    list< shared_ptr<Function> > biList;   //! список функций
    Counter count;                          //! список индексов, соответсвующих функциям из списка
};


#endif //UNTITLED_LIST_H
