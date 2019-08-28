#include <iostream>
using namespace std;
/**
*循环数组表示队列，只有头指针front，不设尾指针rear，实现基本操作
*/

template <class T>
class SpQueue{
private:
    T* q;
    int fron;
    int thecount;
    int Size;

public:
    SpQueue(int thesize){
        Size = thesize;
        q = new T[Size+1];
        fron = thecount = 0;
    }

    ~SpQueue(){
        delete[] q;
        thecount = 0;
    }

    bool isEmpty(){
        return thecount==0 ? true : false;
    }

    bool enqueue(const T item){
        if(thecount >= Size){
            return false;
        }
        q[(thecount+fron)%(Size+1)] = item;
        thecount++;
        return true;
    }

    bool dequeue(T& item){
        if(this->isEmpty()){
            return false;
        }
        item = q[fron];
        fron = (fron+1)%(Size+1);
        thecount--;
        return true;
    }
};
