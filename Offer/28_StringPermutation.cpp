//#define _StringPermutation_
#ifdef _StringPermutation_

#include<iostream>

using namespace std;

void Permutation(char* pStr, char* pBegin);
void Permutation(char* pStr);

int main()
{
	char string[] = "abc";
	Permutation(string);
	return 0;
}
void Permutation(char* pStr, char* pBegin) {
	if (*pBegin == '\0')
	{
		cout << pStr << endl;
	}
	else {
		for (char* p = pBegin;*p != '\0';++p) {
			char temp = *p;
			*p = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *p;
			*p = *pBegin;
			*pBegin = temp;
		}
	}
}

void Permutation(char* pStr) {
	if (pStr == NULL)
		return;
	Permutation(pStr, pStr);
}
#endif // _StringPermutation_