//mypric01_Test
#include "test.h"
#include "../mypric01.cpp"
#include <iostream>
void test01(){
    arrList<int> arr01(4);
    arrList<int> arr02(4);
    arr01.my_insert(0, 1);
    arr01.my_insert(1, 2);
    arr01.my_insert(2, 3);
    arr01.my_insert(3, 4);
    arr02.my_insert(0, 1);
    arr02.my_insert(1, 2);
    arr02.my_insert(2, 3);
    arr02.my_insert(3, 4);
    std::cout<<"arr01"<<Compare(arr01, arr02)<<"arr02"<<std::endl;
}
