//#include<iostream>
#include "arrList.h"

//����
template <class T>
bool arrList<T> :: getPos(int& p, const T value) {
    int i;
    for(i=0; i<curLen-1; i++)
    if(value == aList[i]) {
        p = i;
        return true;
    }
    return false;
}

//����
template <class T>
bool arrList<T> :: my_insert(const int p, const T value) {
        int i;
        if(curLen >= maxSize) {
            //std::cout << "The list is overflow" << std::endl;
            return false;
        }

        for(i=curLen; i>p; i--)
            aList[i] = aList[i-1];
        aList[p] = value;
        curLen++ ;
        return true;
}

//ɾ��
template <class T>
bool arrList<T> :: my_delete(const int p) {
    int i;
    if(curLen <= 0) {
        //std::cout << "No element to delete \n" << std::endl;
        return false;
    }
    if(p<0 || p>curLen-1) {
        //std::cout << "deleteion is illegal\n" << std::endl;
        return false;
    }

    for(i=p; i<curLen-1; i++)
        aList[i] = aList[i+1];
    curLen-- ;
    return true;
}

//�ڱ�β���һ��Ԫ��
template <class T>
bool arrList<T> :: append(const T value) {
    if(curLen >= maxSize) {
        //std::cout << "ArrayList is Full!" << std::endl;
        return false;
    }

    aList[++position] = value;
    curLen++ ;
    return true;
}

//�޸�
template <class T>
bool arrList<T> :: setValue(const int p, const T value) {
    if(curLen <= 0) {
        //std::cout << "No element to set \n" << std::endl;
        return false;
    }
    if(p<0 || p>curLen-1) {
        //std::cout << "setValue illegal" << std::endl;
        return false;
    }

    aList[p] = value;
    return true;
}

//��λ��p��Ԫ�ط��ص�����value��
template <class T>
bool arrList<T> :: getValue(const int p, T& value) {
    if(curLen <= 0) {
        //std::cout << "No element to return \n" << std::endl;
        return false;
    }
    if(p<0 || p>curLen-1) {
        //std::cout << "getValue illegal" << std::endl;
        return false;
    }

    value = aList[p];
    return true;
}

//����ʵ�ʳ���
template <class T>
int arrList<T> :: length() {
    return curLen;
}

//�ж�˳����Ƿ�Ϊ��
template <class T>
bool arrList<T> :: isEmpty() {
    return curLen<=0 ? false : true;
}
