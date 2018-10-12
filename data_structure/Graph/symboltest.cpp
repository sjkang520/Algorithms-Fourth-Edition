#include "SymbolGraph.h"
#include "BreadthFirstPaths.h"
using namespace std;
//输入包含一幅图的文件名、搜索起始顶点和顶点分隔符
//例： /symboltest movies.txt "Bacon, Kevin" /
int main(int argc,char *argv[])
{
	string str;
	SymbolGraph symbolgraph(argv[1],argv[3][0]);//符号图
	Graph symbal_graph=symbolgraph.G();//返回图
	if(!symbolgraph.contain(argv[2]))//判断搜索的起始顶点是否在符号图中
	{
		cout<<argv[2]<<" is not in the graph\n";
		return 0;
	}
	int s=symbolgraph.index(argv[2]);//广度优先搜索搜索的起始顶点
	BreadthFirstPaths breadpaths(symbal_graph,s);//广度优先搜索
	getline(cin,str);//输入顶点str
	if(!symbolgraph.contain(str))//判断符号图中是否存在该顶点
	{
		cout<<str<<" is not in the graph\n";
		return 0;
	}
	stack<int> path=breadpaths.pathTo(symbolgraph.index(str));//返回搜索起点s到顶点str的最短路径
	if(path.empty())//如果path为空，说明s与str在图中没有连通
	{
		cout<<"have no path to "<<str<<endl;
		return 0;
	}
	while(!path.empty())
	{
		cout<<symbolgraph.name(path.top())<<endl;
		path.pop();
	}
	//cout<<endl;
}