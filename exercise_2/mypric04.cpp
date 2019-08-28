/**
*已知由一个链表表示的线性表中含有三类字符的数据元素（字母字符、数字字符和其他字符）
*设计一个算法将该线性链表分割为3个循环链表
*其中每个循环链表均只含一类字符
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
