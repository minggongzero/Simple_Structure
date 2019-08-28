//mypric02
#include "test.h"
#include "../mypric02.cpp"
#include <iostream>
using std::cout;
using std::endl;

void test02(){
    lnkList<int>* lnk = new lnkList<int>();
    Link<int>* link;
    lnk->append(2);
    lnk->append(3);
    lnk->append(6);
    lnk->append(7);
    lnk->append(8);
    lnk->append(9);
    lnk->append(10);
    lnk->append(11);
    lnk = deleteLink(lnk);
    link = lnk->gethead();
    while((link=link->next)!=NULL)
        cout << link->data << endl;
    delete lnk;
}
