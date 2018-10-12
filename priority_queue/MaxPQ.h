#ifndef __MAXPQ_H__
#define __MAXPQ_H__
//基于二插堆的优先队列
#include <iostream>
using namespace std;
template <class Type>
class MaxPQ
{
private:
	Type *pq;
	const int maxN;
	int counts=0;
public:
	MaxPQ(int num=20);
	~MaxPQ();
	void swim(int k);//堆上浮
	void sink(int k);//堆下沉
	bool less(int a,int b);
	void exch(int a,int b);
	void insert(Type item);//向优先队列插入元素
	Type DelMax();//删除元素
	bool isEmpty() const;
	int size() const;
};

template <class Type>
MaxPQ<Type>::MaxPQ(int num):maxN(num)
{
	pq=new Type[maxN+1];
}

template <class Type>
MaxPQ<Type>::~MaxPQ()
{
	delete [] pq;
}

template <class Type>
bool MaxPQ<Type>::less(int a,int b)
{
	return pq[a]<pq[b];
}

template <class Type>
void MaxPQ<Type>::exch(int a,int b)
{
	Type temp;
	temp=pq[a];
	pq[a]=pq[b];
	pq[b]=temp;
}

template <class Type>
void MaxPQ<Type>::swim(int k)
{
	while(k>1&&less(k/2,k))
	{
		
		exch(k/2,k);
		k=k/2;
	}
}

template <class Type>
void MaxPQ<Type>::sink(int k)
{
	while(2*k<=counts)
	{
		int j=2*k;
		if(j<counts&&less(j,j+1))
			j++;
		if(!less(k,j))
			break;
		exch(k,j);
		k=j;
	}
}

template <class Type>
void MaxPQ<Type>::insert(Type item)
{
	if(counts==maxN)
	{
		cout<<"队满\n";
		return;
	}
	pq[++counts]=item;
	swim(counts);
}

template <class Type>
Type MaxPQ<Type>::DelMax()
{
	Type item;
	if(isEmpty())
	{
		cout<<"队空\n";
		exit(1);
	}
	item=pq[1];
	exch(1,counts);
	pq[counts--]=0;
	sink(1);
	return item;
}

template <class Type>
bool MaxPQ<Type>::isEmpty() const
{
	return counts==0;
}

template <class Type>
int MaxPQ<Type>::size() const
{
	return counts;
}
#endif