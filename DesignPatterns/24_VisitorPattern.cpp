//#define _VisitorPattern_
#ifdef _VisitorPattern_
//访问者模式
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Man;
class Woman;
class Action
{
public:
	virtual void GetManConclusion(Man* concreteEleA) = 0;
	virtual void GetWomanConclusion(Woman* concreteEleB) = 0;
};
class Success :public Action
{
public:
	virtual void GetManConclusion(Man* concreteEleA) {
		cout << "man success, great woman." << endl;
	}
	virtual void GetWomanConclusion(Woman* concreteEleB) {
		cout << "woman success,fool man." << endl;
	}
};
class Failure :public Action
{
public:
	virtual void GetManConclusion(Man* concreteEleA) {
		cout << "man failure, great woman." << endl;
	}
	virtual void GetWomanConclusion(Woman* concreteEleB) {
		cout << "woman failure,fool man." << endl;
	}
};
class Person
{
public:
	virtual void Accept(Action* visitor) = 0;
};
class Man :public Person
{
public:
	virtual void Accept(Action* visitor) {
		visitor->GetManConclusion(this);
	}
};
class Woman :public Person
{
public:
	virtual void Accept(Action* visitor) {
		visitor->GetWomanConclusion(this);
	}
};
class ObjectStructure
{
private:
	vector<Person*> m_personList;
public:
	void Add(Person* p) {
		m_personList.push_back(p);
	}
	void Dislay(Action* a) {
		vector<Person*>::iterator p = m_personList.begin();
		while (p != m_personList.end()) {
			(*p)->Accept(a);
			p++;
		}
	}
};

int main()
{
	ObjectStructure* os = new ObjectStructure();
	os->Add(new Man());
	os->Add(new Woman());
	Success* success = new Success();
	os->Dislay(success);
	Failure* failure = new Failure();
	os->Dislay(failure);
	return 0;
}

#endif // _VisitorPattern_
