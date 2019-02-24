//#define _IsExchangeWord_
#ifdef _IsExchangeWord_

#include<iostream>
using namespace std;

bool IsExchangeWord(char* str1, char* str2);
int main()
{
	char str1[] = "silent";
	cout << "str1 = " << str1 << endl;
	char str2[] = "listen";
	cout << "str2 = " << str2 << endl;

	bool is = IsExchangeWord(str1, str2);
	cout << "1 for true,0 for false: " << is << endl;

	return 0;
}
bool IsExchangeWord(char* str1, char* str2) {
	if (str1 == NULL || str2 == NULL)
		return false;
	int hashtable[256] = { 0 };
	char *p1 = str1, *p2 = str2;
	while (*p1 && *p2) {
		hashtable[*(p1++)]++;
		hashtable[*(p2++)]--;
	}
	if (*p1 != '\0' || *p2 != '\0')
		return false;
	for (int i = 0;i < 256;i++) {
		if (hashtable[i] != 0)
			return false;
	}
	return true;
}
#endif // _IsExchangeWord_