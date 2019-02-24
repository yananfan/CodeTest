//#define _CompositePattern_
#ifdef _CompositePattern_

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Component
{
public:
	string m_strName;
	Component(string strname) {
		m_strName = strname;
	}
	virtual void Add(Component* com) = 0;
	virtual void Display(int nDepth) = 0;
};
class Leaf :public Component
{
public:
	Leaf(string strname) :Component(strname) {}
	virtual void Add(Component* com) {
		cout << "leaf can't add." << endl;
	}
	virtual void Display(int nDepth) {
		string strtemp;
		for (int i = 0;i < nDepth;i++) {
			strtemp += '-';
		}
		strtemp += m_strName;
		cout << strtemp << endl;
	}
};
class Composite :public Component
{
private:
	vector<Component*> m_component;
public:
	Composite(string strname) :Component(strname) {}
	virtual void Add(Component* com) {
		m_component.push_back(com);
	}
	virtual void Display(int nDepth) {
		string strtemp;
		for (int i = 0;i < nDepth;i++) {
			strtemp += '-';
		}
		strtemp += m_strName;
		cout << strtemp << endl;
		vector<Component*>::iterator p = m_component.begin();
		while (p != m_component.end()) {
			(*p)->Display(nDepth + 2);
			p++;
		}
	}
};

int main()
{
	Composite* p = new Composite("Wang");
	p->Add(new Leaf("Li"));
	p->Add(new Leaf("Zhao"));

	Composite* p1 = new Composite("Wu");
	p1->Add(new Leaf("San"));

	p->Add(p1);
	p->Display(1);
	return 0;
}

#endif // _CompositePattern_
