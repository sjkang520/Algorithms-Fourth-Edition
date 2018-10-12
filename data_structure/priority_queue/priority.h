#ifndef __PRIORITY_H__
#define __PRIORITY_H__
//优先队列，利用数组实现
#include<iostream>
using namespace std;
template <class Type>
class priority
{
private:
	int top=-1;
	int num=0;
	const int maxsize;
	Type *a;
public:
	priority(int N=4);
	~priority();
	void insert(Type item);//向优先队列中插入元素
	Type delMax();//删除并返回最大元素
	Type max();//返回最大元素
	bool isEmpty();//是否为空
	int size();//优先队列元素个数
};

template <class Type>
priority<Type>::priority(int N):maxsize(N)
{
	a=new Type[maxsize];
}

template <class Type>
priority<Type>::~priority()
{
	delete [] a;
}

template <class Type>
void priority<Type>::insert(Type item)
{
	if(top==maxsize-1)
	{
		cout<<"队列满\n";
		return;
	}
	a[++top]=item;
	num++;
}

template <class Type>
Type priority<Type>::delMax()
{
	if(top==-1)
	{
		cout<<"队列空\n";
		exit(1);
	}
	//找出最大元素
	int max=0;
	for(int i=1;i<top+1;i++)
	{
		if(a[i]>a[max])
			max=i;
	}
	//将最大元素移至栈顶
	Type temp;
	temp=a[max];
	a[max]=a[top];
	a[top]=temp;
	//删除最大元素
	temp=a[top--];
	num--;
	return temp;
}

template <class Type>
Type priority<Type>::max()
{
	if(top==-1)
	{
		cout<<"队列空\n";
		exit(1);
	}
	int max=0;
	for(int i=1;i<top+1;i++)
	{
		if(a[i]>a[max])
			max=i;
	}
	return a[max];
}

template <class Type>
bool priority<Type>::isEmpty()
{
	return top==-1;
}

template <class Type>
int priority<Type>::size()
{
	return top+1;
}
#endif