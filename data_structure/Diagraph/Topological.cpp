#include "Topological.h"
using namespace std;
Topological::Topological(Diagraph G)
{
	DirectedCycle cyclerfind(G);
	if(!cyclerfind.hasCycle())
	{
		DepthFirstOrder dfs(G);
		order=dfs.resversePosts();
	}
}

Topological::~Topological()
{

}

bool Topological::isDAG()
{
	return order.size()!=0;
}

stack<int> Topological::orders()
{
	return order;
}