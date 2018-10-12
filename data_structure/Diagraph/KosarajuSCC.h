#ifndef __KOSARAJUSCC_H__
#define __KOSARAJUSCC_H__
#include <vector>
#include "Diagraph.h"
#include "DepthFirstOrder.h"
//计算有向图中的强连通分量
class KosarajuSCC
{
private:
	std::vector<bool> marked;
	std::vector<int> ids;
	int counts;
public:
	KosarajuSCC(Diagraph G);
	~KosarajuSCC();
	void dfs(Diagraph G,int s);
	bool strongConnected(int v,int w);
	int count();
	int id(int v);
};
#endif