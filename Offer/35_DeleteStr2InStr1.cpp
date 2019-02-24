//#define _DeleteStr2InStr1_
#ifdef _DeleteStr2InStr1_

#include<iostream>
#include<cstring>
using namespace std;

char * DeleteStr2InStr1(char * const str1, const char * const str2);
int main()
{
	char str1[] = "we are students.";
	cout << "str1 = " << str1 << endl;
	char str2[] = "aeiou";
	cout << "str2 = " << str2 << endl;

	char* str = DeleteStr2InStr1(str1, str2);
	cout << "str  = " << str << endl;
	return 0;
}
char * DeleteStr2InStr1(char * const str1, const char * const str2) {
	int len2 = strlen(str2);
	int hashtable[256] = { 0 };
	char* p = str1;
	int p1 = 0;
	for (int i = 0;i < len2;i++)
		hashtable[str2[i]] = 1;
	while (*p) {
		if (hashtable[*p] == 0)
			str1[p1++] = *p;
		p++;
	}
	str1[p1] = '\0';
	return str1;
}
#endif // _DeleteStr2InStr1_