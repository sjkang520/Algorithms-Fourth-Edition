//广度优先搜索测试程序
#include "BreadthFirstPaths.h"
#include "Graph2.h"
#include <iostream>
using namespace std;
int main(int argc,char *argv[])
{
	stack<int> paths;
	Graph graph1(argv[1]);
	BreadthFirstPaths search(graph1,0);
	search.show_edge();
	paths=search.pathTo(4);
	while(!paths.empty())
	{
		cout<<paths.top()<<" ";
		paths.pop();
	}
	cout<<endl;
//	graph1.show_graph();
}