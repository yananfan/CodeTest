//#define ReplaceBlank_
#ifdef ReplaceBlank_

#include<iostream>
using namespace std;

void ReplaceBlank(char str[], int length);

int main()
{
	const int length = 100;
	char str1[length] = " good", str2[length] = "good ", str3[length] = "go od", str4[length] = "go   od";
	char str5[length] = "good.";
	char str6[length] = "", str7[length] = " ", str8[length] = "   ";

	ReplaceBlank(str1, length);
	ReplaceBlank(str2, length);
	ReplaceBlank(str3, length);
	ReplaceBlank(str4, length);
	ReplaceBlank(str5, length);
	ReplaceBlank(str6, length);
	ReplaceBlank(str7, length);
	ReplaceBlank(str8, length);
	ReplaceBlank(NULL, 0);
	return 0;
}
void ReplaceBlank(char str[], int length)
{
	if (str == NULL&&length <= 0) return;

	int oldlength = 0, numofBlank = 0;
	int i = 0;
	while (str[i] != '\0') {
		++oldlength;
		cout << str[i];
		if (str[i] == ' ')
			++numofBlank;
		++i;
	}
	cout << " " << oldlength << "   " << numofBlank << endl;
	cout << "   ";
	int newlength = oldlength + 2 * numofBlank;
	if (newlength > length) return;

	int p1 = oldlength, p2 = newlength;
	while (p1 >= 0 && p2 > p1) {
		if (str[p1] == ' ') {
			str[p2--] = '0';
			str[p2--] = '2';
			str[p2--] = '%';
		}
		else {
			str[p2--] = str[p1];
		}
		--p1;
	}
	for (int i = 0; i < newlength; i++)
	{
		cout << str[i];
	}
	cout << endl;
}

#endif // ReplaceBlank_