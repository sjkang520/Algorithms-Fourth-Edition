#ifndef __INDEXMINPQ_H__
#define __INDEXMINPQ_H__
#include <iostream>
using namespace std;
template <class Type>
class IndexMinPQ
{
private:
	const int Maxsize;
	int *pq;//索引
	int *qp;//
	Type *items;
	int num=0;//优先队列中元素个数
public:
	IndexMinPQ(int N=30);
	~IndexMinPQ();
	void insert(int k,Type item);//插入一个元素，并将其与索引k关联
	void change(int k,Type item);//将索引为k的元素设为item;
	bool contains(int k);//是否包含索引为k的元素
	void Delete(int k);//删除索引为k的元素
	Type min() const;//返回最小元素
	int minIndex() const;//返回最小元素的索引
	int delMin();//删除最小元素并返回它的索引
	bool isEmpty() const;//优先队列是否为空
	int size() const;//优先队列中元素个数
	bool greater(int i,int j) const;//
	void exch(int i,int j);//交换位置i和j的索引
	void swim(int i);
	void sink(int i);
	void show() const;
};

template <class Type>
IndexMinPQ<Type>::IndexMinPQ(int N):Maxsize(N)
{
	pq=new int[Maxsize+1];
	qp=new int[Maxsize+1];
	items=new Type[Maxsize+1];
	for(int i=0;i<Maxsize+1;i++)
		qp[i]=-1;
}

template <class Type>
IndexMinPQ<Type>::~IndexMinPQ()
{
	delete [] pq;
	delete [] qp;
	delete [] items;
}

template <class Type>
void IndexMinPQ<Type>::insert(int k,Type item)
{
	if(k<0||k>Maxsize-1)
	{
		cout<<"不在索引范围内"<<endl;
		return;
	}
	if(contains(k))
		return;
	pq[++num]=k;
	qp[k]=num;
	items[k]=item;
	swim(num);

}

template <class Type>
void IndexMinPQ<Type>::change(int k,Type item)
{
	if(k<0||k>Maxsize-1)
	{
		cout<<"索引不再范围内\n";
		return;
	}
	if(!(contains(k)))
	{
		cout<<"不存在该索引\n";
		return;
	}
	items[k]=item;
	swim(qp[k]);
	sink(qp[k]);
}

template <class Type>
bool IndexMinPQ<Type>::contains(int k)
{
	if(k<0||k>Maxsize-1)
	{
		cout<<"索引不再范围内\n";
		exit(1);
	}
	return qp[k]!=-1;
}

template <class Type>
void IndexMinPQ<Type>::Delete(int k)
{
	if(k<0||k>Maxsize-1)
	{
		cout<<"索引不再范围内\n";
		return;
	}
	if(!(contains(k)))
	{
		cout<<"不存在该索引\n";
		return;
	}
	int n=qp[k];
	exch(n,num--);
	swim(n);
	sink(n);
	qp[k]=-1;
}

template <class Type>
Type IndexMinPQ<Type>::min() const
{
	if(num==0)
	{
		cout<<"队列为空\n";
		exit(1);
	}
	return items[pq[1]];
}

template <class Type>
int IndexMinPQ<Type>::minIndex() const
{
	if(num==0)
	{
		cout<<"队列为空\n";
		exit(1);
	}
	return pq[1];
}

template <class Type>
int IndexMinPQ<Type>::delMin() 
{
	if(num==0)
	{
		cout<<"队列为空\n";
		exit(1);
	}
	int index=pq[1];
	exch(1,num--);
	sink(1);
	qp[index]=-1;
	return index;
}

template <class Type>
bool IndexMinPQ<Type>::isEmpty() const
{
	return num==0;
}

template <class Type>
int IndexMinPQ<Type>::size() const
{
	return num;
}

template <class Type>
bool IndexMinPQ<Type>::greater(int i,int j) const
{
	return items[pq[i]]>items[pq[j]];
}

template <class Type>
void IndexMinPQ<Type>::exch(int i,int j)
{
	int temp=pq[i];
	pq[i]=pq[j];
	pq[j]=temp;
	qp[pq[i]]=i;
	qp[pq[j]]=j;
}

template <class Type>
void IndexMinPQ<Type>::swim(int i)
{
	while(i>1&&greater(i/2,i))
	{
		exch(i/2,i);
		i=i/2;
	}
}

template <class Type>
void IndexMinPQ<Type>::sink(int i)
{
	while(2*i<=num)
	{
		int j=2*i;
		if(j<num&&greater(j,j+1))
			j++;
		if(!greater(i,j))
			break;
		exch(i,j);
		i=j;
	}
	
}

template <class Type>
void IndexMinPQ<Type>::show() const
{
	for(int i=1;i<=num;i++)
		cout<<items[pq[i]]<<' ';
	cout<<endl;
}
#endif
