//
// Created by konstantin on 10.05.19.
//

#include "c_interface.h"

List* create_list(){
    return new (std::nothrow) List;
}

void delete_list(List* l){
    delete l;
}
/**
 * Строит и добавляет новый полином в список функций
 * @param l указатель на список функций
 * @param coefficients указатель на массив коэффициентов полинома
 * @param degree степень полинома
 */
void add_polynomial(List *l, double *coefficients, unsigned int degree){
    auto p = new Polynomial(coefficients,degree);
    auto tmp = make_shared<Function*>(p);
    l->addElement(tmp);
}
/**
 * Строит и добавляет частное полиномов в список функций
 * @param l указатель на список функций
 * @param numCoef указатель на массив коэффициентов числителя
 * @param numDegree степень числителя
 * @param denCoef указатель на массив коэффициентов знаменателя
 * @param denDegree степень знаменателя
 */
void add_quotient(List *l, double *numCoef, unsigned int numDegree, double *denCoef, unsigned int denDegree){
    auto num = new Polynomial(numCoef,numDegree);
    auto den = new Polynomial(denCoef,denDegree);
    auto q = new Quotient(*num,*den);
    auto tmp = make_shared<Function*>(q);
    l->addElement(tmp);
}
/**
 * Представляет содержимое в понятном для С виде
 * @param l указатель на список функций
 * @param objs указатель на массив указателей на функции (элементы списка)
 * @param obj_num указатель на число элементов в массиве objs
 */
void get_objects(List *l, Function ***objs, int *obj_num){
    auto objs_list = l->getList();                  //! копия списка (хотелось бы, но нет)
    *obj_num = objs_list.size();                    //! выявляем число элементов списка
    *objs = new (std::nothrow) Function*[*obj_num]; //! выделяем память под нужное количество элементов
//!
//!    поэлементно копируем список в objs
//!
    int i = 0;
    for (auto it = objs_list.begin(); it != objs_list.end(); ++it, ++i) {
        (*objs)[i] = *( it->get() );
    }
}

void free_objects(Function **objs) {
    delete [] objs;
}
/**
 * Ищет значение функции в точке
 * @param f указатель на функцию (полином или частное)
 * @param x точка, в которой ищется значение
 * @return значение функции в точке
 */
double get_value(Function *f, double x){
    int useless;
    return f->getFunctionValue(x,useless);
}
/**
 * Строит строковое представление функции
 * @param f указатель на функцию (полином или частное)
 * @param str указатель на строку, в который будет передано строковое представление
 */
void get_appearance(Function *f, char** str){
    string tmp;
    f->getFunctionAppearance(tmp);

    *str = new char [tmp.length()+1];
    std::strcpy (*str, tmp.c_str());
}
/**
 * Возвращает тип функции в виде символа
 * @param f указатель на функцию
 * @return тип 'Q' или 'P'
 */
char get_type(Function *f){
    return f->getType();
}