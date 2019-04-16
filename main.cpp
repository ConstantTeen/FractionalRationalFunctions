#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <fstream>

//#include "tests/test_Pool.h"
//#include "tests/test_Polynomial.h"
//#include "tests/test_QuotientOfPolynomials.h"
//#include "tests/test_Function.h"
//#include "tests/test_List.h"

#include "classes/Pool.h"

#define ACTIONNUM 6
#define BUFFERSIZE 100

using namespace std;

struct pol{
    unsigned int degree;
    double *coef;
};

int countEverything(string&,double,Pool&);
int parseAndCount(string&,string&,double,Pool&);
int parseAndDelete(string&,Pool&);
int parseAndPush(Pool &,char*);
void sayHi();
int addNewFunctions(Pool &,string &);
struct pol* parsePolynomial(char *);
int parseAndShow(string&,Pool&);

int main() {
    setlocale(LC_ALL, "Russian");
//    test_Polynomial();
//    test_QuotientOfPolynomials();
//    test_Function();
// //    test_Pool();
//    test_List();
//    cout << "All tests have been passed successfully." << endl;

    sayHi();
    return 0;
}

void sayHi(){
    Pool list;
    string answer;
    string inputFile;
    string outputFile;
    string indexesStr;
    int code;
    double x;

    while(true){
        cout << endl << "Выберите действие:\n"
                "1 - Добавить новые функции из файла в хранилище \n"
                "2 - Удалить функции из хранилища\n"
                "3 - Вывести все функции из хранилища\n"
                "4 - Найти значения функций в хранилище в точке и вывести их в файл\n"
                "5 - Вывести все функции хранилища неопределённые в данной точке\n"
                "0 - Выход" << endl;
        cin >> answer;
        try {
            code = stoi(answer); // если по ошибке(или нет) введен дабл, то он округляется до целого
        }
        catch (invalid_argument& e){
            cout << "Попробуйте ввести цифру!" << endl;
            continue;
        }catch (out_of_range& e){
            cout << "Попробуйте ввести цифру из перечня!" << endl;
            continue;
        }

        if(code > ACTIONNUM || code < 0){
            cout << "Попробуйте ввести цифру из перечня!" << endl;
            continue;
        }
        if(code == 0) break;

        switch (code){
            case 1:
                try {
                    cout << "Имя файла:";
                    cin >> inputFile;
                    addNewFunctions(list,inputFile);
                }catch(...){
                    cerr << "error" << endl;
                }
                break;
            case 2:
                try {
                    cout << "Индексы функций: ";
                    cin >> indexesStr;
                    parseAndDelete(indexesStr,list);
                }catch(...){
                    cerr << "error" << endl;
                }
                break;
            case 3:
//                cout << "Имя файла:";
//                cin >> outputFile;
                try {
                    list.showEverything();
                }catch(...){
                    cerr << "error" << endl;
                }
                break;
            case 4:
                try {
                cout << "Имя файла:";
                cin >> outputFile;
                cout << "Индексы функций: ";
                cin >> indexesStr;
                cout << "Точка: ";
                cin >> x;
                parseAndCount(outputFile,indexesStr,x,list);
                }catch(...){
                    cerr << "error" << endl;
                }
                break;
            case 5:
                try {
//                    cout << "Имя файла:";
//                    cin >> outputFile;
                    cout << "Точка: ";
                    cin >> x;
                    list.undefinedFunctionsSet(x);
                }catch(...){
                    cerr << "error" << endl;
                }
                break;
            default:
                break;
        }
    }
}
//
//int countEverything(string& file,double x,Pool& list){
//
//}


int parseAndCount(string& file,string& str,double x,Pool& list){
    string delim(",");
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();
    int errorCode = 0;

    ofstream out(("../Files/" + file).c_str(), ios::app);
    if (out.is_open()){


        while( ( next = str.find( delim, prev ) ) != string::npos ){
            string tmp = str.substr( prev, next-prev );
            size_t next2 = tmp.find(string("-"));

            if(next2 == string::npos){
                int index = atoi(tmp.c_str());
                double value = list.findValue(x,index,errorCode);

                if(errorCode == 1) out << index << " " << "inf" << endl;
                else if(errorCode == 0) out << index << " " << value << endl;

                prev = next + delta;
                continue;
            }

            int a = atoi(tmp.substr(0, next2).c_str());
            int b = atoi(tmp.substr(next2 + 1).c_str());

            for (int i = a; i <= b; ++i) {
                double value = list.findValue(x,i,errorCode);

                if(errorCode == 1) out << i << " " << "inf" << endl;
                else if(errorCode == 0) out << i << " " << value << endl;
            }

            prev = next + delta;
        }
        //Отладка-start
        string tmp = str.substr( prev );
        size_t next2 = tmp.find(string("-"));

        if(next2 == string::npos){
            int index = atoi(tmp.c_str());
            double value = list.findValue(x,index,errorCode);

            if(errorCode == 1) out << index << " " << "inf" << endl;
            else if(errorCode == 0) out << index << " " << value << endl;

            return 0;
        }

        int a = atoi(tmp.substr(0, next2).c_str());
        int b = atoi(tmp.substr(next2 + 1).c_str());

        for (int i = a; i <= b; ++i) {
            double value = list.findValue(x,i,errorCode);

            if(errorCode == 1) out << i << "inf" << endl;
            else if(errorCode == 0) out << i << value << endl;
        }
    }

    out.close();

    return 0;
}


int parseAndDelete(string &str,Pool &list){
    string delim(",");
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while( ( next = str.find( delim, prev ) ) != string::npos ){
        string tmp = str.substr( prev, next-prev );
        size_t next2 = tmp.find(string("-"));

        if(next2 == string::npos){
            list.deleteElement(atoi(tmp.c_str()));
            prev = next + delta;
            continue;
        }

        int a = atoi(tmp.substr(0, next2).c_str());
        int b = atoi(tmp.substr(next2 + 1).c_str());

        for (int i = a; i <= b; ++i) {
            list.deleteElement(i);
        }

        prev = next + delta;
    }
    //Отладка-start
    string tmp = str.substr( prev );
    size_t next2 = tmp.find(string("-"));

    if(next2 == string::npos){
        list.deleteElement(atoi(tmp.c_str()));
        return 0;
    }

    int a = atoi(tmp.substr(0, next2).c_str());
    int b = atoi(tmp.substr(next2 + 1).c_str());

    for (int i = a; i <= b; ++i) {
        list.deleteElement(i);
    }

    return 0;
}



int addNewFunctions(Pool &list,string &inputFile){
    FILE *pFile;
    char buffer[BUFFERSIZE];

    pFile = fopen(("../Files/" + inputFile).c_str() , "rb");

    if (pFile == nullptr){
        cerr << "error: не удалось открыть файл" << endl;
        return 1;
    }
    else{
        while ( !feof(pFile) ){
            if ( fgets (buffer , BUFFERSIZE , pFile) == nullptr ) break;
            parseAndPush(list,buffer);
        }

        fclose (pFile);
    }
    return 0;
}

int parseAndPush(Pool &list,char *buffer){
    struct pol* num;
    struct pol* den;

    if(strchr(buffer,'/') == nullptr){
        num = parsePolynomial(buffer);
        list.addElement(new Polynomial(num->coef,num->degree));

        delete[] num->coef;
        delete num;

        return 0;
    }

    char* numeratorStr;
    char* denominatorStr;

    numeratorStr = strtok(buffer,"/");
    denominatorStr = strtok (nullptr, "/");

    num = parsePolynomial(numeratorStr);
    den = parsePolynomial(denominatorStr);
    Polynomial numerator(num->coef,num->degree);
    Polynomial denominator(den->coef,den->degree);

    list.addElement(new QuotientOfPolynomials(numerator,denominator));

    delete[] num->coef;
    delete num;
    delete[] den->coef;
    delete den;

    return 0;
}

struct pol* parsePolynomial(char *str){
    char *p = strtok(str," ");
    int degree = atoi(p);

    p = strtok(nullptr, " ");
    auto coef = new double[degree + 1];

    for(int i = 0; i <= degree; i++){
        coef[i] = atof(p);
        p = strtok(nullptr, " ");
    }

    auto s = new struct pol;
    s->degree = degree;
    s->coef = coef;

    return s;
}
