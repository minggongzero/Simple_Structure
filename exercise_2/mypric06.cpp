/**
*��֪��������Ԫ����ֵ������������
*����㷨ɾ������ֵ��ͬ�Ķ���Ԫ��
*ʹ�ò�������е�����Ԫ��ֵ����ͬ
*ͬʱ�ͷű�ɾ���Ľ��ռ�
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
