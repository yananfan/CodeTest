//#define _NumberOf1_
#ifdef _NumberOf1_

#include<iostream>
using namespace std;
// 常规解法
int NumberOf1Between1AndN_1(int n);
int NumberOf1(int n);
// 找出数字规律
int NumberOf1Between1AndN_2(int n);
// 每次去掉最高位做递归
int NumberOf1Between1AndN_3(int n);
int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

int main()
{
	int n;
	while (cin >> n) 
		cout << NumberOf1Between1AndN_1(n) << " " << NumberOf1Between1AndN_2(n) << " " << NumberOf1Between1AndN_3(n) << endl;

	return 0;
}
int NumberOf1Between1AndN_1(int n) {
	int num = 0;
	for (int i = 1;i <= n;i++)
		num += NumberOf1(i);
	return num;
}
int NumberOf1(int n) {
	int num = 0;
	while (n)
	{
		if (n % 10 == 1)
			num++;
		n = n / 10;
	}
	return num;
}
int NumberOf1Between1AndN_2(int n) {
	if (n <= 0)
		return 0;
	int num = 0;
	int Power = 1;
	int High = 0, Cur = 0, Low = 0;
	while (n / Power) {
		Low = n - (n / Power)*Power;
		Cur = (n / Power) % 10;
		High = n / (Power * 10);
		if (Cur == 0)
			num += High*Power;
		else if (Cur == 1)
			num += High*Power + Low + 1;
		else
			num += (High + 1)*Power;
		Power *= 10;
	}
	return num;
}
int NumberOf1Between1AndN_3(int n) {
	if (n <= 0)
		return 0;
	char strN[50];
	sprintf_s(strN, "%d", n);

	return NumberOf1(strN);
}
int NumberOf1(const char* strN) {
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
		return 0;

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if (length == 1 && first == 0)
		return 0;

	if (length == 1 && first > 0)
		return 1;

	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;

	int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
	int numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;

}
int PowerBase10(unsigned int n) {
	int result = 1;
	for (unsigned int i = 0; i < n; ++i)
		result *= 10;

	return result;
}
#endif // _NumberOf1_