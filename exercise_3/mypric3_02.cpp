#include <iostream>
using namespace std;

template <class T>
class Deque{
private:
    int lefthead, righthead, thesize;
    T* st;
public:
    Deque(int thesize){
        this->thesize = thesize;
        lefthead = righthead = 0;
        st = new T[thesize+1];
    }

    ~Deque(){
        delete[] st;
        lefthead = righthead = 0;
    }

    bool left_inster(const T item){
        if(this->length() >= thesize){
            return false;
        }
        lefthead = (lefthead+thesize)%(thesize+1);
        st[lefthead] = item;
        return true;
    }

    bool right_inster(const T item){
        if(this->length() >= thesize){
            return false;
        }
        st[righthead] = item;
        righthead = (righthead+1)%(thesize+1);
        return true;
    }

    bool left_delete(T& item){
        if(this->isEmpty()){
            return false;
        }
        item = st[lefthead];
        lefthead = (lefthead+1)%(thesize+1);
        return true;
    }

    bool right_delete(T& item){
        if(this->isEmpty()){
            return false;
        }
        righthead = (righthead+thesize)%(thesize+1);
        item = st[righthead];
        return true;
    }

    bool isEmpty(){
        return lefthead==righthead ? true : false;
    }

    int length(){
        if(lefthead > righthead){
            return thesize-(lefthead-righthead)+1;
        }
        return righthead-lefthead;
    }
};
