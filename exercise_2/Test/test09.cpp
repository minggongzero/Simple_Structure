//mypric09
#include "test.h"
#include "../mypric09.cpp"
#include <iostream>
using std::cout;
using std::endl;

void test09(){
    char e[9] = {'(',')','(',')','(',')',')','(','#'};
    bool a = panduan(e);
    cout << a;
}
