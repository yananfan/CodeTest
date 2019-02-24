#pragma once
#include<queue>
#include<iostream>
using namespace std;
template<class T>
class QStack
{
public:
	QStack() {};
	~QStack() {};
	void appendTop(const T& node);
	T deleteTop();
private:
	queue<T> queue1;
	queue<T> queue2;
};
template<class T>
void QStack<T>::appendTop(const T& node) // 栈顶插入元素
{
	if (queue1.empty() && queue2.empty())
		queue1.push(node);
	else if (queue1.empty() && !queue2.empty())
		queue2.push(node);
	else if (!queue1.empty() && queue2.empty())
		queue1.push(node);
	else
		return;
	cout << node << " ";
}
template<class T>
T QStack<T>::deleteTop() // 栈顶删除元素
{
	T temp; // 返回值
	if (!queue1.empty() && queue2.empty()) {
		if (queue1.size() < 1) return -1;
		while (queue1.size() != 1) {
			temp = queue1.front();
			queue1.pop();
			queue2.push(temp);
		}
		temp = queue1.front();
		queue1.pop();
		return temp;
	}
	else if (queue1.empty() && !queue2.empty()) {
		if (queue2.size() < 1) return -1;
		while (queue2.size() != 1) {
			temp = queue2.front();
			queue2.pop();
			queue1.push(temp);
		}
		temp = queue2.front();
		queue2.pop();
		return temp;
	}
	else
		return -1;
}