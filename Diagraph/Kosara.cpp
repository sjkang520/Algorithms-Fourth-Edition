//强连通分量测试程序
#include "KosarajuSCC.h"
using namespace std;
int main(int argc,char* argv[])
{
	Diagraph graph(argv[1]);
	KosarajuSCC kosara(graph);
	cout<<kosara.count()<<" components"<<endl;
	for(int i=0;i<graph.V();i++)
	{
		cout<<kosara.id(i)<<" ";
	}
	cout<<endl;
}