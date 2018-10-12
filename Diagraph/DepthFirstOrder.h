#ifndef __DEPTHFIRSTORDER_H__
#define __DEPTHFIRSTORDER_H__
//有向图中基于深度优先搜索的顶点排序
#include "Diagraph.h"
#include <stack>
#include <queue>
class DepthFirstOrder
{
private:
	std::vector<bool> marked;
	std::queue<int> pre;//所有顶点的前序排列
	std::queue<int> post;//所有顶点的后序排列
 	std::stack<int> resversePost;//所有顶点的逆后续排列
public:
	DepthFirstOrder(Diagraph G);
	~DepthFirstOrder();
	void dfs(Diagraph G,int v);
	std::queue<int> pres();
	std::queue<int> posts();
	std::stack<int> resversePosts();
};
#endif