#ifndef LNKLIST_H_INCLUDED
#define LNKLIST_H_INCLUDED

#include "../List.h"
#include "Link.h"

template <class T>
class lnkList : public List<T> {
private:
    Link<T> *head, *tail;
    Link<T> *setPos(const int p);  //寻找第p个结点

public:
    lnkList();
    //lnkList(Link<T>* link);
    ~lnkList();
    bool isEmpty();
    void my_clear();
    int  length();
    bool append(const T value);  //在尾部增加一个结点
    bool my_insert(const int p, const T value);
    bool my_delete(const int p);
    bool getValue(const int p, T& value);  //将第p个结点值返回到value
    bool getPos(int& p, const T value);  //将值为value的结点地址返回到p

    Link<T>* gethead();
    Link<T>* gettail();
    void sethead(Link<T>* head);
    void settail(Link<T>* tail);
};


#endif // LNKLIST_H_INCLUDED
