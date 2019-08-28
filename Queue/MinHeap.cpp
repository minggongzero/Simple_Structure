#include "MinHeap.h"

template <class T>
void MinHeap<T>::MH_swap(int pos_x, int pos_y){}

template <class T>
void MinHeap<T>::BuildHeap(){}

template <class T>
MinHeap<T>::MinHeap(const int n){}

template <class T>
bool MinHeap<T>::isEmpty(){}

template <class T>
bool MinHeap<T>::isLeaf(int pos) const{}

template <class T>
int MinHeap<T>::LeftChild(int pos) const{}

template <class T>
int MinHeap<T>::RightChild(int pos) const{}

template <class T>
int MinHeap<T>::Parent(int pos) const{}

template <class T>
bool MinHeap<T>::Remove(int pos, T& node){}

template <class T>
bool MinHeap<T>::Insert(const T& newNode){}

template <class T>
T& MinHeap<T>::RemoveMin(){}

template <class T>
void MinHeap<T>::SiftUp(int position){}

template <class T>
void MinHeap<T>::SiftDown(int left){}
