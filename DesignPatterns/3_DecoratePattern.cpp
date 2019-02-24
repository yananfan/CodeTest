//#define _DecoratePattern_
#ifdef _DecoratePattern_

#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(string strName) {
		m_strName = strName;
	}
	Person(){}
	virtual void Show() {
		cout << "装饰的是：" << m_strName << endl;
	}
private:
	string m_strName;
};
class Finery :public Person
{
protected:
	Person* m_comp;
public:
	void Decorate(Person* comp) {
		m_comp = comp;
	}
	virtual void Show() {
		m_comp->Show();
	}
};
class TShirts :public Finery
{
public:
	virtual void Show() {
		cout << "T Shirts." << endl;
		m_comp->Show();
	}
};
class BigTrouser :public Finery
{
public:
	virtual void Show() {
		cout << "Big Trouser." << endl;
		m_comp->Show();
	}
};
int main()
{
	Person* p = new Person("小李");
	BigTrouser* bt = new BigTrouser();
	TShirts* ts = new TShirts();

	bt->Decorate(p);
	ts->Decorate(bt);
	ts->Show();

	return 0;
}

#endif // _DecoratePattern_
