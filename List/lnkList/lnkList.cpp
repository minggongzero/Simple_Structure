#include "lnkList.h"
//#include <iostream>

template <class T>
lnkList<T> :: lnkList() {
    head = tail = new Link<T>;
}

/*template <class T>
lnkList<T> :: lnkList(Link<T>* link) {
    head = tail = link;
}*/

template <class T>
lnkList<T> :: ~lnkList() {
    Link<T>* tmp;
    while(head != 0) {
        tmp  = head;
        head = head->next;
        delete tmp;
    }
}

//Ѱ�ҵ�p���ڵ�
template <class T>
Link<T>* lnkList<T> :: setPos(const int p) {
    int my_count = 0;
    if(p == -1)
        return head;
    //Link<T>* t = new Link<T>(head->next);
    Link<T>* t = head->next;
    while(t!=0 && my_count<p) {
        t = t->next;
        my_count++ ;
    }
    return t;
}

//����
template <class T>
bool lnkList<T> :: my_insert(const int p, const T value) {
    Link<T> *a, *b;

    if((a=setPos(p-1)) == 0) {
        //std::cout << "�Ƿ������" << std::endl;
        return false;
    }
    b = new Link<T>(value, a->next);
    a->next = b;
    if(a == tail)
        tail = b;
    return true;
}

//ɾ��
template <class T>
bool lnkList<T> :: my_delete(const int p) {
    Link<T> *a, *b;
    if((a=setPos(p-1))==0 || a==tail) {
        //std::cout << "�Ƿ�ɾ����" << std::endl;
        return false;
    }

    b = a->next;
    if(b == tail) {
        tail = a;
        a->next = 0;
        delete b;
    }
    else if(b != 0) {
        a->next = b->next;
        delete b;
    }
    return true;
}

//�����Ƿ�Ϊ��
template <class T>
bool lnkList<T> :: isEmpty()
{
    if(head->next == 0)
        return true;
    else
        return false;
}

//������
template <class T>
int lnkList<T> :: length()
{
    Link<T>* p = head;
    int i=0;
    while(p != 0)
    {
        ++i;
        p = p->next;
    }
    return i;
}

//��β������һ�����
template <class T>
bool lnkList<T> :: append(const T value)
{
    Link<T>* a = new Link<T>(value);
    if(this->length()==1)
    {
        head->next = tail = a;
    }
    else
    {
        tail->next = a;
        tail = a;
    }
    return true;
}

//����p�����ֵ���ص�value
template <class T>
bool lnkList<T> :: getValue(const int p, T& value)
{
    Link<T>* a = setPos(p-1);
    if(this -> isEmpty())
    {
        //std::cout << "����Ϊ�գ����ܷ���value" << std::endl;
    }
    else if((a == 0))
    {
        //std::cout << "��p���ڵ㲻����" << std::endl;
    }
    else
    {
        value = a->data;
        return true;
    }

    return false;
}

//��ֵΪvalue�Ľ���ַ���ص�p
template <class T>
bool lnkList<T> :: getPos(int& p, const T value)
{
    Link<T>* a=head;
    int i=0;
    if(this->isEmpty())
        return false;
        //std::cout << "����Ϊ�գ��޷����ص�ַp" << std::endl;
    while(a->next != 0)
    {
        a = a->next;
        ++i;
        if(a->data == value)
        {
            p = i;
            return true;
        }
    }
}

//get and set
template <class T>
Link<T>* lnkList<T> :: gethead()
{
    return head;
}

template <class T>
Link<T>* lnkList<T> :: gettail()
{
    return tail;
}

template <class T>
void lnkList<T> :: sethead(Link<T>* head)
{
    this->head = head;
}

template <class T>
void lnkList<T> :: settail(Link<T>* tail)
{
    this->tail = tail;
}
