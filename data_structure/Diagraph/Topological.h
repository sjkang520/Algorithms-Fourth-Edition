#ifndef __TOPOLOGICAL_H__
#define __TOPOLOGICAL_H__
#include "DepthFirstOrder.h"
#include "DirectedCycle.h"
//有向无环图的拓扑排序
class Topological
{
private:
	std::stack<int> order;
public:
	Topological(Diagraph G);
	~Topological();
	bool isDAG();//G是否是有向无环图
	std::stack<int> orders();//拓补排序的所有顶点
};
#endif