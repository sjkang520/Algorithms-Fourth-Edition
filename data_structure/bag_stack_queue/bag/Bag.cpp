#include "Bag.h"
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
}
bool Bag::add(const Item &item)
{
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