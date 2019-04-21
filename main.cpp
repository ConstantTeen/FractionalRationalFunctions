#include <iostream>
//#include "tests/test_Pool.h"
#include "tests/test_Polynomial.h"
#include "tests/test_Quotient.h"
#include "tests/test_Function.h"
#include "tests/test_List.h"

using namespace std;
//!
//! для водсчёта времени работы программы
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
////    test_Pool();
    test_List();
    cout << "All tests have been passed successfully." << endl;

    cout<<tick() - a<<endl;

    return 0;
}
