//mypric06
#include "test.h"
#include "../mypric06.cpp"
#include <iostream>
using std::cout;
using std::endl;

void test06(){
    lnkList<int>* lnk = new lnkList<int>();
    Link<int>* link;
    lnk->append(2);
    lnk->append(3);
    lnk->append(3);
    lnk->append(3);
    lnk->append(6);
    lnk->append(6);
    lnk = delete_thesame(lnk);
    link = lnk->gethead();
    while((link=link->next)!=NULL)
        cout << link->data << endl;
    delete lnk;
}
