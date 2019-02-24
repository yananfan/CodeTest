//#define _21_MinInStack_2_
#ifdef _21_MinInStack_2_

#include<iostream>
#include<stack>

using namespace std;

stack<int> s;
void push(int elem);
int pop();
int min();
int main()
{
	push(3);min();//push(3) : [3 3]
	push(4);min();//push(4) : [3 1 3]
	push(2);min();//push(2) : [3 1 - 1 2]
	push(5);min();//push(5) : [3 1 - 1 3 2]
	push(1);min();//push(1) : [3 1 - 1 3 - 1 1]
	push(1);min();//push(1) : [3 1 - 1 3 - 1 0 1]
	push(6);min();//push(6) : [3 1 - 1 3 - 1 0 5 1]
	push(7);min();//push(7) : [3 1 - 1 3 - 1 0 5 6 1]
	cout << endl;
	pop();min();
	pop();min();
	pop();min();
	pop();min();
	pop();min();
	pop();min();
	pop();min();

	return 0;
}
void push(int elem)
{
	cout << " 压入： " << elem;
	if (s.empty()) {
		s.push(elem);
		s.push(elem);
	}
	else {
		int min = s.top();
		s.pop();
		s.push(elem - min);
		s.push(elem < min ? elem : min);
	}
}

int pop()
{
	int min = s.top();
	s.pop();
	int diff = s.top();
	s.pop();
	if (diff < 0) {
		s.push(min - diff);
		cout << " 弹出： " << min;
		return min;
	}
	else {
		if (!s.empty()) {
			s.push(min);
			cout << " 弹出： " << diff + min;
			return diff + min;
		}
		cout << " 弹出： " << min;
		return min;
	}
}

int min()
{
	int min = s.top();
	cout << " min= " << min << endl;
	return min;
}
#endif // _21_MinInStack_2_