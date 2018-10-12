#include "DirectedCycle.h"
using namespace std;
DirectedCycle::DirectedCycle(Diagraph G)
{
	for(int v=0;v<G.V();v++)
	{
		marked.push_back(false);
		onStack.push_back(false);
		edgeTo.push_back(-1);
	}
	for(int v=0;v<G.V();v++)
	{
		if(!marked[v])
			dfs(G,v);
	}
}

DirectedCycle::~DirectedCycle()
{

}

void DirectedCycle::dfs(Diagraph G,int v)
{
	marked[v]=true;
	onStack[v]=true;
	//for(auto w : G.adj(v))
	for(auto w=G.adj(v).rbegin();w!=G.adj(v).rend();w++)
	{
		if(hasCycle())
			return;
		else if(!marked[*w])
		{
			edgeTo[*w]=v;
			dfs(G,*w);
		}
		else if(onStack[*w])
		{
			for(int x=v;x!=*w;x=edgeTo[x])
				cycle.push(x);
			cycle.push(*w);
			cycle.push(v);
		}
	}
	onStack[v]=false;
}

bool DirectedCycle::hasCycle()
{
	return !cycle.empty();
}

stack<int> DirectedCycle::Cycle()
{
	return cycle;
}
