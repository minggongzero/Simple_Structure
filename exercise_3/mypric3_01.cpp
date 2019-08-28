#include "../Stack/arrStack/arrStack.h"

template <class T>
class StackToQueue{
private:
    arrStack<T> *s1, *s2;
    int pedit;  //当前元素个数
    int thesize;  //最大容纳元素个数
    bool point;  //变栈标记
public:
    StackToQueue(int thesize){
        this->thesize = thesize;
        pedit = 0;
        point = false;
        s1 = new arrStack<T>(thesize);
        s2 = new arrStack<T>(thesize);
    }

    ~StackToQueue(){
        delete s1;
        delete s2;
    }

    bool enqueue(const T item){
        if(!point){
            s1->push(item);
        }
        else{
            T tmp;
            while(s2->pop(tmp))
                s1->push(tmp);
            s1->push(item);
            point = false;
        }
        pedit++;
        return true;
    }

    bool dequeue(T& item){
        if(!point){
            T tmp;
            for(int i=pedit; i>1; i--){
                s1->pop(tmp);
                s2->push(tmp);
            }
            s1->pop(item);
            point = true;
        }
        else{
            s2->pop(item);
        }
        pedit--;
        return true;
    }

    bool queue_empty(){
        T tmp;
        if(!point){
            return s1->getTop(tmp) ? false : true;
        }
        return s2->getTop(tmp) ? false : true;
    }
};
