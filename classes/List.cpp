//
// Created by konstantin on 11.04.19.
//

#include "List.h"

void List::addElement(shared_ptr<Function> &function){
    this->biList.push_back(function); //! добавляем функцию в список
    count.push_back_id();             //! присваиваем ей индекс
}

void List::showEverything(){
    if(biList.empty()){
        cout << endl << "----The list is empty----" << endl << endl;
        return;
    }

    string str;
    unsigned int order = 0;

    cout << endl << "----All list of functions----" << endl << endl;

    for (const auto &item : biList) {

        item->getFunctionAppearance(str);
        cout << "Index: " << count.get_id(order) << endl;
        cout << str << endl;
        order++;
    }
}

int List::deleteElement(unsigned int index){
    unsigned int order = 0;

    for (auto iter = biList.begin(); iter != biList.end(); ++iter,++order) {
        if( count.get_id(order) == (int)index){ //! если индекс тот что нужен
            biList.erase(iter);                 //! удаляем элемент списка
            count.erase_id(index);              //! удаляем соответствующий индекс

            return 0;
        }
    }

    return -1;
}

double List::findValue(double x, unsigned int functionIndex, int& errorCode){
    double value;
    unsigned int order = 0;

    for (const auto &item : biList) {
        if( count.get_id(order) == (int)functionIndex ){
            value = item->getFunctionValue(x,errorCode);

            //! если функция не определена
            if(errorCode == 1) return -122;

            return value;
        }
        order++;
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
    unsigned int order = 0;

    cout << endl << "----All functions undefined in " << x << "----" << endl << endl;

    for (const auto &item : biList) {
        item->getFunctionValue(x,errorCode);

        if(errorCode == 1){
            flag = true;    //! нашлась хотя бы одна фукнция неопределённая в х
            item->getFunctionAppearance(str);

            cout << "Index: " << count.get_id(order) << endl;
            cout << str << endl;
        }
        order++;
    }
    if(!flag) cout << endl << "    There are no such functions    " << endl << endl;

    cout << endl << "----The end----" << endl;
}
