//#define _Power_
#ifdef _Power_

#include<iostream>

using namespace std;

// 第一种写法
int flag = 0; // 指数是否为负
double Power(double base, int exp);
double PowerWithUnsignedExp(double base, int exp);
double PowerGood(double base, int exp);
// 剑指offer上的写法
bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power0(double base, int exponent);
//double PowerWithUnsignedExponent(double base, unsigned int exponent);
double PowerWithUnsignedExponent(double base, unsigned int exponent);
bool equal(double num1, double num2);

int main()
{
	cout << Power(1.0, 10) << " " << flag << endl;
	cout << Power(0.0, -5) << " " << flag << endl;
	cout << Power(2.0, 0) << " " << flag << endl;
	cout << Power(1.2, 5) << " " << flag << endl;
	cout << Power(2.0, -1) << " " << flag << endl;
	cout << endl;

	cout << PowerGood(1.0, 10) << " " << flag << endl;
	cout << PowerGood(0.0, -5) << " " << flag << endl;
	cout << PowerGood(2.0, 0) << " " << flag << endl;
	cout << PowerGood(1.2, 5) << " " << flag << endl;
	cout << PowerGood(2.0, -1) << " " << flag << endl;
	cout << endl;

	cout << Power0(1.0, 10) << " " << g_InvalidInput << endl;
	cout << Power0(0.0, -5) << " " << g_InvalidInput << endl;
	cout << Power0(2.0, 0) << " " << g_InvalidInput << endl;
	cout << Power0(1.2, 5) << " " << g_InvalidInput << endl;
	cout << Power0(2.0, -1) << " " << g_InvalidInput << endl;
	cout << endl;

	int n, exp; // n 是可测试的数据数
	double base, result1, result2;
	while ((cin >> n) && n >= 0) {
		while (n--) {
			flag = 0;
			cin >> base >> exp;
			result1 = Power(base, exp);
			result2 = PowerGood(base, exp);
			if (!result1 && flag)
				cout << "INF" << endl;
			if (!result2 && flag)
				cout << "INF" << endl;
			else
				cout << result1 << " " << result2 << endl;
		}
	}
	return 0;
}
double Power(double base, int exp) {
	flag = 0;
	double result = base;
	if (exp < 0) {
		exp = -exp;
		flag = 1;
	}
	if (exp == 0)
		return 1;
	while (--exp)
		base *= result;
	if (flag)
	{
		if ((base - 0.0 > -0.0000001) && (base - 0.0 < 0.0000001))
			return 0;
		else
			return 1.0 / base;
	}
	else
		return base;
}
double PowerWithUnsignedExp(double base, int exp) {
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;
	double result = PowerWithUnsignedExp(base, exp >> 1);
	result *= result;
	if ((exp & 0x1) == 1)
		result *= base;
	return result;
}
double PowerGood(double base, int exp) {
	flag = 0;
	if (exp < 0) {
		exp = -exp;
		flag = 1;
	}

	double result = PowerWithUnsignedExp(base, exp);

	if (flag)
	{
		if ((base - 0.0 > -0.0000001) && (base - 0.0 < 0.0000001))
			return 0;
		else
			return 1.0 / result;
	}
	else
		return result;
}

// 剑指offer上的写法
bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power0(double base, int exponent)
{
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}


//double PowerWithUnsignedExponent(double base, unsigned int exponent)
//{
//	double result = 1.0;
//
//	for (int i = 1; i <= exponent; ++i)
//		result *= base;
//
//	return result;
//}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if ((exponent & 0x1) == 1)
		result *= base;

	return result;
}

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001)
		&& (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

#endif // _Power_