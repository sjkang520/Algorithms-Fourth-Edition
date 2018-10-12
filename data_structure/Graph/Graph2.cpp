#include "Graph2.h"
using namespace std;
Graph::Graph(int V):m_V(V),m_E(0)
{
	vector<int> temp;
	for(int i=0;i<m_V;i++)
		adjs.push_back(temp);
}

Graph::Graph(string s)
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

Graph::~Graph()
{
	//std::cout<<"graph destruct\n";
}

void Graph::init_Graph(int V)
{
	m_V=V;
	vector<int> temp;
	for(int i=0;i<m_V;i++)
		adjs.push_back(temp);
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
//	cout<<"add"<<endl;
	adjs[v].push_back(w);
	adjs[w].push_back(v);
	m_E++;
}

vector<int>& Graph::adj(int v)
{
	return adjs[v];
}

void Graph::show_graph()
{
	for(int i=0;i<m_V;i++)
	{
		for(auto it : adjs[i])
			cout<<it<<" ";
		cout<<endl;
	}
}