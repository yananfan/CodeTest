#define _ContinousCards_
#ifdef _ContinousCards_

#include<iostream>
#include<stdlib.h>
using namespace std;

int compare(const void *arg1, const void *arg2);
bool IsContinuous(int* numbers, int length);
int main()
{
	//int numbers[] = { 1, 3, 2, 5, 4 }; // 1
	//int numbers[] = { 1, 3, 2, 6, 4 }; // 0
	//int numbers[] = { 0, 3, 2, 6, 4 }; // 1
	//int numbers[] = { 0, 3, 2, 7, 4 }; // 0
	//int numbers[] = { 0, 0, 2, 6, 5 }; // 1
	int numbers[] = { 0, 3, 3, 6, 4 }; // 0

	int length = sizeof(numbers) / sizeof(int);
	cout << IsContinuous(numbers, length) << endl;
	return 0;
}
int compare(const void *arg1, const void *arg2) {
	return *(int*)arg1 - *(int*)arg2;
}
bool IsContinuous(int* numbers, int length) {
	if (numbers == NULL || length < 1)
		return false;
	qsort(numbers, length, sizeof(int), compare);
	int numofzero = 0, numofgap = 0;
	for (int i = 0;i < length&&numbers[i] == 0;i++)
		numofzero++;
	int index1 = numofzero;
	int index2 = index1 + 1;
	while (index2 < length) {
		if (numbers[index1] == numbers[index2])
			return false;
		numofgap += numbers[index2] - numbers[index1] - 1;
		index1 = index2;
		index2++;
	}
	return (numofgap > numofzero) ? false : true;
}
#endif // _ContinousCards_
