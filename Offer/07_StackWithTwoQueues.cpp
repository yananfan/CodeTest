//#define StackWithTwoQueues
#ifdef StackWithTwoQueues

#include<iostream>
#include"07_QStack.h"
using namespace std;
int main()
{
	QStack<char> queue;
	queue.appendTop('a');
	queue.appendTop('b');
	queue.appendTop('c');
	cout << endl;

	queue.deleteTop();
	queue.deleteTop();

	queue.appendTop('d');

	return 0;
}
#endif // StackWithTwoQueues