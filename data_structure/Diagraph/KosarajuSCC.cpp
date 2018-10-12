#include "KosarajuSCC.h"
using namespace std;
KosarajuSCC::KosarajuSCC(Diagraph G):counts(0)
{
	for(int i=0;i<G.V();i++)
	{
		marked.push_back(false);
		ids.push_back(-1);
	}
	DepthFirstOrder Firstorder(reverse(G));
//	DepthFirstOrder Firstorder(G);
	stack<int> reversePost=Firstorder.resversePosts();
	vector<int> ResversePost;
	while(!reversePost.empty())
	{
		ResversePost.push_back(reversePost.top());
	//	cout<<reversePost.top()<<" ";
		reversePost.pop();
	}
	for(auto v : ResversePost)
	{
		cout<<v<<" ";
		if(!marked[v])
		{
			dfs(G,v);
			counts++;
		}
	}
	cout<<endl;
}

KosarajuSCC::~KosarajuSCC()
{

}

void KosarajuSCC::dfs(Diagraph G,int s)
{
	marked[s]=true;
	ids[s]=counts;
	for(auto it : G.adj(s))
	{
		if(!marked[it])
			dfs(G,it);
	}
}

bool KosarajuSCC::strongConnected(int v,int w)
{
	return ids[v]==ids[w];
}

int KosarajuSCC::count()
{
	return counts;
}

int KosarajuSCC::id(int v)
{
	return ids[v];
}