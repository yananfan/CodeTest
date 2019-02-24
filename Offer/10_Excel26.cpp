//#define _Excel26_
#ifdef _Excel26_

#include<iostream>
#include<string>

using namespace std;

int StringT0Int(const string& str);

int main()
{
	string str;
	while (getline(cin, str))
	{
		cout << str << ":" << StringT0Int(str) << endl;
	}
	return 0;
}
int StringT0Int(const string& str) {
	int length = str.length();
	if (length < 0) {
		cout << "Invalid Input." << endl;
		return -1;
	}
	int sum = 0;
	for (int i = 0;i < length;i++) {
		int temp = str[i] - 'A';
		if (temp < 0 || temp >= 26) {
			cout << "Invalid Input." << endl;
			return -1;
		}
		sum = 26 * sum + 1 + temp;
	}
	return sum;
}
#endif // _Excel26_