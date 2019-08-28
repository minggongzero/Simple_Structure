/**
*已知两个元素按值递增有序排列的线性表A和B
*且同一表中的元素值各不相同
*构造一个线性表C，其元素为A和B中元素的交集
*且表C中的元素也按值递增有序排列。
*设计A、B、C都是顺序表时的算法。
*
*/
//方法依然选择二路归并
#include "../List/arrList/arrList.h"
#include "../List/arrList/arrList.cpp"

template <class T>
void qujiaoji(arrList<T>* A, arrList<T>* B, arrList<T>* C)
{
    T a, b;
    int count_a=0, count_b=0;
    while(count_a<A->length() && count_b<B->length())
    {
        A->getValue(count_a, a);
        B->getValue(count_b, b);
        if(a<b)
            ++count_a;
        else if(a>b)
            ++count_b;
        else
        {
            C->my_insert(C->length(), a);
            ++count_a;
            ++count_b;
        }
    }
}
