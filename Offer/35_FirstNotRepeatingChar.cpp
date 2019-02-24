//#define _FirstNotRepeatingChar_
#ifdef _FirstNotRepeatingChar_

#include<iostream>
using namespace std;
// 遍历两次字符串
char FirstNotRepeatingChar(char* pString);
// 遍历一次字符串
char getUniqueCharacter(char *s);
int main()
{
	char str[1000];
	while (cin >> str)
		cout << FirstNotRepeatingChar(str) << " " << getUniqueCharacter(str) << endl;
	return 0;
}
char FirstNotRepeatingChar(char* pString) {
	if (pString == NULL)
		return '#';
	const int tablesize = 256;
	int hashtable[tablesize] = { 0 }; 
	char* pHashKey = pString;
	while (*(pHashKey) != '\0')
		hashtable[*(pHashKey++)]++;
	pHashKey = pString;
	while (*pHashKey != '\0') {
		if (hashtable[*pHashKey] == 1)
			return *pHashKey;
		pHashKey++;
	}
	return '#';
}

char getUniqueCharacter(char *s) {
	int order[256] = { 0 };
	int counter[256] = { 0 };
	int i = 0;
	char temp;
	char *p = s;
	while (*p) {
		temp = *p;
		if (counter[temp] == 0) {
			order[i++] = temp;
		}
		counter[temp]++;
		p++;
	}
	int j;
	for (j = 0; j < 256; j++) {
		if (order[j] != 0) {
			if (counter[order[j]] == 1) {
				temp = order[j];
				break;
			}
		}
	}
	if (j >= 256) {
		return '#';
	}
	else {
		return temp;
	}
}
#endif // _FirstNotRepeatingChar_
