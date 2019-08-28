#include "BinaryTree.h"
#include <queue>
#include <stack>
#include <iostream>

template <class T>
bool BinaryTree<T>::isEmpty() const{
    return (root!=0 ? false : true);
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* current){
    using std::stack;
    stack<BinaryTreeNode<T>*> aStack;
    BinaryTreeNode<T>* pointer = root;
    if(root!=0 && current!=0){
        while(!aStack.empty() || pointer){
            if(pointer){
                if(current == pointer->leftchild() || current == pointer->rightchild())
                    return pointer;
                aStack.push(pointer);
                pointer = pointer->leftchild();
            }
            else{
                pointer = aStack.top();
                aStack.pop();
                pointer = pointer->rightchild();
            }
        }
    }
    return 0;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T>* current){
    return Parent(current)->leftchild();
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>* current){
    return Parent(current)->rightchild();
}

template <class T>
void BinaryTree<T>::CreatTree(const T& info, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree){
    root = new BinaryTreeNode<T>(info, leftTree.root, rightTree.root);
    leftTree.root = rightTree.root = 0;
}

template <class T>
void BinaryTree<T>::CreatTree(BinaryTreeNode<T>*& root){
    T info;
    std::cin >> info;
    if(info == -1){root = 0;}
    else{
        root = new BinaryTreeNode<T>(info);
        CreatTree(root->left);
        CreatTree(root->right);
    }
}

template <class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T>* root){
    if(root != 0){
        Visit(root->value());
        PreOrder(root->leftchild());
        PreOrder(root->rightchild());
    }
}

template <class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>* root){
    if(root != 0){
        InOrder(root->leftchild());
        Visit(root->value());
        InOrder(root->rightchild());
    }
}

template <class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T>* root){
    if(root != 0){
        PostOrder(root->leftchild());
        PostOrder(root->rightchild());
        Visit(root->value());
    }
}

template <class T>
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T>* root){
    using std::queue;
    queue<BinaryTreeNode<T>*> aQueue;
    BinaryTreeNode<T>* pointer = root;
    if(pointer)
        aQueue.push(pointer);
    while(!aQueue.empty()){
        pointer = aQueue.front();
        aQueue.pop();
        Visit(pointer->value());
        if(pointer->leftchild()!=0)
            aQueue.push(pointer->leftchild());
        if(pointer->rightchild()!=0)
            aQueue.push(pointer->rightchild());
    }
}

template <class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T>* root){  //ºóÐòÖÜÓÎÉ¾³ý
    if(root != 0){
        DeleteBinaryTree(root->left);
        DeleteBinaryTree(root->right);
        delete root;
    }
}

template <class T>
void BinaryTree<T>::Visit(T val){std::cout << val;}
