//
// Created by konstantin on 12.02.19.
//

#include "test_Quotient.h"

void test_Quotient(){
    cout << "Testing of Quotient..." << endl;

    double arr1[3] = {1,2,3};
    double arr2[5] = {5,4,3,2,1};
    Polynomial p1(arr1,2);
    Polynomial p2(arr2,4);
    Quotient q(p1,p2);
    int errorCode = 0;
//!
//!    проверка getFunctionValue
//!
    double value = q.getFunctionValue(1.0, errorCode);

    if( errorCode || (value != 0.4) ){
        cerr << "test: Quotient: wrong value of function has been gotten by method getFunctionValue(...)" << endl;
        exit(1);
    }
//!
//!    проверка на функции с нулевым знаменателем
//!
    double arr[4] = {0,1,1,0};
    Polynomial p(arr,3);
    Quotient qq(p1,p);

    qq.getFunctionValue(0.0, errorCode);

    if( qq == q ){
        cerr << "test: Quotient: operator!=()" << endl;
        exit(1);
    }
    if( q != q ){
        cerr << "test: Quotient: operator!=()" << endl;
        exit(1);
    }
    if(errorCode != 1){
        cout << "test: Quotient: wrong value of function has been gotten by method getValueFunction(...)" << endl;
        exit(1);
    }
//!
//!    проверка оператора=()
//!
    qq = q;
    value = qq.getFunctionValue(1.0, errorCode);

    if( !(qq == q) ){
        cerr << "test: Quotient: operator==()" << endl;
        exit(1);
    }
    if( errorCode || (value != 0.4) ){
        cerr << "test: Quotient: assignment error" << endl;
        exit(1);
    }
//!
//!    проверка копирующего конструктора
//!
    auto *qqq = new Quotient(q);
    value = qqq->getFunctionValue(1.0, errorCode);

    if( errorCode || (value != 0.4) ){
        cerr << "test: Quotient: assignment error" << endl;
        exit(1);
    }

    delete qqq;
    cout << "Done." << endl;
}