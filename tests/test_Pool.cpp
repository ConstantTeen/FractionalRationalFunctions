////
//// Created by konstantin on 13.02.19.
////
//
//#include "test_Pool.h"
//
//void test_Pool(){
//cout << "Testing of Pool..." << endl;
//
////!
////!   массивы arr... - наборы коэффициентов будущих полиномов
////!   место коэффициента в массиве соответствует степени
////!   монома, при котором этот коэффициент стоит
////!
//    double arr1[3] = {1,2,3};
//    double arr2[5] = {5,4,3,2,1};
//    double arr[4] = {0,1,1,0};
//    Polynomial p1(arr1,2);
//    Polynomial p2(arr2,4);
//    Polynomial p(arr,3);
//    Quotient q(p1,p2);
//    Quotient qq(p1,p);
//    Function *fp1 = &p1;
////    Function *fp2 = &p2;
//    Function *fq = &q;
//    Function *fqq = &qq;
//    Pool pool;
////!
////!   добавляю элемент и проверяю добавился ли
////!
//    pool.addElement(fp1);
//    int errorCode = 0;
//    double value = pool.findValue(0.0,1,errorCode);
//
//    if(value != 1){
//        cerr << "test: Pool: wrong way of function value calculating" << endl;
//        exit(1);
//    }
//    else if(errorCode == -1){
//        cerr << "test: Pool: wrong way of indexes  storage" << endl;
//        exit(1);
//    }
////!
////!   проверка правильности удаления функций
////!
//    if( pool.deleteElement(1) == 1 ){
//        cerr << "test: Pool: wrong way of indexes storage" << endl;
//        exit(1);
//    }
////!
////!   добавляю ещё элемент и проверяю добавился ли
////!
//    pool.addElement(fq);
//    pool.findValue(0.0,123,errorCode);
//
//    if(errorCode != -1){
//        cerr << "test: Pool: wrong way of indexes storage" << endl;
//        exit(1);
//    }
////!
////!   и ещё раз
////!
//    pool.addElement(fqq);
//    pool.findValue(0.0,2,errorCode);
//
//    if(errorCode != 1){
//        cerr << "test: Pool: wrong way of data storage" << endl;
//        exit(1);
//    }
////!
////!   проверка работы функций showEverything
////!   и notDefinedFunctionsSet
////!
//    pool.showEverything();
//    pool.undefinedFunctionsSet(0.0);
//    pool.undefinedFunctionsSet(1.0);
//
//cout << "Done." << endl;
//}