//#define _NumberOfK_
#ifdef _NumberOfK_

#include<iostream>
using namespace std;

int GetFirstK(int* data, int length, int k, int start, int end);
int GetLastK(int* data, int length, int k, int start, int end);
int GetNumberOfK(int* data, int length, int k);
int main()
{
	//int data[] = { 1, 2, 3, 3, 3, 3, 4, 5 }; // 4
	//int data[] = { 3, 3, 3, 3, 4, 5 }; // 4
	int data[] = { 1, 2, 3, 3, 3, 3 }; // 4

	int length = sizeof(data) / sizeof(int);
	int k = 3;

	int count = GetNumberOfK(data, length, k);
	cout << k << " 出现的次数是： " << count << endl;

	return 0;
}
int GetFirstK(int* data, int length, int k, int start, int end) {
	if (start > end)
		return -1;
	int midIndex = (start + end) / 2;
	int midData = data[midIndex];
	if (midData == k) {
		if ((midIndex > 0 && data[midIndex - 1] != k) || midIndex == 0)
			return midIndex;
		else
			end = midIndex - 1;
	}
	else if (midData > k)
		end = midIndex - 1;
	else
		start = midIndex + 1;
	return GetFirstK(data, length, k, start, end);
}
int GetLastK(int* data, int length, int k, int start, int end) {
	if (start > end)
		return -1;
	int midIndex = (start + end) / 2;
	int midData = data[midIndex];
	if (midData == k) {
		if (midIndex < length - 1 && data[midIndex + 1] != k || midIndex == length - 1)
			return midIndex;
		else
			start = midIndex + 1;
	}
	else if (midData > k)
		end = midIndex - 1;
	else
		start = midIndex + 1;
	return GetLastK(data, length, k, start, end);
}
int GetNumberOfK(int* data, int length, int k) {
	int num = 0;
	if (data != NULL && length > 0) {
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);
		if (first > -1 && last > -1)
			num = last - first + 1;
	}
	return num;
}
#endif // _NumberOfK_