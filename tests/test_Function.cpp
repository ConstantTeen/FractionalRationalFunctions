//
// Created by konstantin on 02.03.19.
//

#include "test_Function.h"

void test_Function(){
    cout << "Testing of Function..." << endl;

    double arr1[3] = {1,2,3};
    Polynomial p1(arr1, 2);
    double arr2[2] = {1,2};
    double arr3[2] = {2,1};
    Polynomial p2(arr2, 1);
    Polynomial p3(arr3, 1);
    Quotient q(p1,p2);
    Function *f;
    int errorCode = 0;

    f = &p1;
    if(f->getFunctionValue(0.0,errorCode) != 1){
        cerr << "test: Function: inheritance Polynomial error" << endl;
        exit(1);
    }
    f = &q;
    if(f->getFunctionValue(0.0,errorCode) != 1){
        cerr << "test: Function: inheritance Quotient error" << endl;
        exit(1);
    }
    cout << "Done." << endl;
}
