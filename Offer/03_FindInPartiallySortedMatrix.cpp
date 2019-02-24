//#define FindInPartiallySortedMatrix
#ifdef FindInPartiallySortedMatrix

#include<iostream>
using namespace std;

bool FindRight(int* matrix, int rows, int cols, int number); // 右上角

bool FindLeft(int* matrix, int rows, int cols, int number); // 左下角

int main()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	int rows = 4, cols = 4;
	int num1 = 15, num2 = 1, num3 = 7;
	int num4 = 20, num5 = 0, num6 = 3;
	bool test1 = FindRight((int*)matrix, rows, cols, num1), test11 = FindLeft((int*)matrix, rows, cols, num1);
	cout << num1 << " " << test1 << " " << test11 << endl;

	bool test2 = FindRight((int*)matrix, rows, cols, num2), test22 = FindLeft((int*)matrix, rows, cols, num2);
	cout << num2 << " " << test2 << " " << test22 << endl;

	bool test3 = FindRight((int*)matrix, rows, cols, num3), test33 = FindLeft((int*)matrix, rows, cols, num3);
	cout << num3 << " " << test3 << " " << test33 << endl;

	bool test4 = FindRight((int*)matrix, rows, cols, num4), test44 = FindLeft((int*)matrix, rows, cols, num4);
	cout << num4 << " " << test4 << " " << test44 << endl;

	bool test5 = FindRight((int*)matrix, rows, cols, num5), test55 = FindLeft((int*)matrix, rows, cols, num5);
	cout << num5 << " " << test5 << " " << test55 << endl;

	bool test6 = FindRight((int*)matrix, rows, cols, num6), test66 = FindLeft((int*)matrix, rows, cols, num6);
	cout << num6 << " " << test6 << " " << test66 << endl;

	bool test7 = FindRight(NULL, rows, cols, num3), test77 = FindLeft(NULL, rows, cols, num3);
	cout << num3 << " " << test7 << " " << test77 << endl;

	return 0;
}
bool FindRight(int* matrix, int rows, int cols, int number) // 右上角
{
	bool found = false;
	if (matrix != NULL&&rows > 0 && cols > 0)
	{
		int row = 0; // 右上角元素的位置
		int col = cols - 1;
		while (row < rows&&col >= 0)
		{
			if (matrix[row*cols + col] == number) {
				found = true;
				break;
			}
			else if (matrix[row*cols + col] > number) --col;
			else ++row;
		}
	}
	return found;
}
bool FindLeft(int* matrix, int rows, int cols, int number) // 左下角
{
	bool found = false;
	if (matrix != NULL&&rows > 0 && cols > 0) {
		int col = 0;
		int row = rows - 1;
		while (col < cols&&row >= 0)
		{
			if (matrix[row*cols + col] == number) {
				found = true;
				break;
			}
			else if (matrix[row*cols + col] > number) --row;
			else ++col;
		}
	}
	return found;
}

#endif // FindInPartiallySortedMatrix