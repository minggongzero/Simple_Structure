#ifndef ARRSTACK_H_INCLUDED
#define ARRSTACK_H_INCLUDED

#include "../stack.h"
//#include <iostream>

template <class T>
class arrStack : public Stack<T> {
private:
    int mSize;
    int top;
    T*  st;

public:
    arrStack(int Size) {
        mSize = Size;
        top   = -1;
        st    = new T[mSize];
    }

    arrStack() {
        top = -1;
    }

    ~arrStack() {
        delete[] st;
    }

    void myclear() {
        top = -1;
    }

    bool push(const T item) {
        if(top == mSize-1) {
            T* newst = new T[mSize*2];
            for(int i=0; i<=top; i++)
                newst[i] = st[i];
            delete[] st;
            mSize *= 2;
            st = newst;
        }
        st[++top] = item;
        return true;
    }

    bool pop(T & item) {
        if(top == -1) {
            //std::cout << "栈为空，不能执行出栈操作" << std::endl;
            return false;
        }
        else {
            item = st[top--];
            return true;
        }
    }

    bool getTop(T & item) {
        if(top == -1) {
            //std::cout << "栈为空，不能读取栈顶元素" << std::endl;
            return false;
        }
        else {
            item = st[top];
            return true;
        }
    }

    int length(){
        return top+1;
    }
};

#endif // ARRSTACK_H_INCLUDED
