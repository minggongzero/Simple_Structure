/**
*假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（不设头指针）
*编写相应队列初始化、入队、出队算法
*/
#include <iostream>
using namespace std;

/**
*带头结点循环链表定义
*/
#include "../List/lnkList/Link.h"
template <class T>
class lnk{
private:
    Link<T>* tail;
    Link<T>* setPos(const int);

public:
    lnk();
    ~lnk();
    bool lnk_insert(int, const T);
    bool lnk_delete(const int);
    bool lnk_append(const T);
    Link<T>* getTail();
    int length();
};

template <class T>
Link<T>* lnk<T>::setPos(const int p){
    int thecount = 0;
    Link<T>* t = tail->next;
    Link<T>* head = tail->next;
    tail->next = 0;
    while(t!=0 && thecount<p){
        t = t->next;
        thecount++;
    }
    tail->next = head;
    return t;
}

template <class T>
lnk<T>::lnk(){
    tail = new Link<T>();
    tail->next = tail;
}

template <class T>
lnk<T>::~lnk(){
    Link<T>* tmp = tail->next;
    tail->next = 0;
    while(tmp != 0){
        tail = tmp->next;
        delete tmp;
        tmp = tail;
    }
}

template <class T>
bool lnk<T>::lnk_insert(int p, const T item){
    Link<T>* a, *b;
    if((a=setPos(p-1)) == 0){
        return false;
    }
    b = new Link<T>(item, a->next);
    a->next = b;
    if(a == tail)
        tail = b;
    return true;
}

template <class T>
bool lnk<T>::lnk_delete(const int p){
    Link<T>* tmp1, *tmp2;
    if(p<0 || ((tmp1=setPos(p-1))==0))
        return false;
    tmp2 = tmp1->next;
    tmp1->next = tmp2->next;
    if(tmp2 == tail)
        tail = tmp1;
    delete tmp2;
    return true;
}

template <class T>
bool lnk<T>::lnk_append(const T value)
{
    Link<T>* a = new Link<T>(value, tail->next);
    tail->next = a;
    tail = a;
    return true;
}

template <class T>
Link<T>* lnk<T>::getTail(){
    return tail;
}

template <class T>
int lnk<T>::length(){
    Link<T>* tmp = tail->next;
    Link<T>* p = tail->next;
    int thecount = 0;
    tail->next = 0;
    while(tmp != 0){
        tmp = tmp->next;
        thecount++;
    }
    tail->next = p;
    return thecount-1;
}

/**
*实现队列
*/
template <class T>
class TBqueue{
private:
    lnk<T>* q;

public:
    TBqueue(){
        q = new lnk<T>();
    }

    ~TBqueue(){
        delete q;
    }

    bool isEmpty(){
        return q->length() <= 0 ? true : false;
    }

    bool enqueue(const T item){
        q->lnk_append(item);
        return true;
    }

    bool dequeue(T& item){
        if(this->isEmpty()){
            return false;
        }
        item = q->getTail()->next->next->data;
        q->lnk_delete(1);
        return true;
    }
};

