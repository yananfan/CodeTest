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
//	if (this == &str) // �ж��뵱ǰ�Ƿ�Ϊͬһ��ʵ��
//		return *this;
//
//	delete[] m_pData; // �ͷ��������е��ڴ�
//	m_pData = NULL;
//
//	m_pData = new char[strlen(str.m_pData) + 1]; // ��ʼ��ֵ
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

// ��������
int main()
{
	// ��ͨ��ֵ
	cout << "one to another:" << endl;
	char *str = "Good Boy!";
	CMyString str1(str);
	CMyString str2;
	str2 = str1;
	str2.Print();
	// ��ֵ���Լ�
	cout << "one to itself:" << endl;
	str1 = str1;
	str1.Print();
	// ������ֵ
	cout << "Continuous:" << endl;
	CMyString str3;
	str3 = str2 = str1;
	str2.Print();
	str3.Print();
	return 0;
}

#endif // AssignmentOperator