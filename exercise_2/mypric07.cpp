/**
*��֪����Ԫ�ذ�ֵ�����������е����Ա�A��B
*��ͬһ���е�Ԫ��ֵ������ͬ
*����һ�����Ա�C����Ԫ��ΪA��B��Ԫ�صĽ���
*�ұ�C�е�Ԫ��Ҳ��ֵ�����������С�
*���A��B��C����˳���ʱ���㷨��
*
*/
//������Ȼѡ���·�鲢
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
