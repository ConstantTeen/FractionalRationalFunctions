#include <iostream>
#include "tests/test_Polynomial.h"
#include "tests/test_Quotient.h"
#include "tests/test_Function.h"
#include "tests/test_List.h"
#include "./lib/c_interface.h"
#include "tests/test_c_interface.h"

using namespace std;
//!
//! для подсчёта времени работы программы
//!
static inline unsigned long long int tick()
{
    unsigned long long int d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}

int main() {
    unsigned long long int a = tick();

    test_Polynomial();
    test_Quotient();
    test_Function();
    test_List();
    test_c_interface();
    cout << "All tests have been passed successfully." << endl;
    cout<<tick() - a<<endl;


    return 0;
}
