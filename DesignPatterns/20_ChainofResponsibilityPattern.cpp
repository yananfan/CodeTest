//#define _ChainofResponsibilityPattern_
#ifdef _ChainofResponsibilityPattern_

#include<iostream>
#include<string>

using namespace std;

class Request
{
public:
	string m_strName;
	int m_nNum;
};
class Manager
{
protected:
	Manager* manager;
	string name;
public:
	Manager(string temp) {
		name = temp;
	}
	void SetSuccessor(Manager* temp) {
		manager = temp;
	}
	virtual void GetRequest(Request* request) = 0;
};
class CommonManager :public Manager
{
public:
	CommonManager(string strtemp) :Manager(strtemp) {}
	virtual void GetRequest(Request* request) {
		if (request->m_nNum >= 0 && request->m_nNum < 10)
			cout << name << " deals with " << request->m_nNum << " requests." << endl;
		else
			manager->GetRequest(request);
	}
};
class MajorDomo :public Manager
{
public:
	MajorDomo(string name) :Manager(name) {}
	virtual void GetRequest(Request* request) {
		if (request->m_nNum >= 10)
			cout << name << " deals with " << request->m_nNum << " requests." << endl;
	}
};

int main()
{
	Manager* common = new CommonManager("Common Zhang");
	Manager* major = new MajorDomo("Major Li");
	common->SetSuccessor(major);
	Request* req = new Request();
	req->m_nNum = 33;
	common->GetRequest(req);

	req->m_nNum = 3;
	common->GetRequest(req);
	return 0;
}

#endif // _ChainofResponsibilityPattern_
