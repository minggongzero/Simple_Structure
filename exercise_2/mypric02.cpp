/**
*��ֵ�������еĵ�����
*ɾ�������Ԫ������СԪ�����������Ԫ�أ�ͬʱ�ͷű�ɾ�����Ŀռ䣬������ʱ�临�Ӷ�
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
//ʱ�临�Ӷ�O(n)
