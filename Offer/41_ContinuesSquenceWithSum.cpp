//#define _ContinuesSquenceWithSum_
#ifdef _ContinuesSquenceWithSum_

#include<iostream>
using namespace std;

void PrintContinuousSequence(int small, int big);
void FindContinuousSequence(int sum);
int main()
{
	int sum = 1;
	while (sum) {
		cout << "输入一个正数：" << endl;
		cin >> sum;
		FindContinuousSequence(sum);
	}
	return 0;
}
void PrintContinuousSequence(int small, int big) {
	for (int i = small;i <= big;i++)
		cout << i << " ";
	cout << endl;
}
void FindContinuousSequence(int sum) {
	if (sum < 3) {
		cout << sum << " < 3." << endl;
		return;
	}
	int p1 = 1, p2 = 2;
	int mid = (1 + sum) / 2;
	int tempSum = p1 + p2;
	while (p1 < mid) {
		if (tempSum == sum)
			PrintContinuousSequence(p1, p2);
		while (tempSum > sum && p1 < mid) {
			tempSum -= p1;
			p1++;
			if (tempSum == sum)
				PrintContinuousSequence(p1, p2);
		}
		p2++;
		tempSum += p2;
	}	
}
#endif // _ContinuesSquenceWithSum_