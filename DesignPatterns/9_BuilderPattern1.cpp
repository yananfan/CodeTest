//#define _BuilderPattern1_
#ifdef _BuilderPattern1_

#include<iostream>
#include<string>

using namespace std;

class Person
{
public:
	virtual void CreateHead() = 0;
	virtual void CreateHand() = 0;
	virtual void CreateBody() = 0;
	virtual void CreateFoot() = 0;
};
class ThinPerson :public Person
{
public:
	virtual void CreateHead() {
		cout << "thin head." << endl;
	}
	virtual void CreateHand() {
		cout << "thin hand." << endl;
	}
	virtual void CreateBody() {
		cout << "thin body." << endl;
	}
	virtual void CreateFoot() {
		cout << "thin foot." << endl;
	}
};
class ThickPerson :public Person
{
public:
	virtual void CreateHead() {
		cout << "Thick head." << endl;
	}
	virtual void CreateHand() {
		cout << "Thick hand." << endl;
	}
	virtual void CreateBody() {
		cout << "Thick body." << endl;
	}
	virtual void CreateFoot() {
		cout << "Thick foot." << endl;
	}
};
class Direct
{
private:
	Person* p;
public:
	Direct(Person* temp) {
		p = temp;
	}
	void Create() {
		p->CreateHead();
		p->CreateBody();
		p->CreateHand();
		p->CreateFoot();
	}
};
int main()
{
	Person* p = new ThickPerson();
	Direct* d = new Direct(p);
	d->Create();
	delete d;
	delete p;
	return 0;
}

#endif // _BuilderPattern1_
