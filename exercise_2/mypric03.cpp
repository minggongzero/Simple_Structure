/**
*两个值递增有序的单链表A和B
*将A和B归并成一个按元素值递减有序排列的线性表C
*并要求利用原表的结点空间构造表C
*/
//二路归并
//利用原表的结点空间势必会破坏原表
#include "../List/lnkList/lnkList.h"
#include "mypric11.cpp"

template <class T>
lnkList<T>* hebing(lnkList<T>* A, lnkList<T>* B)
{
    //lnkList<T>* C = new lnkList<T>();
    Link<T>* p=A->gethead();
    Link<T>* q;
    Link<T>* buff;
    p->next = A->gethead()->next->data<=B->gethead()->next->data ? A->gethead()->next : B->gethead()->next;
    q = A->gethead()->next->data>B->gethead()->next->data ? A->gethead()->next : B->gethead()->next;
    p = p->next;
    while(p->next!=0 && q!=0)
    {
        if(p->next->data <= q->data)
        {
            p = p->next;
        }
        else
        {
            buff = p->next;
            p->next = q;
            q = buff;
        }
    }
    p->next = q;

    //再将链表反转
    A = changeLink(A);

    return A;
}
