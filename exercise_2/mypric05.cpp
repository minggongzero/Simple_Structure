/**
*����㷨
*ɾ��һ��˳����дӵ�i��Ԫ�ؿ�ʼ��k��Ԫ��
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
