#ifndef BINARYTREENODE_H_INCLUDED
#define BINARYTREENODE_H_INCLUDED

template <class T>
class BinaryTree;

template <class T>
class BinaryTreeNode{

friend class BinaryTree<T>;

private:
    T info;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
public:
    BinaryTreeNode();
    BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l=0, BinaryTreeNode<T>* r=0);

    T value() const;
    BinaryTreeNode<T>* leftchild() const;
    BinaryTreeNode<T>* rightchild() const;
    void setLeftchild(BinaryTreeNode<T>*);
    void setRightchild(BinaryTreeNode<T>*);
    void setValue(const T& val);
    bool isLeft() const;
    BinaryTreeNode<T>& operator=(const BinaryTreeNode<T>& Node);
};

#endif // BINARYTREENODE_H_INCLUDED
