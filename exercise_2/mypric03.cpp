/**
*����ֵ��������ĵ�����A��B
*��A��B�鲢��һ����Ԫ��ֵ�ݼ��������е����Ա�C
*��Ҫ������ԭ��Ľ��ռ乹���C
*/
//��·�鲢
//����ԭ��Ľ��ռ��Ʊػ��ƻ�ԭ��
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

    //�ٽ�����ת
    A = changeLink(A);

    return A;
}
