/**
*要求同mypric07
*设计当A、B、C都是单链表时的算法
*/
#include "../List/lnkList/lnkList.h"
#include "../List/lnkList/lnkList.cpp"

template <class T>
void qujiaoji_lnk(lnkList<T>* A, lnkList<T>* B, lnkList<T>* C)
{
    Link<T>* a;
    Link<T>* b;
    a = A->gethead()->next;
    b = B->gethead()->next;
    while(a!=0 && b!=0)
    {
        if(a->data < b->data)
            a = a->next;
        else if(a->data > b->data)
            b = b->next;
        else
        {
            C->my_insert(C->length()-1, a->data);
            a = a->next;
            b = b->next;
        }
    }
}
