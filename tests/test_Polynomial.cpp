//
// Created by konstantin on 12.02.19.
//
#include "test_Polynomial.h"

void test_Polynomial(){
    cout << "Testing of Polynomial..." << endl;

    double arr[9] = {1,2,3,4,5,6,7,8,9};
    Polynomial p(arr,8);
    unsigned int degree = p.getDegree();
    Function *f = &p;
    int l;

    f->getFunctionValue(0.0, l);

    if( p[123] != 0 || p[-123] != 0 ){
        cout << "test: Polynomial: wrong data handling of operator []" << endl;
        exit(1);
    }
    if(degree != 8){
        cout << "test: Polynomial: variable degree is not working" << endl;
        exit(1);
    }
    if(p[8] != 9){
        cout << "test: Polynomial: variable coefficients is not working" << endl;
        exit(1);
    }
    if(p(1) != 45){
        cout << "test: Polynomial: operator () is not working" << endl;
        exit(1);
    }
    if(p[8] != 9){
        cout << "test: Polynomial: operator [] is not working" << endl;
        exit(1);
    }

    double arr2[3] = {3,2,3};

    Polynomial pp(arr2,2);

    p = pp;

    if( !(p == pp) || !(p == p) ){
        cerr << "test: Polynomial: operator==()" << endl;
        exit(1);
    }
    if( p != pp || p != p ){
        cerr << "test: Polynomial: operator!=()" << endl;
        exit(1);
    }
    if(p.getDegree() != 2){
        cerr << "test: Polynomial: variable degree is not working" << endl;
        exit(1);
    }
    if(p[2] != 3){
        cerr << "test: Polynomial: variable coefficients is not working" << endl;
        exit(1);
    }
    if(p(1) != 8){
        cerr << "test: Polynomial: operator () is not working" << endl;
        exit(1);
    }

    Polynomial qwe(arr,8);

    cout << "Done." << endl;
}



