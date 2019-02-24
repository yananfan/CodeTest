//#define _StrategyPattern_
#ifdef _StrategyPattern_

#include<iostream>

using namespace std;

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
	AddOperation(int a, int b) {
		m_FirstNum = a;
		m_SecondNum = b;
	}
	virtual double GetResult() {
		return m_FirstNum + m_SecondNum;
	}
};
class Context
{
public:
	Context(COperation* temp) {
		op = temp;
	}
	double GetResult() {
		return op->GetResult();
	}

private:
	COperation* op;
};

int main()
{
	int a, b;
	cin >> a >> b;
	char c;
	cin >> c;
	switch (c)
	{
	case '+':
		Context* con = new Context(new AddOperation(a, b));
		cout << con->GetResult() << endl;
		break;
	default:
		//Context* con = new Context(new AddOperation(3,8));
		break;
	}
	return 0;
}

#endif // _StrategyPattern_
