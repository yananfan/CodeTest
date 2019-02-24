//#define _FacadePattern_
#ifdef _FacadePattern_

#include<iostream>
#include<string>
using namespace std;

class SubSys1
{
public:
	void MethodOne() {
		cout << "method 1." << endl;
	}
};
class SubSys2
{
public:
	void MethodTwo() {
		cout << "method 2." << endl;
	}
};
class SubSys3
{
public:
	void MethodThree() {
		cout << "method 3." << endl;
	}
};
class Facade
{
private:
	SubSys1* sub1;
	SubSys2* sub2;
	SubSys3* sub3;
public:
	Facade() {
		sub1 = new SubSys1();
		sub2 = new SubSys2();
		sub3 = new SubSys3();
	}
	~Facade()
	{
		delete sub1;
		delete sub2;
		delete sub3;
	}
	void FacadeMethod() {
		sub1->MethodOne();
		sub2->MethodTwo();
		sub3->MethodThree();
	}
};
int main()
{
	Facade* test = new Facade();
	test->FacadeMethod();
	return 0;
}

#endif // _FacadePattern_
