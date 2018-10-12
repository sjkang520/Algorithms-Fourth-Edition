
#ifndef __DIRECTEDCYCLE_H__
#define __DIRECTEDCYCLE_H__
#include <vector>
#include "Diagraph.h"
#include <stack>
//判断一幅有向图是否为有向无环图
class DirectedCycle
{
private:
	std::vector<bool> marked;//该顶点是否被搜索过
	std::vector<bool> onStack;//递归调用栈上的所有顶点（当前搜索的路径）
	std::vector<int> edgeTo;//
	std::stack<int> cycle;//有向环中所有顶点（若存在）
public:
	DirectedCycle(Diagraph G);
	~DirectedCycle();
	void dfs(Diagraph G,int v);
	bool hasCycle();
	std::stack<int> Cycle();
};
#endif