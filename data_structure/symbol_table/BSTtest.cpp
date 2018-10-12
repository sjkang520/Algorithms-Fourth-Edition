#include <iostream>
#include "BST.h"
using namespace std;
int main(int argc,char *argv[])
{
	int m;
	int k;
	char keymin,keymax;
	char key;
	BST<char,int> tree;
	tree.put('S',0); 
	tree.put('E',1); 
	tree.put('A',2); 
	tree.put('R',3); 
	tree.put('C',4); 
	tree.put('H',5); 
	tree.put('E',6);
	tree.put('X',7);  
	tree.put('A',8); 
	tree.put('M',9); 
	tree.put('P',10);
	tree.put('L',11); 
	tree.put('E',12); 
	
	//tree.deleteMax();
	//tree.deleteMin();
	//tree.Delete('L');
	//tree.Delete('P');
	//tree.Delete('A');
	//tree.Delete('M');
	//tree.Delete('X');
	keymin=tree.min();
	keymax=tree.max();
	m=tree.size();
	cout<<m<<endl<<keymin<<" "<<keymax<<endl;
	tree.print(); 
}

