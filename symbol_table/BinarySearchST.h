#ifndef __BINARYSEARCHST_H__
#define __BINARYSEARCHST_H__
#include <vector>
template <typename Key,typename Value>
class BinarySearchST
{
private:
	std::vector<Key> Keys;
	std::vector<Value> Values;
	int N=0;
public:
	BinarySearchST();
	~BinarySearchST();
	void put(Key key,Value val);//向符号表中插入键值
	Value get(Key key) const;//返回键key对应的值
	void Delete(Key key);//
	bool isEmpty() const;
	bool contains(Key key) const;
	int size() const;
	Key min() const;
	Key max() const;
	Key floor(Key key) const;//小于等于key的最大键
	Key ceiling(Key key) const;//大于等于Key的最小键
	int rank(Key key) const;//小key键的数量
	int rank(Key key,int lo,int hi) const;//递归查找
	Key select(int k) const;//找出排名k的键
	void deleteMin();
	void deleteMax();
	int size(Key lo,Key hi);//lo和hi之间键的数量
//	std::vector<Key> keys(Key lo,Key hi);//lo和hi之间键的集合
//	std::vector<Key> keys();//返回表中所有键的集合
};

template <typename Key,typename Value>
BinarySearchST<Key,Value>::BinarySearchST()
{

}

template <typename Key,typename Value>
BinarySearchST<Key,Value>::~BinarySearchST()
{
	
}

template <typename Key,typename Value>
void BinarySearchST<Key,Value>::put(Key key,Value val)
{

}

template <typename Key,typename Value>
Value BinarySearchST<Key,Value>::get(Key key) const
{

}

template <typename Key,typename Value>
void BinarySearchST<Key,Value>::Delete(Key key)
{

}

template <typename Key,typename Value>
bool BinarySearchST<Key,Value>::isEmpty() const
{

}

template <typename Key,typename Value>
bool BinarySearchST<Key,Value>::contains(Key key) const
{

}

template <typename Key,typename Value>
int BinarySearchST<Key,Value>::size() const
{

}

template <typename Key,typename Value>
Key BinarySearchST<Key,Value>::min() const
{

}

template <typename Key,typename Value>
Key BinarySearchST<Key,Value>::max() const
{

}

template <typename Key,typename Value>
Key BinarySearchST<Key,Value>::floor(Key key) const
{
	int i=rank(key);
	if(i<N&&key==Keys[i])
		return Keys[i];
	if(i==0)
		return 0;
	return Keys[i-1];
}

template <typename Key,typename Value>
Key BinarySearchST<Key,Value>::ceiling(Key key) const
{
	int i=rank(key);
	if(i==N)
		return 0;
	return Keys[i];
}

template <typename Key,typename Value>
int BinarySearchST<Key,Value>::rank(Key key) const
{
	int lo=0;
	int hi=N-1;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(key<Keys[mid])
			hi=mid-1;
		else if(key>Keys[mid])
			lo=mid+1;
		else
			return mid;
	}
	return lo;
}

template <typename Key,typename Value>
int BinarySearchST<Key,Value>::rank(Key key,int lo,int hi) const
{
	if(hi<lo)
		return lo;
	int mid=lo+(hi-lo)/2;
	if(key<Keys[mid])
		return rank(key,lo,mid-1);
	else if(key>Keys[mid])
		return rank(key,mid+1,hi);
	else
		return mid;
}

template <typename Key,typename Value>
Key BinarySearchST<Key,Value>::select(int k) const
{

}

template <typename Key,typename Value>
void BinarySearchST<Key,Value>::deleteMin()
{

}

template <typename Key,typename Value>
void BinarySearchST<Key,Value>::deleteMax()
{

}

template <typename Key,typename Value>
int BinarySearchST<Key,Value>::size(int lo,int hi) const
{

}

#endif