#ifndef __BAG_H__ 
#define __BAG_H__
#include <cstdlib>
typedef double Item;
class Bag
{
private:
	struct Node
	{
		Item item;
		struct Node *next;
	};
	Node *front;
	Node *rear;
	int items;
public:
	Bag();
	~Bag();
	bool add(const Item &item);//添加一个元素
	bool isEmpty();//背包是否为空
	int size();//背包中元素数量
	double average();
};
#endif
