//mypric07
#include "test.h"
#include "../mypric07.cpp"
#include <iostream>
using std::cout;
using std::endl;

void test07(){
    int i=0, j;
    arrList<int> arr01(4);
    arrList<int> arr02(4);
    arrList<int> arr03(4);
    arr01.my_insert(0, 1);
    arr01.my_insert(1, 2);
    arr01.my_insert(2, 3);
    arr01.my_insert(3, 4);
    arr02.my_insert(0, 1);
    arr02.my_insert(1, 1);
    arr02.my_insert(2, 3);
    arr02.my_insert(3, 5);

    qujiaoji(&arr01, &arr02, &arr03);
    while(i<arr03.length())
    {
        arr03.getValue(i, j);
        cout << j << endl;
        ++i;
    }
}
