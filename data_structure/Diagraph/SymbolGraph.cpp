#include "SymbolGraph.h"
#include <fstream>
#include <sstream>
using namespace std;
SymbolGraph::SymbolGraph(string filename,char delim):counts(0)
{
	fstream infile;
	int flag=0;
	string first_vertex;
	string line;//行
	string vertex;//顶点
	stringstream strm;
	infile.open(filename);
	if(infile.is_open())
	{
		//第一次输入，初始化map和数组id，将符号名和对应的顶点
		while(getline(infile,line))
		{
			
			strm.clear();
			strm.str("");
			strm.str(line);
			while(getline(strm,vertex,delim))
			{
				if(map.find(vertex)==map.end())
				{
					map.insert(make_pair(vertex,counts));
					id.push_back(vertex);
					counts++;
				}
			}
		}
	}
	else
		cout<<"open error\n";
	infile.close();
	graph.init_Graph(counts);
	infile.open(filename);
	if(infile.is_open())
	{
		while(getline(infile,line))
		{
			strm.clear();
			strm.str("");
			strm.str(line);
			while(getline(strm,vertex,delim))
			{
				flag++;
				if(flag==1)
					first_vertex=vertex;
				else
				{
					//cout<<first_vertex<<" "<<vertex<<" ";
				//	cout<<map.at(first_vertex)<<" "<<map.at(vertex)<<endl;
					graph.addEdge(map.at(first_vertex),map.at(vertex));
				}
			}
			flag=0;
		}
	}
	infile.close();
}

SymbolGraph::~SymbolGraph()
{
}

bool SymbolGraph::contain(string key)
{
	if(map.find(key)!=map.end())
		return true;
	else
		return false;
}

int SymbolGraph::index(string key)
{
	return map.at(key);
}

string SymbolGraph::name(int v)
{
	if(v<0||v>=counts)
		return " ";
	return id[v];
}

int SymbolGraph::count() const
{
	return counts;
}

Diagraph& SymbolGraph::G()
{
	return graph;
}

void SymbolGraph::show()
{
	//cout<<counts<<endl;
//	for(auto it=map.cbegin();it!=map.cend();it++)
//		cout<<it->first<<" "<<it->second<<endl;
//	for(int i=0;i<counts;i++)
//		cout<<id[i]<<" ";
//	cout<<endl;
	graph.show_graph();
}