#define _SimpleFactoryPattern_
#ifdef _SimpleFactoryPattern_
// �򵥹���ģʽ����һ���������ʵ��������һ����̬����������ִ��
#include<iostream>

using namespace std;
// ������
class COperation {
public:
	int m_FirstNum;
	int m_SecondNum;
	virtual double GetResult() {
		double result = 0;
		return result;
	}
};
class AddOperation :public COperation {
public:
	virtual double GetResult() {
		return m_FirstNum + m_SecondNum;
	}
};
class SubOperation :public COperation {
public:
	virtual double GetResult() {
		return m_FirstNum - m_SecondNum;
	}
};
// �����ֻࣺ�����˴���������ľ�̬����
class CCalFactory {
public:
	static COperation* Creat(char coperator);
};
COperation* CCalFactory::Creat(char coperator) {
	COperation* oper;
	switch (coperator)
	{
	case '+':
		oper = new AddOperation();
		break;
	case '-':
		oper = new SubOperation();
		break;
	default:
		oper = new AddOperation();
		break;
	}
	return oper;
}
int main()
{
	int a, b;
	cin >> a >> b;

	COperation* op = CCalFactory::Creat('-');
	op->m_FirstNum = a;
	op->m_SecondNum = b;
	cout << op->GetResult() << endl;

	COperation* op1 = CCalFactory::Creat(' ');
	op1->m_FirstNum = a;
	op1->m_SecondNum = b;
	cout << op1->GetResult() << endl;
	return 0;
}
#endif // _SimpleFactoryPattern_
