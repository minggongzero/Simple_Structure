#ifndef RB_TREE_H_INCLUDE
#define RB_TREE_H_INCLUDE

#include <iostream>
#include <vector>
#include <deque>

enum Color{RED, BLACK};

template <typename T>
class rb_tree_node
{
public:
	T val;
	rb_tree_node<T>* leftchild = nullptr;
	rb_tree_node<T>* rightchild = nullptr;
	rb_tree_node<T>* parent = nullptr;
	Color color;
};

template <typename T>
class rb_tree
{
public:
	rb_tree_node<T>* root;
	rb_tree_node<T>* nil;
	rb_tree();
	~rb_tree();
	void left_rotate(rb_tree_node<T>*);
	void right_rotate(rb_tree_node<T>*);
	void insert_fix(rb_tree_node<T>*);
	void remove_fix(rb_tree_node<T>*);
	rb_tree_node<T>* search(const T&);
	bool insert(rb_tree_node<T>*);
	bool remove(rb_tree_node<T>*);
	void BFS(std::vector<T>&, std::vector<int>&);
	void output();
};

template <typename T>
inline rb_tree<T>::rb_tree()
{
	this->nil = new rb_tree_node<T>();
	nil->color = BLACK;
}

template <typename T>
inline rb_tree<T>::~rb_tree()
{
	delete nil;
}

template <typename T>
void rb_tree<T>::left_rotate(rb_tree_node<T>* node)
{
	if(node == this->nil || (node->rightchild == this->nil)) return;
	rb_tree_node<T>* tmp = node->rightchild;
	node->rightchild = tmp->leftchild;
	if(tmp->leftchild != this->nil) tmp->leftchild->parent = node;
	tmp->leftchild = node;
	tmp->parent = node->parent;
	if(node->parent != this->nil)
	{
		if(node->parent->leftchild == node) 
			node->parent->leftchild = tmp;
		else node->parent->rightchild = tmp;
	}
	node->parent = tmp;
	if(node == this->root) this->root = tmp;
}

template <typename T>
void rb_tree<T>::right_rotate(rb_tree_node<T>* node)
{
	if(node == this->nil || (node->leftchild == this->nil)) return;
	rb_tree_node<T>* tmp = node->leftchild;
	node->leftchild = tmp->rightchild;
	if(tmp->rightchild != this->nil) tmp->rightchild->parent = node;
	tmp->rightchild = node;
	tmp->parent = node->parent;
	if(node->parent != this->nil)
	{
		if(node->parent->leftchild == node) 
			node->parent->leftchild = tmp;
		else node->parent->rightchild = tmp;
	}
	node->parent = tmp;	
	if(node == this->root) this->root = tmp;
}

template <typename T>
void rb_tree<T>::insert_fix(rb_tree_node<T>* node)
{
	while(node->parent->color == RED)
	{	
		if(node->parent == node->parent->parent->leftchild)
		{
			rb_tree_node<T>* y = node->parent->parent->rightchild;
			//case 1
			if(y->color == RED)
			{
				std::cout << "insert_fix case 1" << std::endl;
				node->parent->color = y->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
				continue;
			}
			//case 2
			else if(node->parent->rightchild == node)
			{
				std::cout << "insert_fix case 2" << std::endl;
				node = node->parent;
				left_rotate(node);
			}
			//case 3
			std::cout << "insert_fix case 3" << std::endl;
			node->parent->color = BLACK;
			node->parent->parent->color = RED;
			right_rotate(node->parent->parent);
		}
		else
		{
			rb_tree_node<T>* y = node->parent->parent->leftchild;
			std::cout << y->parent->val << std::endl;
			//case 4
			if(y->color == RED)
			{
				std::cout << "insert_fix case 4" << std::endl;
				node->parent->color = y->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
				continue;
			}
			//case 5
			else if(node->parent->leftchild == node)
			{
				std::cout << "insert_fix case 5" << std::endl;
				node = node->parent;
				right_rotate(node);
			}
			//case 6
			std::cout << "insert_fix case 6" << std::endl;
			node->parent->color = BLACK;
			node->parent->parent->color = RED;
			left_rotate(node->parent->parent);	
		}
	}
	this->root->color = BLACK;
}

template <typename T>
void rb_tree<T>::remove_fix(rb_tree_node<T>* node)
{
	if(!node || (node == this->nil)) return;
	while(node != this->root && (node->color == BLACK))
	{
		if(node->parent->leftchild == node)
		{
			rb_tree_node<T>* w = node->parent->rightchild;
			//case 1
			if(w->color == RED)
			{
				node->parent->color = RED;
				w->color = BLACK;
				left_rotate(node->parent);
			}
			else if(w->leftchild->color == BLACK && (w->rightchild->color == BLACK))    //case 2
			{
				w->color = RED;
				node = node->parent;
			}
			else if(w->leftchild->color == RED && (w->rightchild->color == BLACK))
			{
				w->color = RED;
				w->leftchild->color = BLACK;
				right_rotate(w);
			}
			else    //case 4
			{
				w->color = node->parent->color;
				node->parent->color = BLACK;
				w->rightchild->color = BLACK;
				left_rotate(node->parent);
				node = this->root;		
			}
		}
		else
		{
			rb_tree_node<T>* w = node->parent->leftchild;
			//case 5
			if(w->color == RED)
			{
				node->parent->color = RED;
				w->color = BLACK;
				right_rotate(node->parent);
			}
			else if(w->leftchild->color == BLACK && (w->rightchild->color == BLACK))    //case 6
			{
				w->color = RED;
				node = node->parent;
			}
			else if(w->rightchild->color == RED && (w->leftchild->color == BLACK))    //case 7
			{
				w->color = RED;
				w->rightchild->color = BLACK;
				left_rotate(w);
			}
			else    //case 8
			{
				w->color = node->parent->color;
				node->parent->color = BLACK;
				w->leftchild->color = BLACK;
				right_rotate(node->parent);
				node = this->root;		
			}
		}
	}
	node->color = BLACK;
}

template <typename T>
rb_tree_node<T>* rb_tree<T>::search(const T& val)
{
	return nullptr;
}

/**
 * 插入一个节点node，注意此操作将改变node节点原有信息
 **/
template <typename T>
bool rb_tree<T>::insert(rb_tree_node<T>* node)
{
	if(!node || (node == this->nil)) return true;
	if(this->root == this->nil) 
	{
		node->color = BLACK; 
		node->parent = node->leftchild = node->rightchild = this->nil;
		this->root = node; 
		return true;
	}
	rb_tree_node<T>* tmp = this->root;
	while(tmp != this->nil)
	{
		if(node->val < tmp->val)
		{
			if(tmp->leftchild != this->nil)
			{
				tmp = tmp->leftchild;
				continue;	
			}
			tmp->leftchild = node;
		}
		else
		{
			if(tmp->rightchild != this->nil)
			{
				tmp = tmp->rightchild;
				continue;
			}
			tmp->rightchild = node;
		}
		node->color = RED;
		node->parent = tmp;
		node->leftchild = node->rightchild = this->nil;
		break;
	}
	insert_fix(node);
	return true;
}

template <typename T>
bool rb_tree<T>::remove(rb_tree_node<T>* node)
{
	rb_tree_node<T>* x, *y = node;
	Color y_origin_color = node->color;
	//case 1
	if(node->leftchild == this->nil)
	{
		x = node->rightchild;
		x->parent = node->parent;
		if(node->parent != this->nil)
		{
			if(node->parent->leftchild == node) node->parent->leftchild = x;
			else node->parent->rightchild = x;
		}
		else this->root = x;
	}
	else if(node->rightchild == this->nil)    //case 2
	{
		x = node->leftchild;
		x->parent = node->parent;
		if(node->parent != this->nil)
		{
			if(node->parent->leftchild == node) node->parent->leftchild = x;
			else node->parent->rightchild = x;
		}	
		else this->root = x;
	}
	else
	{
		y = node->rightchild;
		while(y->leftchild != this->nil)
			y = y->leftchild;
		y_origin_color = y->color;
		x = y->rightchild;
		//case 3
		if(node->rightchild == y)
		{
			y->parent = node->parent;
			y->leftchild = node->leftchild;
			node->leftchild->parent = y;
			if(node->parent != this->nil)
			{
				if(node->parent->leftchild == node) node->parent->leftchild = y;
				else node->parent->rightchild = y;
		
			}
			else this->root = y;
		}
		else    //case 4
		{
			y->parent->leftchild = x;
			x->parent = y->parent;
			y->rightchild = node->rightchild;
			node->rightchild->parent = y;
			y->leftchild = node->leftchild;
			node->leftchild->parent = y;
			if(node->parent != this->nil)
			{
				if(node->parent->leftchild == node) node->parent->leftchild = y;
				else node->parent->rightchild = y;
			}	
			else this->root = y;
		}
		y->color = node->color;
	}
	if(y_origin_color == BLACK)
		remove_fix(x);
	return true;
}

template <typename T>
void rb_tree<T>::BFS(std::vector<T>& result, std::vector<int>& re_color)
{
	std::deque<rb_tree_node<T>*> que;
	if(root && (root != this->nil)) que.push_back(root);
	while(!que.empty())
	{
		rb_tree_node<T>* p = que.front();
		result.push_back(p->val);
		re_color.push_back(p->color);
		if(p->leftchild != this->nil)
			que.push_back(p->leftchild);
		if(p->rightchild != this->nil)
			que.push_back(p->rightchild);
		que.pop_front();
	}
}

template <typename T>
void rb_tree<T>::output()
{	
	std::vector<int> re, re_color;
	BFS(re, re_color);
	std::cout << "output: ";
	for(int i=0; i<re.size(); ++i)
	{
		std::cout << re[i] << "[" << (re_color[i]? "BLACK" : "RED") << "]" <<' ';
	}
	std::cout << std::endl;
}

#endif   //RB_TREE_H_INCLUDE
