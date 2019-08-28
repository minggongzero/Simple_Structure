#ifndef BINARY_SEARCH_TREE_H_INCLUDE
#define BINARY_SEARCH_TREE_H_INCLUDE

#include <iostream>
#include <vector>
#include "binary_tree.h"

template <typename T>
class binary_search_tree : public binary_tree<T>
{
public:
	typedef bool (*compare)(const T&);
	binary_tree_node<T>* search(T);
	binary_tree_node<T>* search(T, compare);
	bool insert(binary_tree_node<T>*);
	bool remove(binary_tree_node<T>*);
	//virtual ~binary_search_tree();
};

template <typename T>
binary_tree_node<T>* binary_search_tree<T>::search(T val)
{
	binary_tree_node<T>* p = this->root;
	while(p != nullptr)
	{
		if(p->val == val) break;
		else if(p->val < val) p = p->leftchild;
		else p = p->rightchild;
	}	
	return p;
}

template <typename T>
binary_tree_node<T>* binary_search_tree<T>::search(T val, compare comp)
{
        binary_tree_node<T>* p = this->root;
        while(p != nullptr)
        {
                if(p->val == val) break;
                else if(p->val.*comp(val)) p = p->leftchild;
                else p = p->rightchild;
        }
        return p;
}

template <typename T>
bool binary_search_tree<T>::insert(binary_tree_node<T>* node)
{
	if(!node) return true;
	binary_tree_node<T>* p = this->root;
	while(p)
	{
		if(p->val < node->val)
		{
			if(p->leftchild)
			{
				p = p->leftchild;
				continue;
			}
			p->leftchild = node;
		}
		else
		{
			if(p->rightchild)
			{
				p = p->rightchild;
				continue;
			}
			p->rightchild = node;
		}
		node->parent = p;
		break;
	}
	if(!p) this->root = node;
	return true;
}

template <typename T>
bool binary_search_tree<T>::remove(binary_tree_node<T>* node)
{
	if(!this->root || !node) return true;
	if(!node->leftchild)    //case1: has not leftchild
	{
		std::cout << "case1 start" << std::endl;
		if(node == this->root)
		{
			std::cout << "case1 remove root" << std::endl;
			this->root = node->rightchild;
			if(node->rightchild)
			{
				std::cout << "case1 last remove" << std::endl;
				node->rightchild->parent = nullptr;
			}
		}
		else
		{
			if(node == node->parent->leftchild)
				node->parent->leftchild = node->rightchild;
			else node->parent->rightchild = node->rightchild;
			if(node->rightchild) node->rightchild->parent = node->parent;
		}
		return true;
	}
	else if(!node->rightchild)    //case2: has not rightchild
	{
		std::cout << "case2 start" << std::endl;
		if(node == this->root)
		{
			this->root = node->leftchild;
			if(node->leftchild)
				node->leftchild->parent = nullptr;
		}
		else	
		{
			if(node == node->parent->leftchild)
				node->parent->leftchild = node->leftchild;
			else node->parent->rightchild = node->leftchild;
			if(node->leftchild) node->leftchild->parent = node->parent;
		}
		return true;
	}
	//case3 
	if(!node->rightchild->leftchild)
	{
		std::cout << "case3 start" << std::endl;
		node->rightchild->leftchild = node->leftchild;
		node->leftchild->parent = node->rightchild;
		if(node == this->root)
		{
			node->rightchild->parent = nullptr;
			this->root = node->rightchild;
		}
		else if(node->parent->leftchild == node)
		{
			node->parent->leftchild = node->rightchild;
			node->rightchild->parent = node->parent;	
		}
		else
		{
			node->parent->rightchild = node->rightchild;
			node->rightchild->parent = node->parent;
		}
		return true;
	}
	//case4
	binary_tree_node<T>* nenode = node->rightchild;
	while(nenode->leftchild) nenode = nenode->leftchild;
	nenode->parent->leftchild = nenode->rightchild;
	if(nenode->rightchild) nenode->rightchild->parent = nenode->parent;
	nenode->rightchild = node->rightchild;
	nenode->leftchild = node->leftchild;
	node->leftchild->parent = nenode;
	if(node == this->root)
		this->root = nenode;
	else if(node->parent->leftchild == node)
		node->parent->leftchild = nenode;
	else
		node->parent->rightchild = nenode;
	nenode->parent = node->parent;
	
	return true;
}

#endif    // BINARY_SEARCH_TREE_H_INCLUDE
