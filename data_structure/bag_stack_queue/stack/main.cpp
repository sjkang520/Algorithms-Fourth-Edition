//#include "Bag.h"
#include "expression.h"
#include <iostream>

int main(int argc,char *argv[])
{
	using namespace std;
	vector<char> infixExp;
	vector<char> postfixExp;
	Stack<char> my_stack;
	double res;

	infixExp=input();
	postfixExp=expchange(infixExp,my_stack);
	res=compute(postfixExp);
	cout<<res<<endl;
/*	double temp;
	double sum;
	Bag Bag_list;
	while(cin>>temp)
	{
		if(temp==-1)
			break;
		Bag_list.add(temp);
	}
	sum=Bag_list.average();
	cout<<"items="<<Bag_list.size()<<endl;
	cout<<"sum="<<sum<<endl;*/
}