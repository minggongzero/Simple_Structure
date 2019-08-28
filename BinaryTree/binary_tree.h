#ifndef BINARY_TREE_H_INCLUDE
#define BINARY_TREE_H_INCLUDE

#include <iostream>
#include <vector>
#include <stack>
#include <deque>

template <typename T>
class binary_tree_node
{
public:
	T val;
	binary_tree_node<T>* leftchild = nullptr;
	binary_tree_node<T>* rightchild = nullptr;
	binary_tree_node<T>* parent = nullptr;
};

template <typename T>
class binary_tree
{
public:
	binary_tree_node<T>* root;
	binary_tree();
	//binary_tree(vector<T>&);
	//virtual ~binary_tree();
	//binary_tree(const binary_tree<T>&);
	//binary_tree<T>& operator=(binary_tree<T>&);
	std::vector<T> TLR_DFS();
	std::vector<T> LTR_DFS();
	std::vector<T> LRT_DFS();
	std::vector<T> BFS();
};

template <typename T>
binary_tree<T>::binary_tree()
{
			
}

/*
template <typename T>
binary_tree<T>::binary_tree(vector<T>& values)
{
	if(!values.empty())
	{
		for(int i=0; i<values.size(); ++i)
		{
			binary_tree_node<T>* node = new binary_tree_node<T>();
			node->val = values[i];
			
		}
	}	
}
*/

template <typename T>
std::vector<T> binary_tree<T>::TLR_DFS()
{
	std::stack<binary_tree_node<T>*, std::vector<binary_tree_node<T>*>> sta;
	std::vector<T> result;
	binary_tree_node<T>* current_p = root;
	while(current_p != nullptr || !sta.empty())
	{
		if(current_p != nullptr)
		{
			result.push_back(current_p->val);
			if(current_p->rightchild != nullptr)
				sta.push(current_p->rightchild);
			current_p = current_p->leftchild;
		}
		else
		{
			current_p = sta.top();
			sta.pop();
		}	
	}		
	return result;
}

template <typename T>
std::vector<T> binary_tree<T>::LTR_DFS()
{
	std::vector<T> result;	
	std::stack<binary_tree_node<T>*, std::vector<binary_tree_node<T>*>> sta;
	binary_tree_node<T>* current_p = root;
	while(current_p != nullptr || !sta.empty())
	{
		if(current_p != nullptr)
		{
			sta.push(current_p);
			current_p = current_p->leftchild;
		}
		else
		{
			current_p = sta.top();
			result.push_back(current_p->val);
			current_p = current_p->rightchild;
			sta.pop();
		}
	}
	return result;
}

template <typename T>
std::vector<T> binary_tree<T>::LRT_DFS()
{
	std::vector<T> result;
	std::stack<binary_tree_node<T>, std::vector<binary_tree_node<T>>> sta;

	return result;
}

template <typename T>
std::vector<T> binary_tree<T>::BFS()
{
	std::vector<T> result;
	std::deque<binary_tree_node<T>*> que;
	if(root) que.push_back(root);
	while(!que.empty())
	{
		binary_tree_node<T>* p = que.front();
		result.push_back(p->val);
		if(p->leftchild != nullptr)
			que.push_back(p->leftchild);
		if(p->rightchild != nullptr)
			que.push_back(p->rightchild);
		que.pop_front();
	}
	return result;
}

#endif //BINARY_TREE_H_INCLUDE
