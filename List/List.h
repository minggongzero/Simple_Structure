#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template <class T>
class List {
public:
    void my_clear();
    bool isEmpty();
    bool append(const T value);
    bool my_insert(const int p, const T value);
    bool my_delete(const int p);
    bool getValue(const int p, T& value);
    bool setValue(const int p, const T value);
    bool getPos(int& p, const T value);
};

#endif // LIST_H_INCLUDED
