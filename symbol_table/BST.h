#ifndef __BST_H__
#define __BST_H__
#include <iostream>

template <typename Key,typename Value>
class Node
{
public:
	Key m_key;
	Value m_val;
	int N;
	Node<Key,Value> *left;
	Node<Key,Value> *right;
	Node(Key key,Value val,int num):m_key(key),m_val(val),N(num)
	{
		left=nullptr;
		right=nullptr;
	}
};

template <typename Key,typename Value>
class BST
{
private:
	Node<Key,Value> *root;//根结点
public:
	BST();
	~BST();
	void put(Key key,Value val);
	Node<Key,Value> *put(Node<Key,Value> *node,Key key,Value val);
	Value get(Key key) const;
	Value get(Node<Key,Value> *node,Key key) const;
	int size(Node<Key,Value> *node) const;//以node结点为根的子数的结点总数
	int size() const;//该树的结点总数
	Key min() const;//最小键
	Node<Key,Value>* min(Node<Key,Value> *node) const;
	Key max() const;//最大键
	Node<Key,Value>* max(Node<Key,Value> *node) const;
	Key floor(Key key) const;//找出小于等于key的最大键
	Node<Key,Value>* floor(Node<Key,Value> *node,Key key) const;
	Key ceiling(Key key) const;//找出大于等于key的最小键
	Node<Key,Value>* ceiling(Node<Key,Value> *node,Key key) const;
	Key select(int k) const;//找出排名为k的键（即恰好有k个键小于key）
	Node<Key,Value>* select(Node<Key,Value> *node,int k) const;
	int rank(Key key) const;//返回给定键的排名
	int rank(Node<Key,Value> *node,Key key) const;
	void deleteMax();//删除最大结点
	Node<Key,Value>* deleteMax(Node<Key,Value> *node);
	void deleteMin();//删除最小结点
	Node<Key,Value>* deleteMin(Node<Key,Value> *node);
	void Delete(Key key);//删除结点
	Node<Key,Value>* Delete(Node<Key,Value>* node,Key key);
	void print1(Node<Key,Value>* node);//中序遍历
	void print2(Node<Key,Value>* node);//前序遍历
	void print3(Node<Key,Value>* node);//后序遍历
	void print();
};

template <typename Key,typename Value>
BST<Key,Value>::BST()
{
	root=nullptr;
}

template <typename Key,typename Value>
BST<Key,Value>::~BST()
{
	while(root!=nullptr)
	{
		deleteMax();
		std::cout<<"delete done! ";
	}
	std::cout<<std::endl;
}

template <typename Key,typename Value>
void BST<Key,Value>::put(Key key,Value val)
{
	root=put(root,key,val);
}

template <typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::put(Node<Key,Value> *node,Key key,Value val)
{
	if(node==nullptr)
		return new Node<Key,Value>(key,val,1);
	if(key<node->m_key)
		node->left=put(node->left,key,val);
	else if(key>node->m_key)
		node->right=put(node->right,key,val);
	else
		node->m_val=val;
	node->N=size(node->left)+size(node->right)+1;
	return node;
}

template <typename Key,typename Value>
Value BST<Key,Value>::get(Key key) const
{
	return get(root,key);
}

template <typename Key,typename Value>
Value BST<Key,Value>::get(Node<Key,Value> *node,Key key) const
{
	if(node==nullptr)
	{
		std::cout<<"can't get the key\n";
		return 0;
	}
	if(key<node->m_key)
		return get(node->left,key);
	else if(key>node->m_key)
		return get(node->right,key);
	else
		return node->m_val;
}

template <typename Key,typename Value>
int BST<Key,Value>::size(Node<Key,Value> *node) const
{
	if(node==nullptr)
		return 0;
	else 
		return node->N;
}

template <typename Key,typename Value>
int BST<Key,Value>::size() const
{
	return size(root);
}

template <typename Key,typename Value>
Key BST<Key,Value>::max() const
{
	if(root==nullptr)
	{
		std::cout<<"the tree is null.\n";
		return 0;
	}
	return max(root)->m_key;
}

template <typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::max(Node<Key,Value> *node) const
{
	if(node->right==nullptr)
		return node;
	else
		return max(node->right);
}

template <typename Key,typename Value>
Key BST<Key,Value>::min() const
{
	if(root==nullptr)
	{
		std::cout<<"the tree is null.\n";
		return 0;
	}
	return min(root)->m_key;
}

template <typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::min(Node<Key,Value> *node) const
{
	if(node->left==nullptr)
		return node;
	else
		return min(node->left);
}

template <typename Key,typename Value>
Key BST<Key,Value>::floor(Key key) const
{
	Node<Key,Value> *temp=floor(root,key);
	if(temp==nullptr)
	{
		std::cout<<"can't find the key which 小于等于key\n";
		return 0;
	}
	else
		return temp->m_key;
}

template <typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::floor(Node<Key,Value> *node,Key key) const
{
	Node<Key,Value> *t;
	if(node==nullptr)
		return nullptr;
	if(key==node->m_key)
		return node;
	else if(key<node->m_key)
		return floor(node->left,key);
	else
	{
		t=floor(node->right,key);
		if(t==nullptr)
			return node;
		else 
			return t;
	}
}

template <typename Key,typename Value>
Key BST<Key,Value>::ceiling(Key key) const
{
	Node<Key,Value> *temp=ceiling(root,key);
	if(temp==nullptr)
	{
		std::cout<<"can't find the key which 大于等于key\n";
		return 0;
	}
	else
		return temp->m_key;
}

template <typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::ceiling(Node<Key,Value> *node,Key key) const
{
	Node<Key,Value> *t;
	if(node==nullptr)
		return nullptr;
	if(key==node->m_key)
		return node;
	else if(key>node->m_key)
		return ceiling(node->right,key); 
	else
	{
		t=ceiling(node->left,key);
		if(t==nullptr)
			return node;
		else
			return t;
	}
}

template <typename Key,typename Value>
Key BST<Key,Value>::select(int k) const
{
	Node<Key,Value> *temp=select(root,k);
	if(temp==nullptr)
	{
		std::cout<<"not find\n";
		return 0;
	}
	else
		return temp->m_key;
}

template <typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::select(Node<Key,Value>* node,int k) const
{
	Node<Key,Value> *t;
	if(node==nullptr)
		return nullptr;
	int n=size(node->left);
	if(n==k)
		return node;
	else if(n>k)
		return select(node->left,k);
	else
		return select(node->right,k-n-1);

}

template <typename Key,typename Value>
int BST<Key,Value>::rank(Key key) const
{
	return rank(root,key);
}

template <typename Key,typename Value>
int BST<Key,Value>::rank(Node<Key,Value> *node,Key key) const
{
	if(node==nullptr)
		return 0;
	if(node->m_key==key)
		return size(node->left);
	else if(node->m_key>key)
		return rank(node->left,key);
	else
		return (size(node->left)+1+rank(node->right,key));
}

template <typename Key,typename Value>
void BST<Key,Value>::deleteMax()
{
	if(root==nullptr)
	{
		std::cout<<"the tree is null\n";
		return;
	}
	root=deleteMax(root);
}

template <typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::deleteMax(Node<Key,Value> *node)
{
	Node<Key,Value> *temp;
	Node<Key,Value> *max_left;
	if(node->right==nullptr)
	{
		temp=node;
		max_left=node->left;
		delete temp;
		return max_left;
	}
	else
		node->right=deleteMax(node->right);
	node->N=size(node->left)+size(node->right)+1;
	return node;
}

template <typename Key,typename Value>
void BST<Key,Value>::deleteMin()
{
	if(root==nullptr)
	{
		std::cout<<"the tree is null\n";
		return;
	}
	root=deleteMin(root);
}

template <typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::deleteMin(Node<Key,Value>* node)
{
	Node<Key,Value> *temp;
	Node<Key,Value> *min_right;
	if(node->left==nullptr)
	{
		temp=node;
		min_right=node->right;
		delete temp;
		return min_right;
	}
	else
		node->left=deleteMin(node->left);
	node->N=size(node->left)+size(node->right)+1;
	return node;
}

template <typename Key,typename Value>
void BST<Key,Value>::Delete(Key key)
{
	root=Delete(root,key);
}

template <typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::Delete(Node<Key,Value>* node,Key key)
{
	Node<Key,Value>* temp;
	Node<Key,Value>* childmin;
	Node<Key,Value>* x;
	if(node==nullptr)
		return nullptr;
	if(key<node->m_key)
		node->left=Delete(node->left,key);
	else if(key>node->m_key)
		node->right=Delete(node->right,key);
	else
	{	
		
		temp=node;//要删除的结点
		if(temp->left==nullptr)
		{
			x=temp->right;
			delete temp;
			return x;
		}
		if(temp->right==nullptr)
		{
			x=temp->left;
			delete temp;
			return x;
		}
		childmin=min(temp->right);//要删除的结点的右子树的最小结点
		x=new Node<Key,Value>(childmin->m_key,childmin->m_val,1);
		x->right=deleteMin(temp->right);
		x->left=temp->left;
		x->N=size(x->right)+size(x->left)+1;
		delete temp;
		return x;
	}
	node->N=size(node->right)+size(node->left)+1;
	return node;
}

template <typename Key,typename Value>
void BST<Key,Value>::print1(Node<Key,Value>* node)//中序
{
	if(node==nullptr)
		return;
	print1(node->left);
	std::cout<<node->m_key<<" ";
	print1(node->right);
}

template <typename Key,typename Value>
void BST<Key,Value>::print2(Node<Key,Value>* node)//前序
{
	if(node==nullptr)
		return;
	std::cout<<node->m_key<<" ";
	print2(node->left);
	print2(node->right);
}

template <typename Key,typename Value>
void BST<Key,Value>::print3(Node<Key,Value>* node)//后序
{
	if(node==nullptr)
		return;
	print3(node->left);
	print3(node->right);
	std::cout<<node->m_key<<" ";
}

template <typename Key,typename Value>
void BST<Key,Value>::print()
{
	print3(root);
	std::cout<<std::endl;
}


#endif