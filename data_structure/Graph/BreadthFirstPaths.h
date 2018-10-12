#ifndef __BREADTHFIRSTPATHS_H__
#define __BREADTHFIRSTPATHS_H__
#include "Graph2.h"
//广度优先搜索 搜索最短路径
#include <vector>
#include <stack>
class BreadthFirstPaths
{
private:
	std::vector<bool> marked;//标记该顶点是否被搜索过
	std::vector<int> edgeTo;//到大该顶点已知路径上的最后一个顶点
	int m_s;//搜索起点
public:
	BreadthFirstPaths(Graph &G,int s);
	~BreadthFirstPaths();
	bool hasPathTo(int v);
	void bfs(Graph G,int v);
	std::stack<int> pathTo(int v);//返回s到v的最短路径
	void show_edge();
};
#endif