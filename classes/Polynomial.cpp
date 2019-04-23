//
// Created by konstantin on 10.02.19.
//
#include "Polynomial.h"
#include <iomanip> // setprecision
#include <sstream> // stringstream

using namespace std;

//!
//! копирующий конструктор
//!
Polynomial::Polynomial(const Polynomial& p){
    coefficients = new double[p.degree + 1];

    for(unsigned int i = 0; i <= p.degree; i++){
        coefficients[i] = p.coefficients[i];
    }

    degree = p.degree;
}

Polynomial::Polynomial(const double *coefficients, unsigned int degree){
    if( coefficients != nullptr ){
        this->coefficients = new double[degree + 1];

        for(unsigned int i = 0; i <= degree; i++){
            this->coefficients[i] = coefficients[i];
        }
    }
    else{
       cerr << "error: Polynomial: wrong input: double*coefficients can't be nullptr" << endl;
       exit(1);
    }

    this -> degree = degree;
}

Polynomial::~Polynomial(){
    delete[] coefficients;
}
//!
//!     нахожу значение многочлена по методу Горнера
//!
double Polynomial::operator()(double x)const{
    double a = coefficients[degree];
    double b = a;
    unsigned int i = degree;

    do{
        a = coefficients[--i];
        b = a + b*x;
    }while( i > 0 );

    return b;
};
//!
//!    Многочлен следует воспринимать как некий ряд Лорана,
//!    поэтому при невалидных monomialDegree (больших степени многочлена)
//!    возвращается ноль. Таким образом нежелательные мономы "не имеют веса".
//!
double Polynomial::operator[](unsigned int monomialDegree)const{
    if( monomialDegree > degree) {
        return 0;
    }

    return coefficients[monomialDegree];
};
//!
//!    функция для округления числа типа double до фиксированного числа знаков после запятой acc
//!    параметры: число типа double, число знаков после запятой
//!    если фукнция вызывается без второго аргументов, то число по умолчанию округляется
//!    до второго знака после запятой
//!
string myRound(double d, const unsigned int acc = 2){
    stringstream stream;
    stream << fixed << setprecision(acc) << d;

    return stream.str();
}

int Polynomial::getFunctionAppearance(string &buffer)const{
//!
//!    ищу первый не нулевой коэффициент
//!
    unsigned int i;
    for(i = 0; (i <= degree) && (coefficients[i] == 0); i++);
//!
//!    если все коэффициенты = 0
//!
    if(i == degree + 1) {
        buffer = "0";
        return 0;
    }
//!
//!    иначе
//!
    buffer = "";

    if(i == 0) buffer+= myRound(coefficients[i]);
    else buffer+= myRound(coefficients[i]) + "x^" + to_string(i);

    for(auto j = i + 1; j <= degree; j++){
        if(coefficients[j] < 0) buffer += " - " + myRound(-coefficients[j]) + "x^" + to_string(j);
        else if(coefficients[j] > 0) buffer += " + " + myRound(coefficients[j]) + "x^" + to_string(j);
    }

    return 0;
}

Polynomial& Polynomial::operator=(Polynomial const& p){
    if(this == &p) return *this;
//!
//!    многочлен пуст
//!
    if(coefficients == nullptr){
        coefficients = new double[p.degree + 1];

        for(unsigned int i = 0; i <= p.degree; i++){
            coefficients[i] = p.coefficients[i];
        }
        degree = p.degree;

        return *this;
    }
//!
//!    иначе
//!
    if(p.degree != degree){
        delete[] coefficients;
        coefficients = new double[p.degree + 1];
    }

    for(unsigned int i = 0; i <= p.degree; i++){
        coefficients[i] = p.coefficients[i];
    }
    degree = p.degree;

    return *this;
}

bool Polynomial::operator!=(Polynomial const& p){
//!
//!    если у полиномов степени и коэффициенты совпадают,
//!    то они считаются равными
//!    иначе они не равны
//!
    if(this == &p) return false;

    for(unsigned int i = 0; i <= degree; i++){
        if(coefficients[i] != p.coefficients[i]) return true;
    }

    return degree != p.degree;
}

bool Polynomial::operator==(Polynomial const & p) {
    return !(*this != p);
}

Polynomial* Polynomial::clone() const {
    return new Polynomial(*this);
}

