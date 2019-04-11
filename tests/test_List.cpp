//
// Created by konstantin on 11.04.19.
//

#include "test_List.h"

void test_List(){
    cout << "Testing of List..." << endl;
//!
//!   массивы arr... - наборы коэффициентов будущих полиномов
//!   место коэффициента в массиве соответствует степени
//!   монома, при котором этот коэффициент стоит
//!
    double arr1[3] = {1,2,3};
    double arr2[5] = {5,4,3,2,1};
    double arr[4] = {0,1,1,0};
    Polynomial p1(arr1,2);
    Polynomial p2(arr2,4);
    Polynomial p(arr,3);
    QuotientOfPolynomials q(p1,p2);
    QuotientOfPolynomials qq(p1,p);
    Function *fp1 = &p1;
//    Function *fp2 = &p2;
    Function *fq = &q;
    Function *fqq = &qq;
    List list;
//!
//!   добавляю элемент и проверяю добавился ли
//!
    list.addElement(fp1);
    int errorCode = 0;
    double value = list.findValue(0.0,1,errorCode);

    if(value != 1){
        cerr << "test: List: wrong way of function value calculating" << endl;
        exit(1);
    }
    else if(errorCode == -1){
        cerr << "test: List: wrong way of indexes  storage" << endl;
        exit(1);
    }
//!
//!   проверка правильности удаления функций
//!
    if( list.deleteElement(1) == 1 ){
        cerr << "test: List: wrong way of indexes storage" << endl;
        exit(1);
    }
//!
//!   добавляю ещё элемент и проверяю добавился ли
//!
    list.addElement(fq);
    list.findValue(0.0,123,errorCode);

    if(errorCode != -1){
        cerr << "test: List: wrong way of indexes storage" << endl;
        exit(1);
    }
//!
//!   и ещё раз
//!
    list.addElement(fqq);
    list.findValue(0.0,2,errorCode);

    if(errorCode != 1){
        cerr << "test: List: wrong way of data storage" << endl;
        exit(1);
    }
//!
//!   проверка работы функций showEverything
//!   и notDefinedFunctionsSet
//!
    list.showEverything();
    list.undefinedFunctionsSet(0.0);
    list.undefinedFunctionsSet(1.0);

    cout << "Done." << endl;
}
