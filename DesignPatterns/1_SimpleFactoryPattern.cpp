#define _SimpleFactoryPattern_
#ifdef _SimpleFactoryPattern_
// 简单工厂模式：将一个具体类的实例化交给一个静态工厂方法来执行
#include<iostream>

using namespace std;
// 运算类
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
// 工厂类：只包含了创建具体类的静态方法
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
