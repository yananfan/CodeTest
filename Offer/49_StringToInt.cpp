//#define _StringToInt_
#ifdef _StringToInt_

#include<iostream>
using namespace std;

long long StrToIntCore(const char* str, bool minus);

enum Status { kValid = 0, kInvalid };
int g_nStatus = kValid;

int StrToInt(const char* str);
void PrintSentence(char* pData);
int main()
{
	//char string[] = "  123"; // 123,0
	char string[] = "  +123"; // 123,0
	//char string[] = "-123"; // -123,0
	//char string[] = "1a23"; // 0,1
	//char string[] = "+0"; // 0,0
	//char string[] = "-0"; // 0,0
	//char string[] = "+"; // 0,1
	//char string[] = "-"; // 0,1
	//char string[] = "+2147483647"; // 2147483647,0
	//char string[] = "-2147483647"; // -2147483647,0
	//char string[] = "+2147483648"; // 0,1
	//char string[] = "-2147483649"; // 0,1
	//char string[] = "+2147483649"; // 0,1
	//char string[] = "-2147483648"; // -2147483648,0
	//char string[] = ""; // 0,1

	cout << "原始字符串：     " ;
	PrintSentence(string);

	int result = StrToInt(string);
	cout << "转换后的数字为： " << result << endl;
	cout << "全局 g_nStatus = " << g_nStatus << endl;
	return 0;
}
long long StrToIntCore(const char* str, bool minus) {
	long long num = 0;
	while (*str != '\0') {
		if (*str >= '0' && *str <= '9') {
			int flag = minus ? -1 : 1;
			num = num * 10 + flag*(*str - '0');
			if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000)) {
				num = 0;
				break;
			}
			str++;
		}
		else {
			num = 0;
			break;
		}
	}
	if (*str == '\0')
		g_nStatus = kValid;
	return num;
}
int StrToInt(const char* str) {
	g_nStatus = kInvalid;
	long long num = 0;
	if (str != NULL && *str != '\0') {
		bool minus = false;
		while (*str == ' ')
			str++;
		if (*str == '+')
			str++;
		else if (*str == '-') {
			str++;
			minus = true;
		}
		if (*str != '\0')
			num = StrToIntCore(str, minus);
	}
	return (int)num;
}
void PrintSentence(char* pData) {
	char* p = pData;
	while (*p != '\0') {
		cout << *p;
		p++;
	}
	cout << endl;
}
#endif // _StringToInt_