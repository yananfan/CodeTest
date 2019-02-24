//#define _LeftRotateString_
#ifdef _LeftRotateString_

#include<iostream>
#include<string>
using namespace std;
// 三次反转法
void Reverse(char* pBegin, char* pEnd);
char* LeftRotateString(char* pStr, int n);
void PrintSentence(char* pData);
int main()
{
	char input[] = "abcdefg";
	int num = 2;
	char* result = LeftRotateString(input, num);

	return 0;
}
void Reverse(char* pBegin, char* pEnd) {
	if (pBegin == NULL || pEnd == NULL)
		return;
	while (pBegin < pEnd) {
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++;
		pEnd--;
	}
}
char* LeftRotateString(char* pStr, int n) {
	if (pStr != NULL) {
		cout << "原始字符串：" << endl;
		PrintSentence(pStr);

		int length = strlen(pStr);
		if (length > 0 && n > 0 && n < length) {
			char* p1 = pStr;
			char* p2 = pStr + n - 1;
			char* p3 = pStr + n;
			char* p4 = pStr + length - 1;
			Reverse(p1, p2);
			Reverse(p3, p4);
			Reverse(p1, p4);
		}
	}
	cout << "左旋 " << n << " 位后的字符串：" << endl;
	PrintSentence(pStr);
	return pStr;
}
void PrintSentence(char* pData) {
	char* p = pData;
	while (*p != '\0') {
		cout << *p;
		p++;
	}
	cout << endl;
}
#endif // _LeftRotateString_