/**
*以值递增排列的单链表
*删除除最大元素与最小元素以外的所有元素，同时释放被删除结点的空间，并分析时间复杂度
*/
#include "../List/lnkList/lnkList.h"
#include "../List/lnkList/lnkList.cpp"

template <class T>
lnkList<T>* deleteLink(lnkList<T>* lnk)
{
    int my_count = lnk->length()-3;
    while(my_count-- > 0)
        lnk->my_delete(1);
    return lnk;
}
//时间复杂度O(n)
