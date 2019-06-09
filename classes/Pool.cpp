//
// Created by konstantin on 10.02.19.
//

#include <iostream>
#include "Pool.h"

using namespace std;

Pool::~Pool(){
    struct list *m = root;
    struct list *n;

    do{
        n = m->next;
        delete m->function;
        delete m;
        m = n;
    }while(m != root);
}

void Pool::init(const Function *function){
//!
//!    создание корневого элемента списка
//!    присвоение индекса функции function
//!
    root = new struct list;
    root->next = root;
    root->function = function->clone();
    root->index = counter++;
}

void Pool::addElement(const Function *function){
//!
//!    в случае, если в хранилище нет элементов,
//!    передаю работу функции init()
//!
    if(counter == 1){
        init(function);
        return;
    }
//!
//!    иначе освобождаю память под новый элемент и
//!    с помощью вспомогоательного указателя m
//!    добавляю новый элемент в список
//!
    auto *newElement = new struct list;
    struct list *m;

    m = root->next;
    root->next = newElement;
    newElement->function = function->clone();
    newElement->index = counter++;
    newElement->next = m;
}

int Pool::deleteElement(const unsigned int index){
//!     если нужно удалить последний оставшийся элемент списка
    if(root->next == root && root->index == index) {
        counter = 1;
        delete root->function;
        delete root;
        root = nullptr;

        return 0;
    }

    auto m = root;

    while(m->next->index != index){ // ищем нужный элемент
        m = m->next;
        if(m == root) return 1;     // если обошёл весь список но не нашел такого индекса
    }

    auto isRoot = (m->next == root);
    auto n = m->next->next;

    delete m->next->function;
    delete m->next;
    m->next = n;
    if(isRoot) root = n;

    return 0;
}

double Pool::findValue(double x, unsigned int functionIndex, int& errorCode){
//!
//!   функции с данным индексом нет
//!
    if(counter < functionIndex){
        errorCode = -1;
        return -123;
    }

    struct list *m = root;
    double value = 0;
    Function *currentFunction;
    unsigned int currentIndex;

    do{
        currentFunction = m->function;
        currentIndex = m->index;

        if(currentIndex == functionIndex){
            value = currentFunction->getFunctionValue(x,errorCode);

            //! если функция не определена
            if(errorCode == 1) return -123;

            return value;
        }

        m = m->next;
    }while(m != root);
//!
//!    по каким-то причинам функции с данным
//!    индексом нет
//!
    errorCode = -1;
    return -123;
}

void Pool::showEverything(){
    if(root == nullptr){
        cout << endl << "----The list is empty----" << endl << endl;
        return;
    }
//!
//!    обход списка с помощью вспомогательного
//!    указателя на структуру m
//!    и вывод функций из списка
//!
    cout << endl << "----All list of functions----" << endl << endl;

    struct list *m = root;
    auto index = m->index;
    string str;

    do{
        cout << "Index: " << index << endl;

        m->function->getFunctionAppearance(str);
        cout << str << endl;

        m = m->next;
        index = m->index;
    }while(m != root);

    cout << endl << "----The end----" << endl;
}

void Pool::undefinedFunctionsSet(double x){
    if(root == nullptr){
        cout << endl << "----The list is empty----" << endl << endl;
        return;
    }

    cout << endl << "----All functions undefined in " << x << "----" << endl << endl;

    struct list *m = root;
    int errorCode = 0;
    string str;
    bool flag = false;

    do{
        m->function->getFunctionValue(x,errorCode);

        if(errorCode == 1){
            flag = true;
            m->function->getFunctionAppearance(str);
            errorCode = 0;

            cout << "Index: " << m->index << endl;
            cout << str << endl;
        }

        m = m->next;
    }while(m != root);

    if(!flag) cout << endl << "    There are no such functions    " << endl << endl;

    cout << endl << "----The end----" << endl;
}

void Pool::filling(int number) {
    int i = 0;
    for(; i < number/2; i++){
        double arr[4] = {(double)i, (double)i/2, (double)i/3, (double)i};
        Polynomial p(arr,3);

        this->addElement(&p);
    }

    for(; i < number; i++){
        double arr[4] = {(double)i, (double)i/2, (double)i/3, (double)i};
        Polynomial p(arr,3);
        double arr2[3] = {(double)i/2, (double)i/3, (double)i*2};
        Polynomial p2(arr2,2);
        QuotientOfPolynomials q(p,p2);

        this->addElement(&q);
    }
}
