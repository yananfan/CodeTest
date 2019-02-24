//#define _AddTwoNumbers_
#ifdef _AddTwoNumbers_

#include<iostream>
using namespace std;

int Add(int n1, int n2);
void Merge1(int& n1, int& n2);
void Merge2(int& n1, int& n2);
int main()
{
	cout << Add(1, 2) << endl; // 3
	cout << Add(101, 289) << endl; // 390
	cout << Add(1, -2) << endl; // -1
	cout << Add(-1, 2) << endl; // 1
	cout << Add(1, 0) << endl; // 1
	cout << Add(0, 2) << endl; // 2
	cout << Add(0, 0) << endl; // 0
	cout << Add(0, -2) << endl; // -2

	int n1 = 1, n2 = 2;
	Merge1(n1, n2);
	cout << n1 << " " << n2 << endl;
	Merge2(n1, n2);
	cout << n1 << " " << n2 << endl;
	return 0;
}
int Add(int n1, int n2) {
	int sum, carry;
	do
	{
		sum = n1^n2;
		carry = (n1 & n2) << 1;
		n1 = sum;
		n2 = carry;
	} while (n2 != 0);
	return sum;
}
void Merge1(int& n1, int& n2) {
	n1 = n1 + n2;
	n2 = n1 - n2;
	n1 = n1 - n2;
}
void Merge2(int& n1, int& n2) {
	n1 = n1^n2;
	n2 = n1^n2;
	n1 = n1^n2;
}
#endif // _AddTwoNumbers_