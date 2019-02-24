//#define _LastNumberInCircle_
#ifdef _LastNumberInCircle_

#include<iostream>
#include<list>
using namespace std;
// 循环链表
int LastRemaining_1(int n, int m);
// 创新的解法
int LastRemaining_2(int n, int m);
int main()
{
	cout << LastRemaining_1(5, 3) << " " << LastRemaining_2(5, 3) << endl; // 3
	cout << LastRemaining_1(5, 2) << " " << LastRemaining_2(5, 2) << endl; // 2
	cout << LastRemaining_1(6, 6) << " " << LastRemaining_2(6, 6) << endl; // 3
	cout << LastRemaining_1(6, 7) << " " << LastRemaining_2(6, 7) << endl; // 4
	cout << LastRemaining_1(0, 0) << " " << LastRemaining_2(0, 0) << endl; // -1
	cout << LastRemaining_1(4000, 997) << " " << LastRemaining_2(4000, 997) << endl; // 1027

	return 0;
}
int LastRemaining_1(int n, int m) {
	if (n < 1 || m < 1)
		return -1;
	int i = 0;
	list<int> num;
	for (i = 0;i < n;i++)
		num.push_back(i);
	list<int>::iterator cur = num.begin();
	while (num.size() > 1) {
		for (int i = 1;i < m;i++) {
			cur++;
			if (cur == num.end())
				cur = num.begin();
		}
		list<int>::iterator next = ++cur;
		if (next == num.end())
			next = num.begin();
		cur--;
		num.erase(cur);
		cur = next;
	}
	return *cur;
}
int LastRemaining_2(int n, int m) {
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2;i <= n;i++)
		last = (last + m) % i;
	return last;
}
#endif // _LastNumberInCircle_