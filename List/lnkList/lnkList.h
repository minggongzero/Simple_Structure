#ifndef LNKLIST_H_INCLUDED
#define LNKLIST_H_INCLUDED

#include "../List.h"
#include "Link.h"

template <class T>
class lnkList : public List<T> {
private:
    Link<T> *head, *tail;
    Link<T> *setPos(const int p);  //Ѱ�ҵ�p�����

public:
    lnkList();
    //lnkList(Link<T>* link);
    ~lnkList();
    bool isEmpty();
    void my_clear();
    int  length();
    bool append(const T value);  //��β������һ�����
    bool my_insert(const int p, const T value);
    bool my_delete(const int p);
    bool getValue(const int p, T& value);  //����p�����ֵ���ص�value
    bool getPos(int& p, const T value);  //��ֵΪvalue�Ľ���ַ���ص�p

    Link<T>* gethead();
    Link<T>* gettail();
    void sethead(Link<T>* head);
    void settail(Link<T>* tail);
};


#endif // LNKLIST_H_INCLUDED
