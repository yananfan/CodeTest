//#define _TwoNumbersWithSum_
#ifdef _TwoNumbersWithSum_

#include<iostream>
using namespace std;

bool FindNumbersWithSum(int data[], int length, int sum_expected, int* num1, int* num2);
int main()
{
	int data[] = { 1, 2, 4, 7, 11, 15 };
	int length = sizeof(data) / sizeof(int);
	int sum_expected = 4;
	int num1, num2;
	bool found = FindNumbersWithSum(data, length, sum_expected, &num1, &num2);
	return 0;
}
bool FindNumbersWithSum(int data[], int length, int sum_expected, int* num1, int* num2) {
	bool found = false;
	if (length < 1 || num1 == NULL || num2 == NULL)
		return found;
	int p1 = 0, p2 = length - 1;
	while (p1 < p2) {
		int sum = data[p1] + data[p2];
		if (sum == sum_expected) {
			*num1 = data[p1];
			*num2 = data[p2];
			found = true;
			cout << "和为 " << sum_expected << " 的两个数为： " << endl;
			cout << *num1 << " " << *num2 << endl;
			break;
		}
		else if (sum > sum_expected)
			p2--;
		else
			p1++;
	}
	if (!found)
		cout << "不存在和为 " << sum_expected << " 的两个数." << endl;
	return found;
}
#endif // _TwoNumbersWithSum_