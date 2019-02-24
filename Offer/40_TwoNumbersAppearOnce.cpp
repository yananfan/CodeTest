//#define _NumbersAppearOnce_
#ifdef _NumbersAppearOnce_

#include<iostream>
using namespace std;

int FindFirstBitIs1(int num);
bool IsBit1(int num, int indexBit);
void FindNumsAppearOnce(int data[], int length, int* num1, int* num2);
int main()
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 }; // 4 6
	int length = sizeof(data) / sizeof(int);
	int result1 = 0, result2 = 0;
	FindNumsAppearOnce(data, length, &result1, &result2);
	cout << "result1 = " << result1 << endl;
	cout << "result2 = " << result2 << endl;

	return 0;
}
int FindFirstBitIs1(int num) {
	int indexBit1 = 0;
	while (((num & 1) == 0) && (indexBit1 < 8 * sizeof(int))) {
		num = num >> 1;
		++indexBit1;
	}
	return indexBit1;
}
bool IsBit1(int num, int indexBit) {
	num = num >> indexBit;
	return (num & 1);
}
void FindNumsAppearOnce(int data[], int length, int* num1, int* num2) {
	if (data == NULL || length < 2)
		return;
	int resultXOR = 0;
	for (int j = 0;j < length;j++)
		resultXOR ^= data[j];
	int indexOf1 = FindFirstBitIs1(resultXOR);
	*num1 = *num2 = 0;
	for (int i = 0;i < length;i++) {
		if (IsBit1(data[i], indexOf1))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
}
#endif // _NumbersAppearOnce_