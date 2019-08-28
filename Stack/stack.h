#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <class T>
class Stack {
public:
    void myclear();  //变为空栈
    bool push(const T item); //压栈，item入栈
    bool pop(T & item);  //返回栈顶元素并弹出
    bool getTop(T & item);  //返回栈顶元素但不弹出
    bool isEmpty();
    bool isFull();
};

#endif // STACK_H_INCLUDED
