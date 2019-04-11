#include <iostream>
//#include "tests/test_Pool.h"
#include "tests/test_Polynomial.h"
#include "tests/test_QuotientOfPolynomials.h"
#include "tests/test_Function.h"
#include "tests/test_List.h"

using namespace std;

int main() {
    test_Polynomial();
    test_QuotientOfPolynomials();
    test_Function();
//    test_Pool();
    test_List();
    cout << "All tests have been passed successfully." << endl;

    return 0;
}
