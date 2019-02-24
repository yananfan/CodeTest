//#define _ReverseWordsInSentence_
#ifdef _ReverseWordsInSentence_

#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

// 先翻转句子再翻转单词
void Reverse(char* pBegin, char* pEnd);
char* ReverseSentence(char *pData);
void PrintSentence(char* pData);

// 使用容器
void Reverse_vector(string& s);
void Reverse_stack(string& s);

int main()
{
	char input[] = "I am a student.";
	ReverseSentence(input);

	string data = "I am a student.";
	Reverse_vector(data);
	string data1 = "I am a student.";
	Reverse_stack(data1);

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
char* ReverseSentence(char *pData) {
	if (pData == NULL)
		return NULL;
	cout << "原始单词顺序： " << endl;
	PrintSentence(pData);
	char *pBegin = pData, *pEnd = pData;
	while (*pEnd != '\0')
		pEnd++;
	pEnd--;
	Reverse(pBegin, pEnd);
	pBegin = pEnd = pData;
	while (*pBegin != '\0') {
		if (*pBegin == ' ') {
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0') {
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
			pEnd++;
	}
	cout << "翻转后的句子是：" << endl;
	PrintSentence(pData);
	return pData;
}
void PrintSentence(char* pData) {
	char* p = pData;
	while (*p != '\0') {
		cout << *p;
		p++;
	}
	cout << endl;
}
void Reverse_vector(string& s) {
	vector<string> result;
	string temp;
	for (int i = 0;i < s.size();i++) {
		if (s[i] != ' ')
			temp += s[i];
		else {
			result.push_back(temp);
			temp = "";
		}
	}
	result.push_back(temp);
	cout << "vector的结果：" << endl;
	for (int j = result.size() - 1;j >= 0;j--)
		cout << result[j] << " ";
	cout << endl;
}
void Reverse_stack(string& s) {
	stack<string> result;
	string temp;
	for (int i = 0;i < s.length();i++) {
		if (s[i] != ' ')
			temp += s[i];
		else {
			result.push(temp);
			temp = "";
		}
	}
	result.push(temp);
	cout << "stack 的结果：" << endl;
	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
	//int stackSize = result.size();
	//for (int i = 0;i < stackSize;i++) {
	//	cout << result.top() << " ";
	//	result.pop();
	//}
	cout << endl;
}

#endif // _ReverseWordsInSentence_