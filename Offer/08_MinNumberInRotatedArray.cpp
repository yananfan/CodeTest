//#define _MinNumberInRotatedArray_
#ifdef _MinNumberInRotatedArray_

#include<iostream>
#include<exception>

using namespace std;
int MinInOrder(int* array, int p1, int p2);
int Min(int* array, int length);
int main()
{
	int array1[] = { 3, 4, 5, 1, 2 }; // 1
	cout << Min(array1, 5) << endl;

	int array2[] = { 3, 4, 5, 1, 1, 2 }; // 1
	cout << Min(array2, 6) << endl;

	int array3[] = { 3, 4, 5, 1, 2, 2 }; // 1
	cout << Min(array3, 6) << endl;

	int array4[] = { 1, 0, 1, 1, 1 }; // 0
	cout << Min(array4, 5) << endl;

	int array5[] = { 1, 2, 3, 4, 5 }; // 1
	cout << Min(array5, 5) << endl;

	int array6[] = { 2 }; // 2
	cout << Min(array6, 1) << endl;

	cout << Min(NULL, 0) << endl;

	return 0;
}
int Min(int* array, int length) {
	if (array == NULL || length <= 0)
	{
		//throw new exception("Invalid parameters");
		return -1;
	}
	int p1 = 0, p2 = length - 1;
	int mid = p1;
	while (array[p1] >= array[p2])
	{
		if (p2 - p1 == 1) {
			mid = p2;
			break;
		}
		mid = (p1 + p2) / 2;
		if (array[p1] == array[mid] && array[p1] == array[p2])
			return MinInOrder(array, p1, p2);
		if (array[mid] >= array[p1])
			p1 = mid;
		else if (array[mid] <= array[p2])
			p2 = mid;
	}
	return array[mid];
}
int MinInOrder(int* array, int p1, int p2) {
	int result = array[p1];
	for (int i = p1 + 1;i <= p2;i++) {
		if (result > array[i])
			result = array[i];
	}
	return result;
}
#endif // _MinNumberInRotatedArray_