//检测有向图是否有环的测试程序
#include "DirectedDFS.h"
#include <iostream>
#include "DirectedCycle.h"
using namespace std;
int main(int argc,char *argv[])
{
	stack<int> cyc;
	Diagraph g(argv[1]);
	//DirectedDFS Dfs(g,6);
	//g.show_graph();
	DirectedCycle cycle(g);
	cyc=cycle.Cycle();
	//cout<<"adf"<<endl;
	//cout<<cyc.size()<<endl;
	while(!cyc.empty())
	{
		cout<<cyc.top()<<" ";
		cyc.pop();
	}
/*	for(int i=0;i<g.V();i++)
	{
		if(Dfs.connected(i))
			cout<<i<<" ";
	}*/
	cout<<endl;
	//g.show_graph();
}