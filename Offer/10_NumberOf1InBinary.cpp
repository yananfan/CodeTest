//#define _NumberOf1InBinary_
#ifdef _NumberOf1InBinary_

#include<iostream>
using namespace std;

// 可能引起负数死循环
int NumberOf1Right(int n);
int NumberOf1Left(int n);
int NumberOf1InBinary(int n);

int main()
{
	int n1 = 1, n2 = 9, n3 = 0x7FFFFFFF;
	cout << n1 << ":" << NumberOf1Right(n1) << " " << NumberOf1Left(n1) << " " << NumberOf1InBinary(n1) << endl;
	cout << n2 << ":" << NumberOf1Right(n2) << " " << NumberOf1Left(n2) << " " << NumberOf1InBinary(n2) << endl;
	cout << n3 << ":" << NumberOf1Right(n3) << " " << NumberOf1Left(n3) << " " << NumberOf1InBinary(n3) << endl;

	int n4 = 0xFFFFFFFF, n5 = 0x80000000;
	cout << n4 << ":" << NumberOf1Left(n4) << " " << NumberOf1InBinary(n4) << endl;
	cout << n5 << ":" << NumberOf1Left(n5) << " " << NumberOf1InBinary(n5) << endl;
}
int NumberOf1Right(int n) {
	int count = 0;
	while (n)
	{
		if (n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}

int NumberOf1Left(int n) {
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1InBinary(int n) {
	int count = 0;
	while (n)
	{
		++count;
		n = n&(n - 1);
	}
	return count;
}

#endif // _NumberOf1InBinary_