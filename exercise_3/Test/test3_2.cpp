#include "test.h"
#include "../mypric3_2.cpp"
#include <iostream>

using namespace std;

void test3_2(){
    SpQueue<int> spq(5);
    int i;
    for(i=0; i<5; i++)
        spq.enqueue(i);
    spq.dequeue(i);
    spq.dequeue(i);
    spq.enqueue(5);
    spq.enqueue(6);
    while(spq.dequeue(i))
        cout << i << endl;
}
