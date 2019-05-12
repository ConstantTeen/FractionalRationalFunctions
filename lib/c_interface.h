//
// Created by konstantin on 11.05.19.
//

#ifndef UNTITLED_C_INTERFACE_H
#define UNTITLED_C_INTERFACE_H

#include <new>
#include <cstring>
#include "../tests/test_Polynomial.h"
#include "../tests/test_Quotient.h"
#include "../tests/test_Function.h"
#include "../tests/test_List.h"

extern "C" {

List *create_list();

void delete_list(List *l);
/**
 * Строит и добавляет новый полином в список функций
 * @param l указатель на список функций
 * @param coefficients указатель на массив коэффициентов полинома
 * @param degree степень полинома
 */
void add_polynomial(List *l, double *coefficients, unsigned int degree);
/**
 * Строит и добавляет частное полиномов в список функций
 * @param l указатель на список функций
 * @param numCoef указатель на массив коэффициентов числителя
 * @param numDegree степень числителя
 * @param denCoef указатель на массив коэффициентов знаменателя
 * @param denDegree степень знаменателя
 */
void add_quotient(List *l, double *numCoef, unsigned int numDegree, double *denCoef, unsigned int denDegree);
/**
 * Представляет содержимое в понятном для С виде
 * @param l указатель на список функций
 * @param objs указатель на массив указателей на функции (элементы списка)
 * @param obj_num указатель на число элементов в массиве objs
 */
void get_objects(List *l, Function ***objs, int *obj_num);

void free_objects(Function **objs);
/**
 * Ищет значение функции в точке
 * @param f указатель на функцию (полином или частное)
 * @param x точка, в которой ищется значение
 * @return значение функции в точке
 */
double get_value(Function *f, double x);
/**
 * Строит строковое представление функции
 * @param f указатель на функцию (полином или частное)
 * @param str указатель на строку, в который будет передано строковое представление
 */
void get_appearance(Function *f, char **str);
/**
 * Возвращает тип функции в виде символа
 * @param f указатель на функцию
 * @return тип 'Q' или 'P'
 */
char get_type(Function *f);
/**
 * Выделяет память выделенную под строку
 * @param str
 */
void free_string(char* str);

}

#endif //UNTITLED_C_INTERFACE_H
