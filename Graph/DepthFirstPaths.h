#ifndef __DEPTHFIRSTPATHS_H__
#define __DEPTHFIRSTPATHS_H__
//深度优先搜索查找图中的路径
#include "Graph2.h"
#include <vector>
#include <stack>
#include <iostream>
//using namespace std;
class DepthFirstPaths
{
	std::vector<bool> marked;//顶点是否访问过
	std::vector<int> edgeTo;//从起点到一个顶点的已知路径上的最后一个顶点
	int m_s;
public:
	DepthFirstPaths(Graph &G,int s);//在图G中找出以s为起点的所有路径
	~DepthFirstPaths();
	void dfs(Graph G,int v);//深度优先搜索
	bool hasPathTo(int v);//从起点点s到顶点v是否存在路径
	std::stack<int> pathTo(int v);//返回从s到v的路径	
	void show_edge();
};

#endif