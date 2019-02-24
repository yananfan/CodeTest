#pragma once
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
template<class T>
class MinInStack
{
public:
	MinInStack() {}
	~MinInStack() {}

	T& top();
	const T& top() const;

	void push(const T& value);
	void pop();

	const T& min() const;

	bool empty() const;
	size_t size() const;
private:
	stack<T> m_data;
	stack<T> m_min;
};

template<class T>
T& MinInStack<T>::top() {
	return m_data.top();
}

template<class T>
const T& MinInStack<T>::top() const {
	return m_data.top();
}
template<class T>
void MinInStack<T>::push(const T& value) {
	cout << value << "ÈëÕ»" << endl;
	m_data.push(value);
	if (m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}
template<class T>
void MinInStack<T>::pop() {
	assert(m_data.size() > 0 && m_min.size() > 0);
	cout << m_data.top() << "³öÕ»" << endl;
	m_data.pop();
	m_min.pop();
}
template<class T>
const T& MinInStack<T>::min() const {
	assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();
}
template<class T>
bool MinInStack<T>::empty() const {
	return m_data.empty();
}
template<class T>
size_t MinInStack<T>::size() const {
	return m_data.size();
}