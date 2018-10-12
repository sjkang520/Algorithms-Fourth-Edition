#include "DirectedDFS.h"
DirectedDFS::DirectedDFS(Diagraph G,int s)
{
	for(int i=0;i<G.V();i++)
		marked.push_back(false);
	dfs(G,s);
}

DirectedDFS::~DirectedDFS()
{

}

void DirectedDFS::dfs(Diagraph G,int v)
{
	marked[v]=true;
	for(auto it : G.adj(v))
	{
		if(!marked[it])
			dfs(G,it);
	}
}

bool DirectedDFS::connected(int v)
{
	return marked[v];
}