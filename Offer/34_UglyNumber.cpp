//#define _UglyNumber_
#ifdef _UglyNumber_

#include<iostream>
using namespace std;
// 逐个判断
bool IsUgly(int number);
int GetUglyNumber_1(int index);
// 自己按序创建丑数数组
int Min(int number1, int number2, int number3);
int GetUglyNumber_2(int index);

int main()
{
	int n;
	while (cin >> n)
		cout << GetUglyNumber_1(n) << " " << GetUglyNumber_2(n) << endl;
	return 0;
}
bool IsUgly(int number) {
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return (number == 1) ? true : false;
}
int GetUglyNumber_1(int index) {
	if (index <= 0)
		return 0;
	int count = 0;
	int uglycount = 0;
	while (uglycount < index) {
		++count;
		if (IsUgly(count))
			++uglycount;
	}
	return count;
}
int Min(int number1, int number2, int number3) {
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	return min;
}
int GetUglyNumber_2(int index) {
	if (index <= 0)
		return 0;
	int* ugly = new int[index];
	ugly[0] = 1;
	int nextugly = 1;
	int* T2 = ugly, *T5 = ugly, *T3 = ugly;
	while (nextugly < index) {
		int min = Min(*T2 * 2, *T3 * 3, *T5 * 5);
		ugly[nextugly] = min;
		while (*T2 * 2 <= ugly[nextugly])
			++T2;
		while (*T3 * 3 <= ugly[nextugly])
			++T3;
		while (*T5 * 5 <= ugly[nextugly])
			++T5;
		++nextugly;
	}
	int result = ugly[nextugly - 1];
	delete[] ugly;
	return result;
}

#endif // _UglyNumber_