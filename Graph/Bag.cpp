#include "Bag.h"
#include <iostream>
Bag::Bag()
{
	front=rear=NULL;
	items=0;
}
Bag::~Bag()
{
	Node *temp;
	while(front!=NULL)
	{
		temp=front;
		front=front->next;
		delete temp;
	}
	//std::cout<<"bag destruct\n";
}
bool Bag::add(Item item)
{
	//std::cout<<"add\n";
	Node *add=new Node;
	add->item=item;
	add->next=NULL;
	items++;
	if(front==NULL)
		front=add;
	else
		rear->next=add;
	rear=add;
	return true;
}
bool Bag::isEmpty()
{
	return items==0;
}
int Bag::size()
{
	return items;
}

double Bag::average()
{
	double sum;
	Node *it=front;
	while(it!=NULL)
	{
		sum+=it->item;
		it=it->next;
	}
	return sum/items;
}

void Bag::show()
{
	Node *temp;
	temp=front;
	while(temp!=NULL)
	{
		std::cout<<temp->item<<" ";
		temp=temp->next;
	}
}