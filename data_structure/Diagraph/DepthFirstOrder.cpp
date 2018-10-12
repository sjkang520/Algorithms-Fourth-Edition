#include "DepthFirstOrder.h"
using namespace std;
DepthFirstOrder::DepthFirstOrder(Diagraph G)
{
	for(int v=0;v<G.V();v++)
		marked.push_back(false);
	for(int v=0;v<G.V();v++)
	{
		if(!marked[v])
			dfs(G,v);
	}
}

DepthFirstOrder::~DepthFirstOrder()
{

}

void DepthFirstOrder::dfs(Diagraph G,int v)
{
	marked[v]=true;
	pre.push(v);
	for(auto w=G.adj(v).rbegin();w!=G.adj(v).rend();w++)
	{
		if(!marked[*w])
			dfs(G,*w);
	}
	post.push(v);
	resversePost.push(v);
}

queue<int> DepthFirstOrder::pres()
{
	return pre;
}

queue<int> DepthFirstOrder::posts()
{
	return post;
}

stack<int> DepthFirstOrder::resversePosts()
{
	return resversePost;
}