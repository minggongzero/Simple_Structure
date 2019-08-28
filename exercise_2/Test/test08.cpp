//mypric08
#include "test.h"
#include "../mypric08.cpp"
#include <iostream>
using std::cout;
using std::endl;

void test08(){
    lnkList<int>* lnk = new lnkList<int>();
    lnkList<int>* lnk01 = new lnkList<int>();
    lnkList<int>* lnk02 = new lnkList<int>();
    Link<int>* link;
    lnk->append(2);
    lnk->append(3);
    lnk->append(6);
    lnk->append(7);
    lnk01->append(2);
    lnk01->append(2);
    lnk01->append(2);
    lnk01->append(3);
    lnk01->append(7);
    qujiaoji_lnk(lnk, lnk01, lnk02);
    link = lnk02->gethead();
    while((link=link->next)!=0)
        cout << link->data << endl;
    delete lnk;
    delete lnk01;
    delete lnk02;

}
