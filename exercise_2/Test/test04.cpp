//mypric04
#include "test.h"
#include "../mypric04.cpp"
#include <iostream>
using std::cout;
using std::endl;

void test04(){
    lnkList<char>* A = new lnkList<char>();
    lnkList<char>* B = new lnkList<char>();
    lnkList<char>* C = new lnkList<char>();
    lnkList<char>* D = new lnkList<char>();
    A->append('I');
    A->append('L');
    A->append('O');
    A->append('V');
    A->append('E');
    A->append('y');
    A->append('o');
    A->append('u');
    A->append('!');
    A->append('!');
    A->append('1');
    A->append('3');
    A->append('1');
    A->append('4');
    A->append('!');
    A->append('!');

    B->append(' ');
    B->append(' ');
    B->append(' ');
    B->append(' ');
    B->append(' ');
    B->append(' ');
    B->append(' ');
    B->append(' ');

    C->append(' ');
    C->append(' ');
    C->append(' ');
    C->append(' ');

    D->append(' ');
    D->append(' ');
    D->append(' ');
    D->append(' ');

    fen_ge<char>(A, B, C, D);
//    cout << A->length() << endl;
//    cout << B->length() << endl;
//    cout << C->length() << endl;
//    cout << D->length() << endl;

    cout << B->gethead()->next->data << B->gethead()->next->next->data << B->gethead()->next->next->next->data << B->gethead()->next->next->next->next->data << B->gethead()->next->next->next->next->next->data << B->gethead()->next->next->next->next->next->next->data << B->gethead()->next->next->next->next->next->next->next->data << B->gethead()->next->next->next->next->next->next->next->next->data << endl;
    cout << C->gethead()->next->data << C->gethead()->next->next->data << C->gethead()->next->next->next->data << C->gethead()->next->next->next->next->data << endl; //C->gethead()->next->next->next->next->next->next->data << endl;
    cout << D->gethead()->next->data << D->gethead()->next->next->data << D->gethead()->next->next->next->data << D->gethead()->next->next->next->next->data << endl;

}
