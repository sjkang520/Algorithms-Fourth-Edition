#ifndef __SYMBOLGRAPH_H__
#define __SYMBOLGRAPH_H__
#include <vector>
#include <string>
#include "Diagraph.h"
#include <map>
class SymbolGraph
{
private:
	std::map<std::string, int> map;//符号名-顶点
	std::vector<std::string> id;//符号名对应的顶点
	int counts;
	Diagraph graph;
public:
	SymbolGraph(std::string filename,char delim);//根据输入filename文件构建符号图，文件中顶点与顶点之间分隔符是delim
	~SymbolGraph();
	bool contain(std::string key);//顶点Key是否存在
	int index(std::string key);//顶点Key的索引
	std::string name(int v);//索引v对应的顶点
	int count() const;//返回顶点个数
	Diagraph& G();//返回图
	void show();
};
#endif