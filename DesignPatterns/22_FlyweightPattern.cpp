//#define _FlyweightPattern_
#ifdef _FlyweightPattern_

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class WebSite
{
public:
	virtual void Use() = 0;
};
class ConcreteWebSite :public WebSite
{
private:
	string name;
public:
	ConcreteWebSite(string strname) {
		name = strname;
	}
	virtual void Use() {
		cout << "website class : " << name << endl;
	}
};
class UnShareWebSite :public WebSite
{
private:
	string name;
public:
	UnShareWebSite(string strname) {
		name = strname;
	}
	virtual void Use() {
		cout << "unshare website : " << name << endl;
	}
};
class WebFactory
{
private:
	vector<WebSite*> websites;
public:
	WebSite* GetWeb() {
		vector<WebSite*>::iterator p = websites.begin();
		return *p;
	}
	WebFactory() {
		websites.push_back(new ConcreteWebSite("test"));
	}
};

int main()
{
	WebFactory* f = new WebFactory();
	WebSite* ws1 = f->GetWeb();
	ws1->Use();
	WebSite* ws2 = f->GetWeb();
	ws2->Use();
	WebSite* ws3 = new UnShareWebSite("test");
	ws3->Use();
	return 0;
}

#endif // _FlyweightPattern_
