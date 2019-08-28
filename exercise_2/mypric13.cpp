/**
*设有n个人围坐在一个圆桌周围
*现从第s个人开始报数，数到第m的人出列，然后从出列的下一个人重新开始报数，数到第m的人又出列，如此反复直到所有的人全部出列为止。
*Josephus问题是：对于任意给定的n、s、m，求出按出列次序得到的n个人员的序列。
*在计算机上模拟Josephus问题的求解过程。
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
