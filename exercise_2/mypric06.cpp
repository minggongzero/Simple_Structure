/**
*已知单链表中元素以值递增有序排列
*设计算法删除表中值相同的多余元素
*使得操作后表中的所有元素值均不同
*同时释放被删除的结点空间
*/
#include "../List/lnkList/lnkList.h"
#include "../List/lnkList/lnkList.cpp"

template <class T>
lnkList<T>* delete_thesame(lnkList<T>* lnk)
{
    int my_count = 1;
    Link<T>* link;
    link = lnk->gethead()->next;
    while(link->next != 0)
    {
        if(link->data == link->next->data)
            lnk->my_delete(my_count);
        else
        {
            ++my_count;
            link = link->next;
        }
    }
    return lnk;
}
