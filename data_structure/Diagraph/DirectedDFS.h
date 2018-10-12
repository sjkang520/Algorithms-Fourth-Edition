#ifndef __DIRECTEDDFS_H__
#define __DIRECTEDDFS_H__
#include <vector>
#include <iostream>
#include "Diagraph.h"
//有向图的可达性
class DirectedDFS
{
private:
	std::vector<bool> marked;
public:
	DirectedDFS(Diagraph G,int s);
	void dfs(Diagraph G,int v);
	bool connected(int v);
	~DirectedDFS();
};
#endif