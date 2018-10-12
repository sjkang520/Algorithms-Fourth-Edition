#include "BreadthFirstPaths.h"
#include <queue>
using namespace std;
BreadthFirstPaths::BreadthFirstPaths(Graph &G,int s):m_s(s)
{
	for(int i=0;i<G.V();i++)
	{
		marked.push_back(false);
		edgeTo.push_back(-1);
	}
	bfs(G,m_s);
	edgeTo[s]=s;
}

BreadthFirstPaths::~BreadthFirstPaths()
{

}

bool BreadthFirstPaths::hasPathTo(int v)
{
	return marked[v];
}

void BreadthFirstPaths::bfs(Graph G,int v)
{
	marked[v]=true;
	queue<int> Queues;
	Queues.push(v);
	while(!Queues.empty())
	{
		int front=Queues.front();
		Queues.pop();
		for(auto it=G.adj(front).rbegin();it!=G.adj(front).rend();it++)
		{
			if(!marked[*it])
			{
				marked[*it]=true;
				Queues.push(*it);
				edgeTo[*it]=front;
			}
		}
		
	}
}

stack<int> BreadthFirstPaths::pathTo(int v)
{
	stack<int> paths;
	if(!hasPathTo(v))
		return paths;
	for(int i=v;i!=m_s;i=edgeTo[i])
		paths.push(i);
	paths.push(m_s);
	return paths;
}

void BreadthFirstPaths::show_edge()
{
	for(auto it : edgeTo)
		cout<<it<<" ";
	cout<<endl;
}