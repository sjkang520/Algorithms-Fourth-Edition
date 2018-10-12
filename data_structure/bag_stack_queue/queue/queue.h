#ifndef __QUEUE_H__
#define __QUEUE_H__

class queue
{
private:
	enum {Q_SIZE=20};
	struct Node
	{
		Item item;
		struct Node *next;
	};
	const int size;
public:
	queue(int qs=Q_SIZE);
	~queue();
	
};
#endif