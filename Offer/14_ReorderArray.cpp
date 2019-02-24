//#define _ReorderOddEven_
#ifdef _ReorderOddEven_

#include<iostream>

using namespace std;

void Print(int array[], int length);
void ReorderOddEven(int* pData, unsigned int length);

void Reorder(int* pData, unsigned int length, bool(*func)(int));
bool isEven(int n);
void ReorderOddEven_2(int* pData, unsigned int length);
int main()
{
	//int num[] = { 1, 2, 3, 4, 5, 6, 7 };
	int num[] = { 2, 4, 6, 1, 3, 5, 7 };
	//int num[] = { 1, 3, 5, 7, 2, 4, 6 };
	//int num[] = { 1 };
	//int num[] = { 2 };
	int length = sizeof(num) / sizeof(int);

	cout << "原数组：" << endl;
	Print(num, length);
	cout << "调整之后的数组(方法1)：" << endl;
	ReorderOddEven(num, length);
	Print(num, length);
	cout << "调整之后的数组(方法2)：" << endl;
	ReorderOddEven_2(num, length);
	Print(num, length);

	ReorderOddEven(NULL, 0);
	Print(NULL, 0);


	return 0;
}

void Print(int array[], int length) {
	if (length <= 0) {
		cout << "NULL" << endl;
		return;
	}
	for (int i = 0;i < length;i++)
		cout << array[i] << " ";
	cout << endl;
}
void  ReorderOddEven(int* pData, unsigned int length) {
	if (pData == NULL || length == 0) return;
	int* p1 = pData;
	int* p2 = pData + length - 1;
	while (p1 < p2) {
		while (p1 < p2 && (*p1 & 0x1) != 0)
			p1++;
		while (p1 < p2 && (*p2 & 0x1) == 0)
			p2--;
		if (p1 < p2) {
			int temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}
	}
}
void Reorder(int* pData, unsigned int length, bool(*func)(int)) {
	if (pData == NULL || length == 0) return;
	int* p1 = pData;
	int* p2 = pData + length - 1;
	while (p1 < p2) {
		while (p1 < p2 && !func(*p1))
			p1++;
		while (p1 < p2 && func(*p2))
			p2--;
		if (p1 < p2) {
			int temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}
	}
}
bool isEven(int n) {
	return (n & 1) == 0;
}
void ReorderOddEven_2(int* pData, unsigned int length) {
	Reorder(pData, length, isEven);
}
#endif // _ReorderOddEven_