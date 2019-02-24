//#define _21_MinInStack_1_
#ifdef _21_MinInStack_1_

#include<iostream>
#include"21_MinInStack.h"

using namespace std;

int main()
{
	MinInStack<int> stack;

	stack.push(3);
	cout << "����ջ���� " << stack.top();
	cout << "  ��СԪ�أ� " << stack.min() << endl;

	stack.push(4);
	cout << "����ջ���� " << stack.top();
	cout << "  ��СԪ�أ� " << stack.min() << endl;

	stack.push(2);
	cout << "����ջ���� " << stack.top();
	cout << "  ��СԪ�أ� " << stack.min() << endl;

	stack.push(3);
	cout << "����ջ���� " << stack.top();
	cout << "  ��СԪ�أ� " << stack.min() << endl;

	stack.pop();
	cout << "����ջ���� " << stack.top();
	cout << "  ��СԪ�أ� " << stack.min() << endl;

	stack.pop();
	cout << "����ջ���� " << stack.top();
	cout << "  ��СԪ�أ� " << stack.min() << endl;

	stack.pop();
	cout << "����ջ���� " << stack.top();
	cout << "  ��СԪ�أ� " << stack.min() << endl;

	stack.push(0);
	cout << "����ջ���� " << stack.top();
	cout << "  ��СԪ�أ� " << stack.min() << endl;

	return 0;
}
#endif // _21_MinInStack_1_