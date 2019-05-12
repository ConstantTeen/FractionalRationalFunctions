//
// Created by konstantin on 12.05.19.
//

#include "test_c_interface.h"
#include "../classes/List.h"
#include "../lib/c_interface.h"

void test_c_interface(){
    cout << "Testing of library..." << endl;

    List* pool = create_list();
    double arr[4] = {1,2,34,3};

    add_polynomial(pool, arr, 3);
    add_quotient(pool, arr, 3, arr, 3);
    pool->showEverything();

    Function** go;
    int n;

    get_objects(pool, &go, &n);
    cout<<get_value(go[0],1)<<endl;

    char* str;
    get_appearance(go[1],&str);
    cout<<str<<endl;
    cout << get_type(go[1])<<endl;

    free_string(str);
    free_objects(go);
    delete_list(pool);

    cout << "Done." << endl;
}
