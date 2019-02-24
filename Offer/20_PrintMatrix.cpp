//#define _20_PrintMatrix_
#ifdef _20_PrintMatrix_

#include<iostream>

using namespace std;

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);
void PrintNumber(int number);
void PrintMatrixClockwisely(int** numbers, int columns, int rows);

int main()
{
	//const int rows = 4, columns = 4;
	//const int rows = 4, columns = 5;
	//const int rows = 5, columns = 3;
	//const int rows = 3, columns = 4;
	//const int rows = 4, columns = 1;
	//const int rows = 1, columns = 4;
	const int rows = 1, columns = 1;

	int** numbers = new int*[rows];

	cout << "ԭʼ����" << endl;
	for (int i = 0; i < rows; ++i) {
		numbers[i] = new int[columns];
		for (int j = 0; j < columns; ++j)
		{
			numbers[i][j] = i * columns + j + 1;
			cout << numbers[i][j] << " ";
		}
		cout << endl;
	}

	cout << "˳ʱ���ӡ�ľ���" << endl;
	PrintMatrixClockwisely(numbers, columns, rows);

	return 0;
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start) {
	// һȦ����ʼ���꣨start��start���ͣ�endr��endc��
	int endr = rows - start - 1;
	int endc = columns - start - 1;
	int i, temp;
	// �������Ҵ�ӡһ��
	for (i = start;i <= endc;i++) {
		temp = numbers[start][i];
		PrintNumber(temp);
	}
	// �������´�ӡһ��
	if (start < endr) {
		for (i = start + 1;i <= endr;i++) {
			temp = numbers[i][endc];
			PrintNumber(temp);
		}
	}
	// ���������ӡһ��
	if (start < endr && start < endc) {
		for (i = endc - 1;i >= start;i--) {
			temp = numbers[endr][i];
			PrintNumber(temp);
		}
	}
	// �������ϴ�ӡһ��
	if (start < endc && start < endr - 1) {
		for (i = endr - 1;i >= start + 1;i--) {
			temp = numbers[i][start];
			PrintNumber(temp);
		}
	}
}
void PrintNumber(int number) {
	cout << number << " ";
}
void PrintMatrixClockwisely(int** numbers, int columns, int rows) {
	if (numbers == NULL || columns <= 0 || rows <= 0)
		return;
	int start = 0;
	while (columns > start * 2 && rows > start * 2) {
		PrintMatrixInCircle(numbers, columns, rows, start);
		start++;
	}
}
#endif // _20_PrintMatrix_