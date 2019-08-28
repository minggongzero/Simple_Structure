#include <iostream>
#include "../Stack/arrStack/arrStack.h"
using namespace std;

//(1)
template <class T>
void stack_transfer01(arrStack<T>* s1, arrStack<T>* s2){
    arrStack<T>* tmp = new arrStack<T>(s1->length());
    T t;
    while(s1->pop(t))
        tmp->push(t);
    while(tmp->pop(t))
        s2->push(t);
    delete tmp;
}

//(2)
template <class T>
void stack_transfer02(arrStack<T>* s1, arrStack<T>* s2){
    T tmp, item;
    int i = s1->length();
    int k = i;
    int j = 0;
    while(i-- > 0){
        //int j = s1->length() - i - 1;
        while(j-- > 0){
            s1->pop(tmp);
            s2->push(tmp);
        }
        s1->pop(tmp);
        while(++j < k-i-1){
            s2->pop(item);
            s1->push(item);
        }
        s1->push(tmp);
        j++;
    }
    while(s1->pop(tmp))
        s2->push(tmp);
}
