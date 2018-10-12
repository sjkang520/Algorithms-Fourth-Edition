#ifndef __GRAPH2_H__
#define __GRAPH2_H__
#include <vector>
#include <iostream>
//#include "Bag.h"
#include <fstream>
#include <string>
class Graph
{
private:
	int m_V;//图顶点数
	int m_E;//图边数
	std::vector<std::vector<int> > adjs;//邻接表
public:
	Graph(int V=0);
	Graph(std::string s);
	~Graph();
	void init_Graph(int V);
	int V() const;//返回图的顶点数
	int E() const;//返回图的边数
	void addEdge(int v,int w);//添加一条边
	std::vector<int>& adj(int v);//返回和v相邻的所有顶点
	void show_graph();
};
#endif