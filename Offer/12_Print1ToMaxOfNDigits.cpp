//#define _Print1ToMaxOfNDigits_
#ifdef _Print1ToMaxOfNDigits_

#include<iostream>
#include<memory>

using namespace std;

void PrintNumber(char* number);
// 第一种
void Print1ToMaxOfNDigits_1(int n);
bool Increment(char* number);
// 第二种
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);
void Print1ToMaxOfNDigits_2(int n);

int main()
{
	Print1ToMaxOfNDigits_1(1);
	Print1ToMaxOfNDigits_1(2);
	Print1ToMaxOfNDigits_1(-1);
	Print1ToMaxOfNDigits_1(0);

	Print1ToMaxOfNDigits_2(1);
	Print1ToMaxOfNDigits_2(2);
	Print1ToMaxOfNDigits_2(-1);
	Print1ToMaxOfNDigits_2(0);
	return 0;
}

void PrintNumber(char* number) {
	bool isBeginning0 = true;
	int length = strlen(number);
	for (int i = 0;i < length;i++) {
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
			cout << number[i];
	}
	cout << endl;
}
bool Increment(char* number) {
	bool isOverflow = false;
	int nCarryout = 0;
	int length = strlen(number);
	for (int i = length - 1;i >= 0;i--) {
		int tempSum = number[i] - '0' + nCarryout;
		if (i == length - 1)
			tempSum++;
		if (tempSum >= 10) {
			if (i == 0)
				isOverflow = true;
			else {
				tempSum -= 10;
				nCarryout = 1;
				number[i] = tempSum + '0';
			}
		}
		else {
			number[i] = tempSum + '0';
			break;
		}
	}
	return isOverflow;
}
void Print1ToMaxOfNDigits_1(int n) {
	if (n <= 0) {
		cout << n << " is Invalid Input." << endl;
		return;
	}
	cout << n << " is started to print." << endl;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increment(number))
		PrintNumber(number);
	delete[] number;
	cout << n << " is finished." << endl;
}
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index) {
	if (index == length - 1) {
		PrintNumber(number);
		return;
	}
	for (int i = 0;i < 10;i++) {
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}
void Print1ToMaxOfNDigits_2(int n) {
	if (n <= 0) {
		cout << n << " is Invalid Input." << endl;
		return;
	}
	cout << n << " is started to print." << endl;
	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0;i < 10;i++) {
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	delete[] number;
	cout << n << " is finished." << endl;
}
#endif // _Print1ToMaxOfNDigits_