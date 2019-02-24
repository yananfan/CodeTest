//#define _ObserverPattern_
#ifdef _ObserverPattern_

#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Secretary;
class StockObserver
{
private:
	string name;
	Secretary* sub;
public:
	StockObserver(string strname, Secretary* strsub) {
		name = strname;
		sub = strsub;
	}
	void Update();
};
class Secretary
{
private:
	vector<StockObserver> observers;
public:
	string action;
	void Add(StockObserver obs) {
		observers.push_back(obs);
	}
	void Notify() {
		vector<StockObserver>::iterator p = observers.begin();
		while (p != observers.end()) {
			(*p).Update();
			p++;
		}
	}
};
void StockObserver::Update() {
	cout << name << ":" << sub->action << ",don't play with the stock, please start working." << endl;
}
int main()
{
	Secretary* p = new Secretary();
	StockObserver* s1 = new StockObserver("Li", p);
	StockObserver* s2 = new StockObserver("Zhao", p);
	p->Add(*s1);
	p->Add(*s2);
	p->action = "boss is coming";
	p->Notify();

	return 0;
}

#endif // _ObserverPattern_
