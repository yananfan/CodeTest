//#define _ObserverPattern1_
#ifdef _ObserverPattern1_

#include<iostream>
#include<string>
#include<vector>

using namespace std;
class SecretaryBase;

class ObserverBase
{
protected:
	string name;
	SecretaryBase* sub;
public:
	ObserverBase(string strname, SecretaryBase* strsub) {
		name = strname;
		sub = strsub;
	}
	virtual void Update() = 0;
};
class StockObserver :public ObserverBase
{
public:
	StockObserver(string strname, SecretaryBase* strsub) :ObserverBase(strname, strsub) {}
	virtual void Update();
};
class NBAObserver :public ObserverBase
{
public:
	NBAObserver(string strname, SecretaryBase* strsub) :ObserverBase(strname, strsub) {}
	virtual void Update();
};

class SecretaryBase
{
public:
	string action;
	vector<ObserverBase*> observers;
	virtual void Attach(ObserverBase* observer) = 0;
	virtual void Notify() = 0;
};
class Secretary :public SecretaryBase
{
public:
	void Attach(ObserverBase* observer) {
		observers.push_back(observer);
	}
	void Notify() {
		vector<ObserverBase*>::iterator p = observers.begin();
		while (p != observers.end()) {
			(*p)->Update();
			p++;
		}
	}
};
void StockObserver::Update() {
	cout << name << ":" << sub->action << ",don't play with the stock, please start working." << endl;
}
void NBAObserver::Update() {
	cout << name << ":" << sub->action << ",don't watch NBA, please start working." << endl;
}
int main()
{
	SecretaryBase* p = new Secretary();
	ObserverBase* s1 = new NBAObserver("Li", p);
	ObserverBase* s2 = new StockObserver("Zhao", p);
	p->Attach(s1);
	p->Attach(s2);
	p->action = "boss is coming";
	p->Notify();
	return 0;
}

#endif // _ObserverPattern1_
