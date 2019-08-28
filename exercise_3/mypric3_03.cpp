#include <iostream>
#include "../Queue/Queue.h"
using namespace std;

//(1)
template <class T>
void QueueSort01(Queue<T>* que){
    Queue<T>* p, *q;
    T tmp, item;
    int len = que->length();
    bool flag = false;
    p = new Queue<T>(len);
    q = new Queue<T>(len);
    que->deQueue(tmp);

    while(p->length() < len){
        if(!flag){
            while(que->deQueue(item)){
                if(tmp > item){
                    tmp = tmp^item;
                    item = item^tmp;
                    tmp = tmp^item;
                }
                q->enQueue(item);
            }
            flag = true;
            p->enQueue(tmp);
            q->deQueue(tmp);
        }
        else {
            while(q->deQueue(item)){
                if(tmp > item){
                    tmp = tmp^item;
                    item = item^tmp;
                    tmp = tmp^item;
                }
                que->enQueue(item);
            }
            flag = false;
            p->enQueue(tmp);
            que->deQueue(tmp);
        }
    }
    while(p->deQueue(tmp))
        que->enQueue(tmp);

    delete q;
    delete p;
}

//(2)
template <class T>
void QueueSort02(Queue<T>* que){
    int len = que->length();
    Queue<T>* p = new Queue<T>(que->length());
    T tmp, item;
    while(p->length() < len){
        int i = len - p->length();
        que->deQueue(tmp);
        while(--i > 0){
            que->deQueue(item);
            if(tmp > item){
                tmp = tmp^item;
                item = item^tmp;
                tmp = tmp^item;
            }
            que->enQueue(item);
        }
        p->enQueue(tmp);
    }
    while(p->deQueue(tmp))
        que->enQueue(tmp);

    delete p;
}

