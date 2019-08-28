#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

template <class T>
class Link {
public:
    T data;
    Link<T>* next;

    Link(const T info, /*const*/ Link<T>* nextValue=0) {
        data = info;
        next = nextValue;
    }

    Link(/*const*/ Link<T>* nextValue=0) {
        next = nextValue;
    }
};


#endif // LINK_H_INCLUDED
