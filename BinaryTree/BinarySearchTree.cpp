#include "BinarySearchTree.h"

template <class T>
void BinarySearchTree<T>::InsertNode(BinaryTreeNode<T>* root, BinaryTreeNode<T>* newpointer){
    BinaryTreeNode<T>* pointer = 0;
    if(root == 0){
        initialize(newpointer);
        return;
    }
    else pointer = root;
    while(pointer != 0){
        if(newpointer->value() == pointer->value())
            return;
        else if(newpointer->value() < pointer->value()){
            if(pointer->leftchild() == 0){
                pointer->left = newpointer;
                return;
            }
            else pointer = pointer->leftchild();
        }
        else{
            if(pointer->rightchild() == 0){
                pointer->right = newpointer;
                return;
            }
            else pointer = pointer->rightchild();
        }
    }
}

template <class T>
void BinarySearchTree<T>::DeleteNodeEx(BinaryTreeNode<T>* pointer){
    if(pointer == 0)
        return;
    BinaryTreeNode<T>* temppointer;
    BinaryTreeNode<T>* tempparent = 0;
    BinaryTreeNode<T>* parent = Parent(pointer);
    if(pointer->leftchild() == 0)
        temppointer = pointer->rightchild();
    else{
        temppointer = pointer->leftchild();
        while(temppointer->rightchild() != 0){
            tempparent = temppointer;
            temppointer = temppointer->rightchild();
        }
        if(tempparent == 0)
            pointer->left = temppointer->leftchild();
        else tempparent->right = temppointer->leftchild();
        temppointer->left = pointer->leftchild();
        temppointer->right = pointer->rightchild();
    }
    if(parent == 0)
        root = temppointer;
    else if(parent->leftchild() == pointer)
        parent->left = temppointer;
    else parent->right = temppointer;
    delete pointer;
    pointer = 0;
    return;
}
