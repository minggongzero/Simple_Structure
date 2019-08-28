#include <iostream>
using namespace std;

template <class T>
class arrayStack{
private:
    T* st;
    int left, right, nsize;

public:
    arrayStack(int Size){
        nsize = Size;
        st = new T[nsize];
        left = -1;
        right = nsize;
    }

    ~arrayStack(){
        delete st;
    }

    bool left_push(const T item){
        if(this->isFull()){
            return false;
        }
        st[++left] = item;
        return true;
    }

    bool right_push(const T item){
        if(this->isFull()){
            return false;
        }
        st[--right] = item;
        return true;
    }

    bool left_pop(T& item){
        if(this->left_isEmpty()){
            return false;
        }
        item = st[left--];
        return true;
    }

    bool right_pop(T& item){
        if(this->right_isEmpty()){
            return false;
        }
        item = st[right++];
        return true;
    }

    bool left_isEmpty(){
        return left==-1 ? true : false;
    }

    bool right_isEmpty(){
        return right==nsize ? true : false;
    }

    bool isFull(){
        if(left == right-1)
            return true;
        return false;
    }
};
