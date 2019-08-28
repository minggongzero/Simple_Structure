#include "test.h"
#include "../mypric3_5.cpp"
#include <iostream>

using namespace std;

void test3_5(){
    TBqueue<int> *tbq = new TBqueue<int>();
    int i;
    for(i=5; i>0; i--)
        tbq->enqueue(i);
    tbq->enqueue(6);
    tbq->enqueue(7);
    while(!tbq->isEmpty()){
        tbq->dequeue(i);
        cout << i << endl;
    }
    delete tbq;
}
