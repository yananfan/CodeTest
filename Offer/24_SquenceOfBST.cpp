//#define _SquenceOfBST_
#ifdef _SquenceOfBST_

#include<iostream>

using namespace std;

bool VerifySquenceOfBST_Post(int sequence[], int length);
bool VerifySquenceOfBST_Pre(int sequence[], int length);
bool VerifySquenceOfBST_In(int sequence[], int length);

int main()
{
	// ≤‚ ‘∫Û–Ú–Ú¡–
	int data[] = { 5,7,6,9,11,10,8 };
	int length = sizeof(data) / sizeof(int);

	bool result = VerifySquenceOfBST_Post(data, length);
	cout << "result ( 1 for true,0 for false ) = " << result << endl;

	int data_1[] = { 7,4,6,5 };
	int length_1 = sizeof(data_1) / sizeof(int);

	bool result_1 = VerifySquenceOfBST_Post(data_1, length_1);
	cout << "result ( 1 for true,0 for false ) = " << result_1 << endl;
	// ≤‚ ‘«∞–Ú–Ú¡–
	int data_2[] = { 5,7,6,9,11,10,8 };
	int length_2 = sizeof(data_2) / sizeof(int);

	bool result_2 = VerifySquenceOfBST_Pre(data_2, length_2);
	//bool result_2 = SequenceIsPreOrderOfBST(data_2, length_2);

	cout << "result ( 1 for true,0 for false ) = " << result_2 << endl;

	int data_3[] = { 7,4,6,5 };
	int length_3 = sizeof(data_3) / sizeof(int);

	bool result_3 = VerifySquenceOfBST_Pre(data_3, length_3);
	cout << "result ( 1 for true,0 for false ) = " << result_3 << endl;
	// ≤‚ ‘÷––Ú–Ú¡–
	int data_4[] = { 5,6,7,8,9,10,11 };
	int length_4 = sizeof(data_4) / sizeof(int);

	bool result_4 = VerifySquenceOfBST_In(data_4, length_4);
	cout << "result ( 1 for true,0 for false ) = " << result_4 << endl;

	int data_5[] = { 7,4,6,5 };
	int length_5 = sizeof(data_5) / sizeof(int);

	bool result_5 = VerifySquenceOfBST_In(data_5, length_5);
	cout << "result ( 1 for true,0 for false ) = " << result_5 << endl;

	return 0;
}

bool VerifySquenceOfBST_Post(int sequence[], int length) {
	if (sequence == NULL || length <= 0)
		return false;
	int root = sequence[length - 1];
	int i, j;
	for (i = 0;i < length - 1;i++) {
		if (sequence[i] > root)
			break;
	}
	for (j = i;j < length - 1;j++) {
		if (sequence[j] < root)
			return false;
	}
	bool left = true;
	if (i > 0)
		left = VerifySquenceOfBST_Post(sequence, i);
	bool right = true;
	if (i < length - 1)
		right = VerifySquenceOfBST_Post(sequence + i, length - i - 1);
	return (left&&right);
}
bool VerifySquenceOfBST_Pre(int sequence[], int length) {
	if (sequence == NULL || length <= 0)
		return false;
	int root = sequence[0];
	int i, j;
	for (i = 1;i < length;i++) {
		if (sequence[i] > root)
			break;
	}
	for (j = i;j < length;j++) {
		if (sequence[j] < root)
			return false;
	}
	bool left = true;
	if (i > 1)
		left = VerifySquenceOfBST_Pre(sequence + 1, i - 1);
	bool right = true;
	if (i < length)
		right = VerifySquenceOfBST_Pre(sequence + i, length - i);
	return (left&&right);
}
bool VerifySquenceOfBST_In(int sequence[], int length) {
	if (sequence == NULL || length <= 0)
		return false;
	int i;
	for (i = 0;i < length - 1;i++) {
		if (sequence[i] > sequence[i + 1])
			break;
	}
	if (i == length - 1)
		return true;
	return false;
}
#endif // _SquenceOfBST_
