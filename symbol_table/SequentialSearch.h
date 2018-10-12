#ifndef __SEQUENTIALSEARCH_H__
#define __SEQUENTIALSEARCH_H__
#include <iostream>
template <typename Key,typename Value>
class SequentialSearch
{
private:
	struct Node
	{
		Key key;
		Value val;
		struct Node *Next;
	};
	struct Node *first;
	int N=0;
public:
	SequentialSearch();
	~SequentialSearch();
	void put(Key key,Value val);//把一对键值存入符号表
	Value get(Key key);//得到键对应的值，不存在返回null
	void Delete(Key key);//删除键key
	Node* deletes(Node *node,Key key);
	bool contains(Key key);//键key在表中是否有对应的值
	bool isEmpty();//是否为空
	int size();//键值的数量
	void show();
};

template <typename Key,typename Value>
SequentialSearch<Key,Value>::SequentialSearch()
{
	first=nullptr;
}

template <typename Key,typename Value>
SequentialSearch<Key,Value>::~SequentialSearch()
{
	Node *temp;
	while(first!=nullptr)
	{
		temp=first;
		first=first->Next;
		delete temp;
	}
}

template <typename Key,typename Value>
void SequentialSearch<Key,Value>::put(Key key,Value val)
{
	for(Node *x=first;x!=nullptr;x=x->Next)
	{
		if(x->key==key)
		{
			x->val=val;
			return;
		}
	}
	Node *add=new Node;
	add->key=key;
	add->val=val;
	add->Next=first;
	first=add;
	N++;
}

template <typename Key,typename Value>
Value SequentialSearch<Key,Value>::get(Key key)
{
	for(Node *x=first;x!=nullptr;x=x->Next)
	{
		if(x->key==key)
			return x->val;
	}
	return 0;
}

template <typename Key,typename Value>
void SequentialSearch<Key,Value>::Delete(Key key)
{
	/*if(key==nullptr)
	{
		std::cout<<"the key to delete is null\n";
		return;
	}*/
	first=deletes(first,key);
}

template <typename Key,typename Value>
typename SequentialSearch<Key,Value>::Node* SequentialSearch<Key,Value>::deletes(Node *node,Key key)
{
	Node *temp;
	if(node==nullptr)
		return nullptr;
	if(node->key==key)
	{	
		temp=node;
		node=node->Next;
		delete temp;
		return node;
		N--;
	}
	node->Next=deletes(node->Next,key);
	return node;
}

template <typename Key,typename Value>
bool SequentialSearch<Key,Value>::contains(Key key)
{
	return get(key)!=0;
}

template <typename Key,typename Value>
bool SequentialSearch<Key,Value>::isEmpty()
{
	return N==0;
}

template <typename Key,typename Value>
int SequentialSearch<Key,Value>::size()
{
	return N;
}

template <typename Key,typename Value>
void SequentialSearch<Key,Value>::show()
{
	Node *temp=first;
	while(temp)
	{
		std::cout<<temp->key<<" "<<temp->val<<std::endl;
		temp=temp->Next;
	}
}
#endif