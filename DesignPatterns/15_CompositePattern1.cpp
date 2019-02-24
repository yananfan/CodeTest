//#define _CompositePattern1_
#ifdef _CompositePattern1_

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Company
{
protected:
	string m_strName;
public:
	Company(string strname) {
		m_strName = strname;
	}
	virtual void Add(Company* c) = 0;
	virtual void Display(int nDepth) = 0;
	virtual void LineOfDuty() = 0;
};
class ConcreteCompany :public Company
{
private:
	vector<Company*> m_company;
public:
	ConcreteCompany(string strname) :Company(strname) {}
	virtual void Add(Company* c) {
		m_company.push_back(c);
	}
	virtual void Display(int nDepth) {
		string strtemp;
		for (int i = 0;i < nDepth;i++) {
			strtemp += '-';
		}
		strtemp += m_strName;
		cout << strtemp << endl;
		vector<Company*>::iterator p = m_company.begin();
		while (p != m_company.end()) {
			(*p)->Display(nDepth + 2);
			p++;
		}
	}
	virtual void LineOfDuty() {
		vector<Company*>::iterator p = m_company.begin();
		while (p != m_company.end()) {
			(*p)->LineOfDuty();
			p++;
		}
	}
};
class HrDepartment :public Company
{
public:
	HrDepartment(string strname) :Company(strname) {}
	virtual void Add(Company* c) {
		cout << "error." << endl;
	}
	virtual void Display(int nDepth) {
		string strtemp;
		for (int i = 0;i < nDepth;i++) {
			strtemp += '-';
		}
		strtemp += m_strName;
		cout << strtemp << endl;
	}
	virtual void LineOfDuty() {
		cout << m_strName << "招聘人才" << endl;
	}
};

int main()
{
	ConcreteCompany* p = new ConcreteCompany("清华大学");
	p->Add(new HrDepartment("清华大学人才部"));

	ConcreteCompany* p1 = new ConcreteCompany("数学系");
	p1->Add(new HrDepartment("数学系人才部"));

	ConcreteCompany* p2 = new ConcreteCompany("物理系");
	p2->Add(new HrDepartment("物理系人才部"));

	p->Add(p1);
	p->Add(p2);

	p->Display(1);
	p->LineOfDuty();
	return 0;
}

#endif // _CompositePattern1_
