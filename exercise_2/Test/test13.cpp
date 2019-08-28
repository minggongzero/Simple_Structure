//mypric013
#include "test.h"
#include "../mypric13.cpp"
#include <iostream>
using std::cout;
using std::endl;

void test13(){
    lnkList<int>* lnk = new lnkList<int>();
    Link<int>* link;
    lnk->append(0);
    lnk->append(1);
    lnk->append(2);
    lnk->append(3);
    lnk->append(4);
    lnk->append(5);
    lnk->append(6);
    lnk->append(7);
    //cout<<lnk->length()<<endl;
    Josephus(lnk, 8, 3, 4);
    link = lnk->gethead();
    while((link=link->next)!=0)
        cout << link->data << endl;
    delete lnk;
}
