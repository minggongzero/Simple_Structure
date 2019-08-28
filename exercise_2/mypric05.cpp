/**
*设计算法
*删除一个顺序表中从第i个元素开始的k个元素
*/
#include "../List/lnkList/lnkList.h"
#include "../List/lnkList/lnkList.cpp"
template <class T>
lnkList<T>* List_delete(lnkList<T>* mylist, int i, int k)
{
    T value;
    if(mylist->getValue(i, value) && mylist->getValue(i+k-1, value))
    {
        while(k--)
            mylist->my_delete(i);
    }
    return mylist;
}
