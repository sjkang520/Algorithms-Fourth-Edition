#ifndef __DIAGRAPH_H__
#define __DIAGRAPH_H__
#include <iostream>
//#include "Bag.h"
#include <fstream>
#include <string>
#include <vector>
class Diagraph
{
private:
	int m_V;//图顶点数
	int m_E;//图边数
	std::vector<std::vector<int> > adjs;//邻接表
public:
	Diagraph(int V=0);
	Diagraph(std::string s);
	~Diagraph();
	void init_Graph(int V);
	int V() const;//返回图的顶点数
	int E() const;//返回图的边数
	void addEdge(int v,int w);//添加一条边
	std::vector<int>& adj(int v);//返回和v相邻的所有顶点
	void show_graph();
};
Diagraph reverse(Diagraph G);//返回图G的反向图
#endif