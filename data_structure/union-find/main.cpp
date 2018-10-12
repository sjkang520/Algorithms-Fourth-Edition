#include <iostream>
#include <fstream>
#include "UF.h"


int main(int argc,char *argv[])
{
	ifstream in;
	ofstream out("./output.txt");
	int N;
	int p,q;
	in.open(argv[1]);
	if(in.is_open())
	{
		in>>N;
		UF uf(N);
		while(in>>p>>q)
		{
			//out<<p<<" "<<q<<endl;
			if(uf.connected(p,q))
				continue;
			uf.connect2(p,q);
		//	for(int i=0;i<N;i++)
		//		out<<uf.id[i]<<" ";
		//	out<<endl;
		}
	}
	else
		cout<<"can't open the file.\n";
	in.close();
	out.close();
	return 0;
}