#include "CC.h"

CC::CC(Graph G):counts(0)
{
	for(int i=0;i<G.V();i++)
	{
		marked.push_back(false);
		ids.push_back(-1);
	}
	for(int v=0;v<G.V();v++)
	{
		if(!marked[v])
		{
			dfs(G,v);
			counts++;
		}
	}
}

CC::~CC()
{

}

void CC::dfs(Graph G,int s)
{
	marked[s]=true;
	ids[s]=counts;
	for(auto it=G.adj(s).rbegin();it!=G.adj(s).rend();it++)
	{
		if(!marked[*it])
		{
			dfs(G,*it);
		}
	}
}

bool CC::connected(int v,int w)
{
	return ids[v]==ids[w];
}

int CC::count()
{
	return counts;
}

int CC::id(int v)
{
	return ids[v];
}