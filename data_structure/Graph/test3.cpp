//深度优先搜索找出连通分量测试程序
#include "CC.h"
#include "Graph2.h"
#include <iostream>
using namespace std;
int main(int argc,char *argv[])
{
	Graph graphs(argv[1]);
	CC cc(graphs);
	vector<vector<int> > components(cc.count());
	for(int i=0;i<graphs.V();i++)
		components[cc.id(i)].push_back(i);
	for(int v=0;v<cc.count();v++)
	{
		for(auto it : components[v])
			cout<<it<<" ";
		cout<<endl;
	}
}