#ifndef __STACK_H__
#define __STACK_H__
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
//typedef char Item;
using namespace std;
template <class Type>
class Stack
 {
 private:
 	struct Node
 	{
 		Type item;
 		struct Node *next;
 	};
 	enum {SIZE=20};
 	const int size;
 	Node *top;
 	Node *bottom;
 	int items;
 public:
 	Stack(int qs=SIZE);
 	~Stack();
 	bool isEmpty();
 	bool isfull();
 	int stackcount();
 	bool push(const Type &item);
 	Type pop();
 	char get_topitem();//返回栈顶元素
 }; 

template <class Type>
Stack<Type>::Stack(int qs):size(qs)
{
	top=bottom=NULL;
	items=0;
}

template <class Type>
Stack<Type>::~Stack()
{
	Node *temp;
	while(top!=NULL)
	{
		temp=top;
		top=top->next;
		delete temp;
	}
}

template <class Type>
bool Stack<Type>::isEmpty()
{
	return items==0;
}

template <class Type>
bool Stack<Type>::isfull()
{
	return items==size;
}

template <class Type>
int Stack<Type>::stackcount()
{
	return items;
}

template <class Type>
bool Stack<Type>::push(const Type &item)
{
	if(isfull())
		return false;
	Node *add=new Node;
	add->item=item;
	add->next=NULL;
	items++;
	if(top==NULL)
		bottom=add;
	else
		add->next=top;
	top=add;
	return true;
}

template <class Type>
Type Stack<Type>::pop()
{
	if(isEmpty())
		return false;
	Type item;
	item=top->item;
	items--;
	Node *temp=top;
	top=top->next;
	delete temp;
	if(items==0)
		bottom=NULL;
	return item;
}

template <class Type>
char Stack<Type>::get_topitem()
{
	if(top==NULL)
		return '#';
	else
		return top->item;
}
#endif