#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <class T>
class Stack {
public:
    void myclear();  //��Ϊ��ջ
    bool push(const T item); //ѹջ��item��ջ
    bool pop(T & item);  //����ջ��Ԫ�ز�����
    bool getTop(T & item);  //����ջ��Ԫ�ص�������
    bool isEmpty();
    bool isFull();
};

#endif // STACK_H_INCLUDED
