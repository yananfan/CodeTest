//#define MergerSortedArray
#ifdef MergerSortedArray

#include<iostream>
using namespace std;

void merger(int A1[], int len1, int A2[], int len2);

int main()
{
	const int len = 20, lenb = 3, lena = 5;
	int a[len] = { 1,3,5,6,9 };
	int b[lenb] = { 2,4,7 };
	merger(a, lena, b, lenb);
	for (int i = 0;i < lena + lenb;i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
void merger(int A1[], int len1, int A2[], int len2)
{
	int len = len1 + len2 - 1;
	int p1 = len1 - 1;
	int p2 = len2 - 1;
	while (p1 >= 0 && p2 >= 0)
	{
		if (A1[p1] > A2[p2])
			A1[len--] = A1[p1--];
		else
			A1[len--] = A2[p2--];
	}
	while (p2 >= 0)
	{
		A1[len--] = A2[p2--];
	}
}
#endif // MergerSortedArray