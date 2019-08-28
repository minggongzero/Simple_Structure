#include "BinaryTreeNode.h"

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(){}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r){
    info = ele;
    left = l;
    right = r;
}

template <class T>
T BinaryTreeNode<T>::value() const{
    return info;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::leftchild() const{
    return left;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::rightchild() const{
    return right;
}

template <class T>
void BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T>* antherleft){
    left = antherleft;
}

template <class T>
void BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T>* antherright){
    right = antherright;
}

template <class T>
void BinaryTreeNode<T>::setValue(const T& val){
    info = val;
}

template <class T>
bool BinaryTreeNode<T>::isLeft() const{
    return left||right ? false : true;
}

template <class T>
BinaryTreeNode<T>& BinaryTreeNode<T>::operator=(const BinaryTreeNode<T>& Node){
    return Node;
}
