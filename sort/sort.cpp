#include "sort.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define N 1000
int main(int argc,char *argv[])
{/*
	double m;
	clock_t start,stop;
	double totaltime1,totaltime2;
	vector<char> a;
	sort<char> sorts;
	srand((unsigned int)time(NULL));
	for(int i=0;i<N;i++)
	{
		m=rand()/double(RAND_MAX);
		a.push_back(m);
	//	srand((unsigned int)time(NULL));
		//cout<<rand()/double(RAND_MAX)<<" ";
	}
	start=clock();
	sorts.Sort1(a);
	stop=clock();
	totaltime1=(double)(stop-start)/CLOCKS_PER_SEC;

	start=clock();
	sorts.Sort2(a);
	stop=clock();
	totaltime2=(double)(stop-start)/CLOCKS_PER_SEC;
//	cout<<totaltime2<<endl;
	cout<<totaltime1<<endl<<totaltime2<<endl<<totaltime1/totaltime2<<endl;
	return 0;*/
	ifstream in;
	int c;
	vector<int> a;
	
	clock_t start,stop;
	double totaltime1,totaltime2,totaltime3,totaltime4;
	in.open(argv[1]);
	if(in.is_open())
	{
	//	a.push_back(-1);//对于堆排序，v[0]位置的元素不参与排序
		while(in>>c)
			a.push_back(c);
	}
	else
		cout<<"can't open the file.\n";
	//cout<<a.size()-1;
	sort<int> sorts(a);
/*	start=clock();
	sorts.Sort2(a);
	stop=clock();
	totaltime1=(double)(stop-start)/CLOCKS_PER_SEC;*/

	/*start=clock();
	sorts.Sort3(a);
	stop=clock();
	totaltime2=(double)(stop-start)/CLOCKS_PER_SEC;

	start=clock();
	sorts.Sort4(a,0,a.size()-1);
	stop=clock();
	totaltime3=(double)(stop-start)/CLOCKS_PER_SEC;*/

	start=clock();
	sorts.Sort7(a);
	stop=clock();
	totaltime4=(double)(stop-start)/CLOCKS_PER_SEC;

	cout<<totaltime4<<endl;//<<totaltime3<<endl<<totaltime4<<endl;
//	sorts.Sort1(a);
	sorts.show(a);
}