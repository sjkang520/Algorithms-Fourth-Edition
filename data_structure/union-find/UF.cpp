
#include "UF.h"

UF::UF(int N):counts(N)
{
	for(int i=0;i<N;i++)
	{
		id.push_back(i);
		sz.push_back(1);
	}
}
UF::~UF()
{

}
void UF::connect(int p,int q)
{
	int pID=find(p);
	int qID=find(q);
	if(pID!=qID)
	{
		for(int i=0;i<id.size();i++)
		{
			if(id[i]==pID)
				id[i]=qID;
		}
	}
	counts--;
}
void UF::connect2(int p,int q)
{
	int pRoot=find2(p);
	int qRoot=find2(q);
	if(pRoot!=qRoot)
	{
		if(sz[p]<sz[q])
		{
			id[pRoot]=qRoot;
			sz[qRoot]+=sz[pRoot];
		}
		else
		{
			id[qRoot]=pRoot;
			sz[pRoot]+=sz[qRoot];
		}

	}
	counts--;
}
int UF::find(int p) const
{
	return id[p];
}

int UF::find2(int p) const
{
	while(p!=id[p])
		p=id[p];
	return p;
}
bool UF::connected(int p,int q) const
{
	return find2(p)==find2(q);
}
int UF::count() const
{
	return counts;
}