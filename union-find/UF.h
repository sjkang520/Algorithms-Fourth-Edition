#ifndef __UF_H__
#define __UF_H__
#include <vector>
using namespace std;
class UF
{
private:
	int counts=0;
	vector<int> sz;
public:
	UF()=default;
	UF(int N);
	~UF();
	vector<int> id;
	void connect(int p,int q);//在p和q之间添加一条连接(quick-find)
	void connect2(int p,int q);//在p和q之间添加一条连接(quick-union)
	int find(int p) const;//返回p所在连通分量标识符(quick-find)
	int find2(int p) const;//返回p所在连通分量标识符(quick-union)
	bool connected(int p,int q) const; //判断触点q,p是否处于同一个分量
	int count() const;//返回连通分量数
};

#endif
