#include <iostream>
#include "tests/test_Pool.h"
#include "tests/test_Polynomial.h"
#include "tests/test_QuotientOfPolynomials.h"
#include "tests/test_Function.h"

using namespace std;

int main() {
    test_Polynomial();
    test_QuotientOfPolynomials();
    test_Function();
    test_Pool();
    cout << "All tests have been passed successfully." << endl;

    return 0;
}
