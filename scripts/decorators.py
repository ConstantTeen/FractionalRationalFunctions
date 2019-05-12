#!/usr/bin/env python3

from ctypes import *

c_lib = CDLL('./mylib.so')

c_lib.add_polynomial.argtypes = [
    c_void_p,
    POINTER(c_double),
    c_uint
]
c_lib.add_polynomial.restype = None

c_lib.add_quotient.argtypes = [
    c_void_p,
    POINTER(c_double),
    c_uint,
    POINTER(c_double),
    c_uint
]
c_lib.add_quotient.restype = None

c_lib.get_objects.argtypes = [
    c_void_p,
    POINTER(POINTER(c_void_p)),
    POINTER(c_int)
]
c_lib.get_objects.restype = None

c_lib.free_objects.argtypes = [
    POINTER(c_void_p)
]
c_lib.free_objects.restype = None

c_lib.get_value.argtypes = [
    c_void_p,
    c_double
]
c_lib.get_value.restype = c_double

c_lib.get_appearance.argtypes = [
    c_void_p,
    POINTER(POINTER(c_char))
]
c_lib.get_appearance.restype = None

c_lib.get_type.argtypes = [
    c_void_p
]
c_lib.get_appearance.restype = c_char

c_lib.free_string.argtypes = [
    POINTER(c_char)
]
c_lib.get_appearance.restype = None


def create_pool():
    """Возвращает 'указатель' на список функций"""
    return c_lib.create_list()


def delete_pool(pool):
    """Удаляет список"""
    c_lib.delete_list(pool)


def add_poly(pool, coef):
    """Добавляет полином в список"""
    degree = len(coef) - 1
    carr = (c_double*(degree+1))(*coef)
    cdegree = c_uint(degree)
    c_lib.add_polynomial(pool, carr, cdegree)
    

def add_quot(pool, num_coef, den_coef):
    """Добавляет частное в список"""
    num_degree = len(num_coef)
    cnum = (c_double*(num_degree+1))(*num_coef)
    cnum_degree = c_uint(num_degree)
    den_degree = len(den_coef)
    cden = (c_double*(den_degree+1))(*den_coef)
    cden_degree = c_uint(den_degree)
    c_lib.add_quotient(pool, cnum, cnum_degree, cden, cden_degree)


def get_objs(pool):
    """Создаёт массив 'указателей' на функции из списка"""
    objs = POINTER(c_void_p)()
    objs_num = c_int()
    c_lib.get_objects(pool, byref(objs), byref(objs_num))
    ret_type = POINTER(POINTER(c_void_p) * objs_num.value)
    objs_arr = cast(objs, ret_type)

    return objs_arr, objs_num.value


def free_objs(objs):
    """Удаляет массив функций"""
    c_lib.free_objects(cast(objs, POINTER(c_void_p)))


def get_val(fun, x):
    """Возвращает значение функции"""
    return c_lib.get_value(fun, c_double(x))


def get_app(fun):
    """Возвращает строковое представление функции"""
    cstr = POINTER(c_char)()
    c_lib.get_appearance(fun, byref(cstr))
    s = cast(cstr, c_char_p).value.decode('utf-8')
    c_lib.free_string(cstr)  # Освобождаю строку

    return s


def get_ftype(fun):
    """Возвращает тип функции"""
    return chr(c_lib.get_type(fun))
