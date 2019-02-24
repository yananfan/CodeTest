//#define AssignmentOperator
#ifdef AssignmentOperator

#pragma warning(disable:4996)
#include<iostream>
#include<string>

using namespace std;

class CMyString
{
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString &str);
	~CMyString(void);
	CMyString& operator=(const CMyString& str);
	void Print();
private:
	char *m_pData;
};

CMyString::CMyString(char *pData)
{
	if (pData == NULL)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString &str)
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(void)
{
	delete[] m_pData;
}

//CMyString& CMyString::operator=(const CMyString& str)
//{
//	if (this == &str) // 判断与当前是否为同一个实例
//		return *this;
//
//	delete[] m_pData; // 释放自身已有的内存
//	m_pData = NULL;
//
//	m_pData = new char[strlen(str.m_pData) + 1]; // 开始赋值
//	strcpy(m_pData, str.m_pData);
//
//	return *this;
//}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str)
	{
		CMyString strTemp(str);
		char* ptemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = ptemp;
	}
	return *this;
}
void CMyString::Print()
{
	cout << m_pData << endl;
}

// 测试用例
int main()
{
	// 普通赋值
	cout << "one to another:" << endl;
	char *str = "Good Boy!";
	CMyString str1(str);
	CMyString str2;
	str2 = str1;
	str2.Print();
	// 赋值给自己
	cout << "one to itself:" << endl;
	str1 = str1;
	str1.Print();
	// 连续赋值
	cout << "Continuous:" << endl;
	CMyString str3;
	str3 = str2 = str1;
	str2.Print();
	str3.Print();
	return 0;
}

#endif // AssignmentOperator