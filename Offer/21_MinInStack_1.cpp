//#define _21_MinInStack_1_
#ifdef _21_MinInStack_1_

#include<iostream>
#include"21_MinInStack.h"

using namespace std;

int main()
{
	MinInStack<int> stack;

	stack.push(3);
	cout << "数据栈顶： " << stack.top();
	cout << "  最小元素： " << stack.min() << endl;

	stack.push(4);
	cout << "数据栈顶： " << stack.top();
	cout << "  最小元素： " << stack.min() << endl;

	stack.push(2);
	cout << "数据栈顶： " << stack.top();
	cout << "  最小元素： " << stack.min() << endl;

	stack.push(3);
	cout << "数据栈顶： " << stack.top();
	cout << "  最小元素： " << stack.min() << endl;

	stack.pop();
	cout << "数据栈顶： " << stack.top();
	cout << "  最小元素： " << stack.min() << endl;

	stack.pop();
	cout << "数据栈顶： " << stack.top();
	cout << "  最小元素： " << stack.min() << endl;

	stack.pop();
	cout << "数据栈顶： " << stack.top();
	cout << "  最小元素： " << stack.min() << endl;

	stack.push(0);
	cout << "数据栈顶： " << stack.top();
	cout << "  最小元素： " << stack.min() << endl;

	return 0;
}
#endif // _21_MinInStack_1_