#pragma once
#include<stack>
#include <exception>

using namespace std;

template<class T>
class CQueue
{
public:
	CQueue(void) {};
	~CQueue(void) {};
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};
template<class T>
void CQueue<T>::appendTail(const T& node) // �ڶ�β���Ԫ�ز������ʾ
{
	stack1.push(node);
	cout << stack1.top() << " ";
}
template<class T>
T CQueue<T>::deleteHead() // �ڶ�ͷɾ��Ԫ��
{
	if (stack2.size() <= 0) {
		while (stack1.size() > 0) {
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0)
		throw new exception("queue is empty");
	T head = stack2.top();
	stack2.pop();
	return head;
}