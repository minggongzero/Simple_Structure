#ifndef LNKSTACK_H_INCLUDED
#define LNKSTACK_H_INCLUDED

#include "Stack\stack.h"
#include "List\lnkList\Link.h"

template <class T>
class lnkStack : public Stack<T> {
private:
    Link<T>* top;
    int mysize;
public:
    lnkStack()
    {
        top = 0;
        mysize = 0;
    }
    ~lnkStack()
    {
        my_clear();
    }

    void my_clear()
    {
        Link<T>* tmp = top;
        while(top != 0)
        {
            top = top->next;
            delete tmp;
            tmp = top;
        }
        mysize = 0;
    }

    bool push(const T item)
    {
        Link<T>* tmp = new Link<T>(item, top);
        top = tmp;
        ++mysize;
        return true;
    }

    bool pop(T& item)
    {
        if(mysize <= 0)
        {
            //std::cout << "栈为空，不能弹出" << std::endl;
            return false;
        }
        Link<T>* tmp = top->next;
        item = top->data;
        delete top;
        top = tmp;
        --mysize;
        return true;
    }

    bool getTop(T& item)
    {
        if(mysize <= 0)
        {
            //std::cout << "栈为空，不能返回值" << std::endl;
            return false;
        }
        item = top->data;
        return true;
    }
};


#endif // LNKSTACK_H_INCLUDED
