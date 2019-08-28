#ifndef ARRLIST_H_INCLUDED
#define ARRLIST_H_INCLUDED

#include "../List.h"

template <class T>
class arrList : public List<T> {
private:
    T*  aList;
    int maxSize;
    int curLen;
    int position;

public:
    arrList(const int asize){
        maxSize = asize;
        aList = new T[maxSize];
        curLen = position = 0;
    }

    ~arrList() {
        delete[] aList;
    }

    void my_clear() {
        delete[] aList;
        curLen = position = 0;
        aList = new T[maxSize];
    }

    int length();
    bool isEmpty();
    bool append(const T value);
    bool my_insert(const int p, const T value);//
    bool my_delete(const int p);//
    bool setValue(const int p, const T value);
    bool getValue(const int p, T& value);
    bool getPos(int& p, const T value);//
};


#endif // ARRLIST_H_INCLUDED
