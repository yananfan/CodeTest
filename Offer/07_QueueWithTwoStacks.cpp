//#define QueueWithTwoStacks
#ifdef QueueWithTwoStacks

#include<iostream>
#include"07_CQueue.h"

using namespace std;

int main()
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	cout << endl;

	char head = queue.deleteHead();

	queue.appendTail('d');

	head = queue.deleteHead();
	head = queue.deleteHead();
	head = queue.deleteHead();
	return 0;
}
#endif // QueueWithTwoStacks