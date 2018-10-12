#include "SequentialSearch.h"
#include <fstream>
#include <string>
//#include <iostream>
using namespace std;
int main(int argc,char *argv[])
{
	fstream in;
	string word;
	SequentialSearch<string,int> st;
	in.open(argv[1]);
	if(in.is_open())
	{
		while(in>>word)
		{
			if(word.length()<2)
				continue;
			if(!st.contains(word))
				st.put(word,1);
			else
				st.put(word,st.get(word)+1);
		}
	}
	else
		cout<<"can't open the file\n";
	st.Delete("it");
	st.Delete("best");
	st.show();
}