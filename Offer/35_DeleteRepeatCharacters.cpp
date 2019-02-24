//#define _DeleteRepeatCharacters_
#ifdef _DeleteRepeatCharacters_

#include<iostream>
using namespace std;
// ×Ö·û´®È¥ÖØ
char* DeleteRepeatCharacters(char* str);
int main()
{
	char str1[] = "google";
	cout << "str1 = " << str1 << endl;
	char* str2 = DeleteRepeatCharacters(str1);
	cout << "str2 = " << str2 << endl;

	return 0;
}
char* DeleteRepeatCharacters(char* str) {
	if (str == NULL) {
		cout << "NULL." << endl;
		return NULL;
	}
	bool hashtable[256] = { false };
	char *pold = str, *pnew = str;
	while (*pold) {
		if (hashtable[*pold] == true)
			pold++;
		else {
			hashtable[*pold] = true;
			*pnew = *pold;
			pold++;
			pnew++;
		}
	}
	*pnew = '\0';
	return str;
}
#endif // _DeleteRepeatCharacters_
