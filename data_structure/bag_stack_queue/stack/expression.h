#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
#include "Stack.h"
//输入中缀表达式
 vector<char> input();
 //判断是否是数字
 bool isNumber(char c);
//中缀表达式转换成后缀表达式
 vector<char> expchange(vector<char> infixExp,Stack<char> my_stack);
 //判断其与栈顶元素优先级
 bool priority(char top,char c);
 //后缀表达式求值
 double compute(vector<char> postfixExp);
#endif