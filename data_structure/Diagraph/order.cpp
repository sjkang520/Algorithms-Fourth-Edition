//图的拓补排序测试程序
#include "Topological.h"
#include "SymbolGraph.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
	SymbolGraph symbol_graph(argv[1],'/');
	Topological Top(symbol_graph.G());
	stack<int> order=Top.orders();
	while(!order.empty())
	{
		cout<<symbol_graph.name(order.top())<<endl;
		order.pop();
	}
	//cout<<endl;
}