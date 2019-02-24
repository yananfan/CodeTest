//#define _MoreThanHalfNumber_
#ifdef _MoreThanHalfNumber_

#include<iostream>
#include"08_Partition.h"

using namespace std;

bool g_bInputInvalid = false;
// 超过一半
bool CheckInvalidArray(int* numbers, int length);
bool CheckMoreThanHalf(int* numbers, int length, int number);
int MoreThanHalfNum_1(int* numbers, int length);
int MoreThanHalfNum_2(int* numbers, int length);
// 至少一半减一
int getNumOverHalf(int *nums, int size);
// 恰好一半
int Find2(int * data, int length);
int main()
{
	//int numbers[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 }; // 存在出现次数超过数组长度一半的数字
	//int numbers[] = { 1, 2, 3, 2, 4, 2, 5, 2, 3 }; // 不存在出现次数超过数组长度一半的数字
	//int numbers[] = { 2, 2, 2, 2, 2, 1, 3, 4, 5 }; // 出现次数超过数组长度一半的数字都出现在数组的前半部分
	//int numbers[] = { 1, 3, 4, 5, 2, 2, 2, 2, 2 }; // 出现次数超过数组长度一半的数字都出现在数组的后半部分
	//int numbers[] = { 1 }; 
	int numbers[] = { 2,2,1,3 };
	//int numbers[] = { 1,2,3,2,2,4,5,6 };

	int length = sizeof(numbers) / sizeof(int);
	cout << "原始数组为：" << endl;
	for (int i = 0;i < length;i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	int result1 = MoreThanHalfNum_1(numbers, length);
	int result2 = MoreThanHalfNum_2(numbers, length);
	int result3 = getNumOverHalf(numbers, length);
	int result4 = Find2(numbers, length);
	cout << "result1 = " << result1 << endl;
	cout << "result2 = " << result2 << endl;
	cout << "result3 = " << result3 << endl;
	cout << "result4 = " << result4 << endl;

	return 0;
}
bool CheckInvalidArray(int* numbers, int length) {
	g_bInputInvalid = false;
	if (numbers == NULL&&length <= 0)
		g_bInputInvalid = true;
	return g_bInputInvalid;
}
bool CheckMoreThanHalf(int* numbers, int length, int number) {
	int times = 0;
	for (int i = 0;i < length;i++) {
		if (numbers[i] == number)
			times++;
	}
	bool isMoreThanHalf = true;
	if (times * 2 <= length) {
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}
	if (!isMoreThanHalf)
		cout << "不存在出现次数超过数组长度一半的数字" << endl;
	return isMoreThanHalf;
}
int MoreThanHalfNum_1(int* numbers, int length) {
	if (CheckInvalidArray(numbers, length))
		return 0;
	int mid = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, length, start, end);
	while (index != mid) {
		if (index > mid) {
			end = index - 1;
			index = Partition(numbers, length, start, end);
		}
		else {
			start = index + 1;
			index = Partition(numbers, length, start, end);
		}
	}
	int result = numbers[mid];
	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;
	return result;
}
int MoreThanHalfNum_2(int* numbers, int length) {
	if (CheckInvalidArray(numbers, length))
		return 0;
	int result = numbers[0];
	int times = 1;
	for (int i = 1;i < length;i++) {
		if (times == 0) {
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
			times++;
		else
			times--;
	}
	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;
	return result;
}
int getNumOverHalf(int *nums, int size) {
	int record[2][2] = { { 0 } };
	int i = 0;
	for (;i<size;i++) {
		if (record[0][0] == nums[i]) {
			record[0][1]++;
			continue;
		}
		if (record[1][0] == nums[i]) {
			record[1][1]++;
			continue;
		}

		if (record[0][1] <= record[1][1]) {
			record[0][0] = nums[i];
			record[0][1] = 1;
		}
		else {
			record[1][0] = nums[i];
			record[1][1] = 1;
		}
	}
	return record[0][1] > record[1][1] ? record[0][0] : record[1][0];
}
int Find2(int * data, int length)
{
	int result, times, ntimes;
	times = ntimes = 0;
	int i;
	for (i = 0;i<length;i++)
	{
		if (data[i] == data[length - 1])
			ntimes++;   //最后一个元素出现次数
		if (times == 0)
		{
			result = data[i];
			times = 1;
		}
		else
		{
			if (data[i] == result)
				times++;
			else
				times--;
		}
	}
	if (ntimes * 2 == length)
		return data[length - 1];
	else
		return result;
}

#endif // _MoreThanHalfNumber_