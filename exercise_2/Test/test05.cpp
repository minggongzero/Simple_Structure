//mypric05
#include "test.h"
#include "../mypric05.cpp"
#include <iostream>
using std::cout;
using std::endl;

void test05(){
    lnkList<int>* lnk = new lnkList<int>();
    Link<int>* link;
    lnk->append(2);
    lnk->append(3);
    lnk->append(4);
    lnk->append(5);
    lnk->append(6);
    lnk->append(7);
 //   lnk->my_delete(4);
    lnk = List_delete<int>(lnk,0,4);
    link = lnk->gethead();
    while((link=link->next)!=NULL)
        cout << link->data << endl;
    delete lnk;
}
