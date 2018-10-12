#include <iostream>
#include <fstream>
#include <vector>
#include "sort.h"
//百名单过滤
int main(int argc,char *argv[])
{
	fstream in;
	vector<int> a;
	int temp;
	
	in.open(argv[1]);
	if(in.is_open())
	{
		while(in>>temp)
			a.push_back(temp);
	}
	else
		cout<<"fail open the whilelist\n";
	sort<int> sorts(a); 
	sorts.Sort5(a);
//	sorts.show(a);
	in.close();

	in.open(argv[2]);
	if(in.is_open())
	{
		while(in>>temp)
		{
			if(sorts.search(a,temp,0,a.size()-1)<0)
				cout<<temp<<" ";
		}
	}
	else
		cout<<"fail open the transaction\n";
	in.close();
}	