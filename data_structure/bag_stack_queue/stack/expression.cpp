#include "expression.h"


vector<char> input()
{
	string str_exp;
	vector<char> infixExp;
	getline(cin,str_exp);
	for(int i=0;i<str_exp.length();i++)
		infixExp.push_back(str_exp[i]);
	return infixExp;
}
 bool isNumber(char c)
 {
 	if((c=='+')||(c=='-')||(c=='*')||(c =='/')||(c=='(')||(c==')'))
 		return false;
 	else
 		return true;
 }
 bool priority(char top,char c)
 {
 	if ((top=='+')&&(c=='+')) return true;
 	else if((top=='+')&&(c=='-')) return true;
 	else if((top=='-')&&(c=='+')) return true;
 	else if((top=='-')&&(c=='-')) return true;
 	else if((top=='*')&&(c=='+')) return true;
 	else if((top=='*')&&(c=='-')) return true;
 	else if((top=='*')&&(c=='*')) return true;
 	else if((top=='*')&&(c=='/')) return true;
 	else if((top=='/')&&(c=='+')) return true;
 	else if((top=='/')&&(c=='-')) return true;
 	else if((top=='/')&&(c=='*')) return true;
 	else if((top=='/')&&(c=='/')) return true;
 	else if((c==')')) return true;
 	else 
 		return false;
 }
 vector<char> expchange(vector<char> infixExp,Stack<char> my_stack)
 {
 	vector<char> postfixExp;
 	char item;
 	for(auto it : infixExp)
 	{
 		//cout<<isNumber(it)<<endl;
 		if(isNumber(it))
 			postfixExp.push_back(it);
 		else
 		{
 			if(my_stack.isEmpty())
 				my_stack.push(it);
 			else
 			{
 				if(priority(my_stack.get_topitem(),it))
 				{
 					if(it==')')
 					{
 						while(my_stack.get_topitem()!='(')
 						{
 							item=my_stack.pop();
 							postfixExp.push_back(item);
 						}
 						my_stack.pop();//弹出'('
 					}
 					else
 					{
 						while(priority(my_stack.get_topitem(),it))
 						{
 							item=my_stack.pop();
 							postfixExp.push_back(item);
 							if(my_stack.isEmpty())
 								break;
 						}
 						my_stack.push(it);
 					}
 				}
 				else
 					my_stack.push(it);
 			}
 		}
 	}
 	while(!my_stack.isEmpty())
 	{
 		item=my_stack.pop();
 		postfixExp.push_back(item);
 	}
 	return postfixExp;
 }
 
 double compute(vector<char> postfixExp)
 {
 	Stack<double> result;
 	double a,b;
 	for(auto it : postfixExp)
 	{
 		if(isNumber(it))
 		{
 			result.push(double(it-'0'));
 		}
 		else
 		{
 			a=result.pop();
 			b=result.pop();
 			if(it=='+')
 				result.push(a+b);
 			else if(it=='-')
 				result.push(b-a);
 			else if(it=='*')
 				result.push(a*b);
 			else 
 				result.push(b/a);
 		}
 	}
 	return result.pop();
 }