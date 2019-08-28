#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

template <class T>
class BinaryTree;

template <class T>
class BinaryTreeNode;

template <class T>
class BinarySearchTree : public BinaryTree<T>{
private:
    BinaryTreeNode<T>* root;

public:
    BinarySearchTree(){root = 0;};
    void createBinarySearchTree();
    void InsertNode(BinaryTreeNode<T>* root, BinaryTreeNode<T>* newpointer);
    void DeleteNodeEx(BinaryTreeNode<T>* pointer);
};

#endif // BINARYSEARCHTREE_H_INCLUDED
