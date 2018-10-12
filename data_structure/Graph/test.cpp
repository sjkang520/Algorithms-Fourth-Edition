#include "Graph2.h"
#include "DepthFirstPaths.h"
#include <iostream>
using namespace std;
int main(int argc,char *argv[])
{
	stack<int> paths;
	Graph graph1(argv[1]);
	DepthFirstPaths search(graph1,0);
	search.show_edge();
	paths=search.pathTo(5);
	while(!paths.empty())
	{
		cout<<paths.top()<<" ";
		paths.pop();
	}
	cout<<endl;
//	graph1.show_graph();
}