//
// Created by konstantin on 23.04.19.
//

#ifndef UNTITLED_COUNTER_H
#define UNTITLED_COUNTER_H

#include <vector>

using namespace std;

class Counter {
public:
//!
//!    добавить новый индекс
//!
    void push_back_id();
//!
//!    удалить order+1'й индекс
//!
    void delete_id(unsigned int order);
//!
//!    удалить индекс = index
//!
    void erase_id(unsigned int index);
//!
//!    вернуть место в списке индекса id (если считать с нуля)
//!
    int get_order(unsigned int id);
//!
//!    вернуть индекс стоящий на order+1'м месте
//!
    int get_id(unsigned int order);

private:
//!
//!    порядок индексов такой же как и в списке функций
//!    которым соответствуют индексы
//!
    vector<unsigned int> ids;
    unsigned int counter = 0;
};


#endif //UNTITLED_COUNTER_H
