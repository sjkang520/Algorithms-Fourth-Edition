#include "DepthFirstPaths.h"
using namespace std;
DepthFirstPaths::DepthFirstPaths(Graph &G,int s):m_s(s)
{
	for(int i=0;i<G.V();i++)
	{
		marked.push_back(false);
		edgeTo.push_back(-1);
	}
	dfs(G,m_s);
	edgeTo[s]=s;
}	

DepthFirstPaths::~DepthFirstPaths()
{

}

void DepthFirstPaths::dfs(Graph G,int v)
{
	//vector<int> adj_item;
	marked[v]=true;
	//adj_item=G.adj(v);
	//for(auto it=adj_item.rbegin();it!=adj_item.rend();it++)
	for(auto it=G.adj(v).rbegin();it!=G.adj(v).rend();it++)
	//for(int w=adj_item.size()-1;w>0;w--)
	{
		if(!marked[*it])
		{
			edgeTo[*it]=v;
			dfs(G,*it);
		}
	}
}

bool DepthFirstPaths::hasPathTo(int v)
{
	return marked[v];
}

stack<int> DepthFirstPaths::pathTo(int v)
{
	stack<int> path;
	if(!hasPathTo(v))
		return path;
	for(int w=v;w!=m_s;w=edgeTo[w])
		path.push(w);
	path.push(m_s);
	return path;	
}

void DepthFirstPaths::show_edge()
{
	for(auto it : edgeTo)
		cout<<it<<" ";
	cout<<endl;
}