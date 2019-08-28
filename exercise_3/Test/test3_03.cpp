#include "test.h"
#include "../mypric3_03.cpp"
#include <iostream>

using namespace std;

void test3_03(){
    Queue<int>* que = new Queue<int>(10);
    for(int i=10; i>0; i--)
        que->enQueue(i);
    //QueueSort01(que);
    QueueSort02(que);
    int t;
    while(que->deQueue(t))
        cout << t << endl;
    delete que;
}
