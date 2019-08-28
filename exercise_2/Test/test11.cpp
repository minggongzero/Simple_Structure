//myprice11_Test
#include "test.h"
#include "../mypric11.cpp"
#include <iostream>
using std::cout;
using std::endl;

void test11(){
    lnkList<int>* lnk = new lnkList<int>();

    lnk->my_insert(0,2);
    lnk->my_insert(1,3);
    lnk->my_insert(2,4);
    lnk->my_insert(3,5);

    /*lnk->append(2);
    lnk->append(3);
    lnk->append(4);
    lnk->my_insert(2,10);*/
 //   cout<<lnk->length();
    cout<<lnk->gethead()->next->data<<'\n'<<lnk->gethead()->next->next->data<<'\n'<<lnk->gethead()->next->next->next->data<<'\n'<<lnk->gethead()->next->next->next->next->data<<endl;
    lnk = changeLink(lnk);
    cout<<lnk->gethead()->next->data<<'\n'<<lnk->gethead()->next->next->data<<'\n'<<lnk->gethead()->next->next->next->data<<'\n'<<lnk->gethead()->next->next->next->next->data<<endl;
    delete lnk;
}
