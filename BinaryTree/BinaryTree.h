#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

template <class T>
class BinaryTreeNode;

template <class T>
class BinaryTree{
private:
    BinaryTreeNode<T>* root;
public:
    BinaryTree(){root = 0;};
    ~BinaryTree(){DeleteBinaryTree(root);};
    bool isEmpty() const;
    BinaryTreeNode<T>* Root(){return root;};
    BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);
    BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T>* current);
    BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T>* current);
    void CreatTree(const T& info, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree);
    void CreatTree(BinaryTreeNode<T>*& root);

    void PreOrder(BinaryTreeNode<T>* root);
    void InOrder(BinaryTreeNode<T>* root);
    void PostOrder(BinaryTreeNode<T>* root);
    void LevelOrder(BinaryTreeNode<T>* root);
    void DeleteBinaryTree(BinaryTreeNode<T>* root);

    void Visit(T val);
};

#endif // BINARYTREE_H_INCLUDED
