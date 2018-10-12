#include "graph.h"
using namespace std;
Graph::Graph(int V):m_V(V),m_E(0)
{
	Bag bag;
	for(int v=0;v<m_V;v++)
	{
		adjs.push_back(bag);
		//std::cout<<"bag\n";
	}
}

Graph::Graph(string s)
{
	//cout<<"graph\n";
	fstream in;
	int v,w;
	int E;
	Bag bag;
	in.open(s);
	if(in.is_open())
	{
		in>>m_V>>E;
		//cout<<m_V<<" "<<m_E<<endl;
		for(int v=0;v<m_V;v++)
			adjs.push_back(bag);
		for(int i=0;i<E;i++)
		{
			in>>v>>w;
			addEdge(v,w);
		}
	}
	else
		std::cout<<"open error\n";
}

Graph::~Graph()
{
	//std::cout<<"graph destruct\n";
}

int Graph::V() const
{
	return m_V;
}

int Graph::E() const
{
	return m_E;
}

void Graph::addEdge(int v,int w)
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
	adjs[v].add(w);
	adjs[w].add(v);
	m_E++;
}

Bag& Graph::adj(int v)
{
	return adjs[v];
}

void Graph::show_graph()
{
	for(int i=0;i<m_V;i++)
	{
		adjs[i].show();
		std::cout<<endl;
	}
}