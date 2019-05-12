#!/usr/bin/env python3

from decorators import create_pool
from decorators import add_poly
from decorators import add_quot
from decorators import get_objs
from decorators import get_val
from decorators import get_app
from decorators import delete_pool
from decorators import free_objs
from decorators import get_ftype

pool = create_pool()  # Создаю список

arr1 = [1.0, 2.0, 3.0, 4.0]
arr2 = [0.0, 2.0, 0.0, 4.0]

add_poly(pool, arr1)         # Добавляю в список полином
add_poly(pool, arr1)         # Добавляю в список такой же полином
add_quot(pool, arr1, arr2)   # Добавляю в список частное полиномов
fun_arr, n = get_objs(pool)  # Получаю указатель на массив указателей на функции из списка

# Вывод данных
print("Число функций в списке: " + str(n))

for fun_ptr in fun_arr.contents:
    print("Значение функции " + get_app(fun_ptr) + " в точке 1: ")
    print(get_val(fun_ptr, 1))
    print("Тип: " + get_ftype(fun_ptr), '\n')

# Освобождаю память
free_objs(fun_arr)
delete_pool(pool)


