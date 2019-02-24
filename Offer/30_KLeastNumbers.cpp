//#define _KLeastNumbers_
#ifdef _KLeastNumbers_

#include<iostream>
#include<vector>
#include<functional>
#include<set>
#include"08_Partition.h"

using namespace std;

void PrintArray(int* input, int n);
void GetLeastNumbers_1(int* input, int n, int* output, int k);

typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator  setIterator;
void GetLeastNumbers_2(const vector<int>& data, intSet& leastNumbers, int k);
int main()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int length = sizeof(data) / sizeof(int);
	cout << "原始数组：" << endl;
	PrintArray(data, length);
	int expected[] = { 1, 2, 3, 4 };
	int k = sizeof(expected) / sizeof(int);
	cout << "预期的输出数组：" << endl;
	PrintArray(expected, k);
	int* output = new int[k];
	GetLeastNumbers_1(data, length, output, k);

	vector<int> vectorData;
	for (int i = 0; i < length; ++i)
		vectorData.push_back(data[i]);
	intSet leastNumbers;
	GetLeastNumbers_2(vectorData, leastNumbers, k);

	return 0;
}
void GetLeastNumbers_1(int* input, int n, int* output, int k) {
	if (input == NULL || output == NULL || n <= 0 || k <= 0 || k > n)
		return;
	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	while (index != k - 1) {
		if (index > k - 1) {
			end = index - 1;
			index = Partition(input, n, start, end);
		}
		else {
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}
	for (int i = 0;i < k;i++)
		output[i] = input[i];
	cout << "方法一计算的结果：" << endl;
	PrintArray(output, k);
}
void PrintArray(int* input, int n) {
	for (int i = 0;i < n;i++)
		cout << input[i] << " ";
	cout << endl;
}
void GetLeastNumbers_2(const vector<int>& data, intSet& leastNumbers, int k) {
	leastNumbers.clear();
	if (k < 1 || data.size() < k)
		return;
	vector<int>::const_iterator iter = data.begin();
	for (;iter != data.end();++iter) {
		if (leastNumbers.size() < k)
			leastNumbers.insert(*iter);
		else {
			setIterator iterGreastest = leastNumbers.begin();
			if (*iter < *(leastNumbers.begin())) {
				leastNumbers.erase(iterGreastest);
				leastNumbers.insert(*iter);
			}
		}
	}
	cout << "方法二计算的结果：" << endl;
	setIterator iterr = leastNumbers.begin();
	for (;iterr != leastNumbers.end();++iterr)
		cout << *iterr << " ";
	cout << endl;
}

#endif // _KLeastNumbers_