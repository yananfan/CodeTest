//#define _InversePairs_
#ifdef _InversePairs_

#include<iostream>
using namespace std;

int InversePairsCore(int* data, int* copy, int start, int end);
int InversePairs(int* data, int length);
int main()
{
	//int data[] = { 1, 2, 3, 4, 7, 6, 5 }; // 3
	//int data[] = { 6, 5, 4, 3, 2, 1 }; // 15
	//int data[] = { 1, 2, 3, 4, 5, 6 }; // 0
	//int data[] = { 1 }; // 0
	//int data[] = { 1, 2 }; // 0
	//int data[] = { 2, 1 }; // 1
	int data[] = { 1, 2, 1, 2, 1 }; // 3

	int length = sizeof(data) / sizeof(int);
	int count = InversePairs(data, length);
	cout << "逆序对的数目： " << count << endl;

	return 0;
}
int InversePairsCore(int* data, int* copy, int start, int end) {
	if (start == end) {
		copy[start] = data[start];
		return 0;
	}
	int mid = start + (end - start) / 2;
	int left = InversePairsCore(copy, data, start, mid);
	int right = InversePairsCore(copy, data, mid + 1, end);
	int p1 = mid, p2 = end, p3 = end;
	int count = 0;
	while (p1 >= start&&p2 >= mid + 1) {
		if (data[p1] > data[p2]) {
			copy[p3--] = data[p1--];
			count += p2 - mid;
		}
		else
			copy[p3--] = data[p2--];
	}
	for (;p1 >= start;p1--)
		copy[p3--] = data[p1];
	for (;p2 >= mid + 1;p2--)
		copy[p3--] = data[p2];
	return left + right + count;
}
int InversePairs(int* data, int length) {
	if (data == NULL || length < 0)
		return 0;
	int* copy = new int[length];
	for (int i = 0;i < length;i++)
		copy[i] = data[i];
	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;
	return count;
}
#endif // _InversePairs_