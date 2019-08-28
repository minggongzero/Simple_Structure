#include "test.h"
#include "../mypric3_04.cpp"
#include <iostream>

using namespace std;

void test3_04(){
    arrStack<int>* s1 = new arrStack<int>(5);
    arrStack<int>* s2 = new arrStack<int>(5);
    int i;
    for(i=0; i<5; i++)
        s1->push(i);
    //s1->pop(i);
    //s1->pop(i);
    //s1->push(11);
    //s1->push(21);
    stack_transfer02(s1, s2);
    while(s2->pop(i))
        cout << i << endl;
    delete s2;
    delete s1;
}
