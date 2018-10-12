//利用深度优先搜索找出图的所有连通分量
#ifndef __CC_H__
#define __CC_H__
#include <vector>
#include "Graph2.h"
class CC
{
private:
	std::vector<bool> marked;//该顶点是否被搜索过
	std::vector<int> ids;//该顶点所在的连通分量
	int counts;//连通分量的数量
public:
	CC(Graph G);
	~CC();
	void dfs(Graph G,int s);
	bool connected(int v,int w);
	int count();
	int id(int v);
};
#endif