//mypric03
#include "test.h"
#include "../mypric03.cpp"
#include <iostream>
using std::cout;
using std::endl;

void test03(){
    lnkList<int>* A = new lnkList<int>();
    lnkList<int>* B = new lnkList<int>();
    lnkList<int>* C = new lnkList<int>();
    A->append(0);
    A->append(2);
    A->append(4);
    A->append(6);
    B->append(1);
    B->append(3);
    B->append(5);
    B->append(7);

    cout << A->gethead()->next->data << '\n' << A->gethead()->next->next->data << '\n' << A->gethead()->next->next->next->data << '\n' << A->gethead()->next->next->next->next->data << endl;
    cout << B->gethead()->next->data << '\n' << B->gethead()->next->next->data << '\n' << B->gethead()->next->next->next->data << '\n' << B->gethead()->next->next->next->next->data << endl;
    C = hebing(A, B);
    cout << C->gethead()->next->data << '\n' << C->gethead()->next->next->data << '\n' << C->gethead()->next->next->next->data << '\n' << C->gethead()->next->next->next->next->data << '\n' << C->gethead()->next->next->next->next->next->data << '\n' << C->gethead()->next->next->next->next->next->next->data << '\n' << C->gethead()->next->next->next->next->next->next->next->data << '\n' << C->gethead()->next->next->next->next->next->next->next->next->data << endl;
    delete A;
    delete B;
    delete C;
}
