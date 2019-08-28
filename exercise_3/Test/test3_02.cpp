//mypric3_02
#include "test.h"
#include "../mypric3_02.cpp"
#include <iostream>

using namespace std;

void test3_02(){
    Deque<int> deq(5);
    int tmp, i;
    for(i=0; i<5; i++)
        deq.left_inster(i);
    while(i-- > 0){
        deq.left_delete(tmp);
        cout << tmp << endl;
    }
}
