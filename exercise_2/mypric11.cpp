#include "../List/lnkList/lnkList.h"
#include "../List/lnkList/lnkList.cpp"
/**
*时间复杂度为O(n)、空间复杂度为O(1)的链表反转算法
*/
template <class T>
lnkList<T>* changeLink(lnkList<T>* lnk)
{
    Link<T>* head = lnk->gethead()->next;
    Link<T>* p = 0, *q = head;

    while(q != 0)  //反转链表
    {
        q = q->next;
        head->next = p;
        p = head;
        head = q;
    }
    head = lnk->gethead();
    head->next = p;

    lnk->sethead(head);
    lnk->settail(lnk->gethead()->next);

    return lnk;
}
