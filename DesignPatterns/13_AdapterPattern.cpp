//#define _AdapterPattern_
#ifdef _AdapterPattern_

#include<iostream>

using namespace std;

class Target
{
public:
	virtual void Request() {
		cout << "simple request." << endl;
	}
};
class Adaptee
{
public:
	void SpecialRequest() {
		cout << "special request." << endl;
	}
};
class Adapter :public Target
{
private:
	Adaptee* ada;
public:
	virtual void Request() {
		ada->SpecialRequest();
		Target::Request();
	}
	Adapter() {
		ada = new Adaptee();
	}
	~Adapter()
	{
		delete ada;
	}
};

int main()
{
	Adapter* ada = new Adapter();
	ada->Request();
	delete ada;
	return 0;
}

#endif // _AdapterPattern_
