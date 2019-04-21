//
// Created by konstantin on 11.04.19.
//

#include "List.h"

void List::addElement(Function *function){
    this->biList.push_back(function);
}

void List::showEverything(){
    if(biList.empty()){
        cout << endl << "----The list is empty----" << endl << endl;
        return;
    }

    unsigned int currentIndex = 1;
    string str;

    cout << endl << "----All list of functions----" << endl << endl;

    for (const auto &item : biList) {
        item->getFunctionAppearance(str);
        cout << "Index: " << currentIndex++ << endl;
        cout << str << endl;
    }
}

int List::deleteElement(unsigned int index){
    if(biList.size() < index || index == 0) return 1;

    unsigned int currentIndex = 1;

    for (auto iter = biList.begin(); iter != biList.end(); ++iter,++currentIndex) {
        if(currentIndex == index){
            biList.erase(iter);
            return 0;
        }
    }
    return -1;
}

double List::findValue(double x, unsigned int functionIndex, int& errorCode){
//!
//!   функции с данным индексом нет
//!
    if(biList.size() < functionIndex){
        errorCode = -1;
        return -123;
    }

    unsigned int currentIndex = 1;
    double value;

    for (const auto &item : biList) {
        if(currentIndex == functionIndex){
            value = item->getFunctionValue(x,errorCode);

            //! если функция не определена
            if(errorCode == 1) return -123;

            return value;
        }
        currentIndex++;
    }
//!
//!    по каким-то причинам функции с данным
//!    индексом нет
//!
    errorCode = -1;
    return -123;
}

void List::undefinedFunctionsSet(double x){
    if(biList.empty()){
        cout << endl << "----The list is empty----" << endl << endl;
        return;
    }

    int errorCode = 0;
    string str;
    bool flag = false;
    unsigned int currentIndex = 1;

    cout << endl << "----All functions undefined in " << x << "----" << endl << endl;

    for (const auto &item : biList) {
        item->getFunctionValue(x,errorCode);

        if(errorCode == 1){
            flag = true;
            item->getFunctionAppearance(str);

            cout << "Index: " << currentIndex << endl;
            cout << str << endl;

            currentIndex++;
        }
    }
    if(!flag) cout << endl << "    There are no such functions    " << endl << endl;

    cout << endl << "----The end----" << endl;
}
