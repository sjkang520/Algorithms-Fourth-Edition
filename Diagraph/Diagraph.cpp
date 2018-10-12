#include "Diagraph.h"
using namespace std;
Diagraph::Diagraph(int V):m_V(V),m_E(0)
{
	vector<int> temp;
	for(int i=0;i<m_V;i++)
		adjs.push_back(temp);
}

Diagraph::Diagraph(string s)
{
	//cout<<"graph\n";
	fstream in;
	int v,w;
	int E;
	vector<int> temp;
	in.open(s);
	if(in.is_open())
	{
		in>>m_V>>E;
		//cout<<m_V<<" "<<m_E<<endl;
		for(int v=0;v<m_V;v++)
			adjs.push_back(temp);
		for(int i=0;i<E;i++)
		{
			in>>v>>w;
			addEdge(v,w);
		}
	}
	else
		std::cout<<"open error\n";
}

Diagraph::~Diagraph()
{
	//std::cout<<"graph destruct\n";
}

void Diagraph::init_Graph(int V)
{
	m_V=V;
	vector<int> temp;
	for(int i=0;i<m_V;i++)
		adjs.push_back(temp);
}

int Diagraph::V() const
{
	return m_V;
}

int Diagraph::E() const
{
	return m_E;
}

void Diagraph::addEdge(int v,int w)
{
	if(v<0||v>=m_V)
	{
		cout<<"v is not between 0 and m_V\n";
		return;
	}
	if(w<0||w>=m_V)
	{
		cout<<"w is not between 0 and m_V\n";
		return;
	}
//	cout<<"add"<<endl;
	adjs[v].push_back(w);
	m_E++;
}

vector<int>& Diagraph::adj(int v)
{
	return adjs[v];
}

void Diagraph::show_graph()
{
	for(int i=0;i<m_V;i++)
	{
		for(auto it : adjs[i])
			cout<<it<<" ";
		cout<<endl;
	}
}


Diagraph reverse(Diagraph G)
{
	Diagraph resverse_graph(G.V());
	for(int v=0;v<G.V();v++)
	{
		//for(auto it=G.adj(v).begin();it!=G.adj(v).end();it++)
		for(auto it : G.adj(v))
			resverse_graph.addEdge(it,v);
	}
	return resverse_graph;
}
