//#define _ProxyPattern_
#ifdef _ProxyPattern_

#include<iostream>
#include<string>

using namespace std;

class Interface
{
public:
	virtual void Request() = 0;
};
class RealClass :public Interface
{
public:
	virtual void Request() {
		cout << "real request." << endl;
	}
};
class ProxyClass :public Interface
{
private:
	RealClass* m_real;
public:
	virtual void Request() {
		m_real = new RealClass();
		m_real->Request();
		delete m_real;
	}
};

int main()
{
	ProxyClass* test = new ProxyClass();
	test->Request();
	return 0;
}

#endif // _ProxyPattern_
