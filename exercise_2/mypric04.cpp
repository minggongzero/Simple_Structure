/**
*��֪��һ�������ʾ�����Ա��к��������ַ�������Ԫ�أ���ĸ�ַ��������ַ��������ַ���
*���һ���㷨������������ָ�Ϊ3��ѭ������
*����ÿ��ѭ�������ֻ��һ���ַ�
*/


#include "../List/lnkList/lnkList.h"
#include "../List/lnkList/lnkList.cpp"
template <class T>
bool fen_ge(lnkList<T>* &lnk, lnkList<T>* &a, lnkList<T>* &b, lnkList<T>* &c)
{
    Link<T>* buff00=lnk->gethead()->next;
    Link<T>* buff01=a->gethead()->next;
    Link<T>* buff02=b->gethead()->next;
    Link<T>* buff03=c->gethead()->next;
    while(buff00 != 0)
    {
        if(((buff00->data>=65 && buff00->data<=90) || (buff00->data>=97 && buff00->data<=122)))
        {
            buff01->data = buff00->data;
            if(buff01->next != 0)
            {
                buff01 = buff01->next;
                //return false;
            }
        }
        else if(buff00->data>=48 && buff00->data<=57)
        {
            buff02->data = buff00->data;
            if(buff02->next != 0)
            {
                buff02 = buff02->next;
                //return false;
            }
        }
        else
        {
            buff03->data = buff00->data;
            if(buff03->next != 0)
            {
                buff03 = buff03->next;
                //return false;
            }
        }
        buff00 = buff00->next;
    }
    a->settail(buff01);
    b->settail(buff02);
    c->settail(buff03);
    buff01->next = a->gethead();
    buff02->next = b->gethead();
    buff03->next = c->gethead();
    return true;
}
