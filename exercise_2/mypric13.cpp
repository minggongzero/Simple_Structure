/**
*����n����Χ����һ��Բ����Χ
*�ִӵ�s���˿�ʼ������������m���˳��У�Ȼ��ӳ��е���һ�������¿�ʼ������������m�����ֳ��У���˷���ֱ�����е���ȫ������Ϊֹ��
*Josephus�����ǣ��������������n��s��m����������д���õ���n����Ա�����С�
*�ڼ������ģ��Josephus����������̡�
*/
#include "../List/lnkList/lnkList.h"
#include "../List/lnkList/lnkList.cpp"

template <class T>
bool Josephus(lnkList<T>* &lnk, int n, int s, int m)
{
    int t = lnk->length();
    if(n != t-1)
        return false;
    int p, i;
    lnkList<T>* endlnk = new lnkList<T>();
    Link<T>* thenext;
    Link<T>* buff = lnk->gettail();
    Link<T>* link = lnk->gettail();
    link->next = lnk->gethead()->next;
    link = lnk->gethead();
    for(i=0; i<s; ++i)
        link = link->next;
    while(t-- > 1)
    {
        for(i=0; i<m-1; ++i)
            link = link->next;
        thenext = link->next;
        buff->next = 0;
        lnk->getPos(p, link->data);
        endlnk->append(link->data);
        lnk->my_delete(p-1);
        Link<T>* buff = lnk->gettail();
        buff->next = lnk->gethead()->next;
        link = thenext;
    }
    link = endlnk->gethead()->next;
    while(link != 0){
       lnk->append(link->data);
       link = link->next;
    }
    delete endlnk;
    return true;
}
