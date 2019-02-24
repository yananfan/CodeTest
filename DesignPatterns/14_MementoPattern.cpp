//#define _MementoPattern_
#ifdef _MementoPattern_

#include<iostream>
#include<string>

using namespace std;

class Memo;
class Originator
{
public:
	string state;
	Memo* CreateMemo();
	void SetMemo(Memo* memo);
	void Show() {
		cout << "state: " << state << endl;
	}
};
class Memo
{
public:
	string state;
	Memo(string strstate) {
		state = strstate;
	}
};
Memo* Originator::CreateMemo() {
	return new Memo(state);
}
void Originator::SetMemo(Memo* memo) {
	state = memo->state;
}
class Carctaker
{
public:
	Memo* memo;
};

int main()
{
	Originator* on = new Originator();
	on->state = "on";
	on->Show();

	Carctaker* ca = new Carctaker();
	ca->memo = on->CreateMemo();

	on->state = "off";
	on->Show();

	on->SetMemo(ca->memo);
	on->Show();
	return 0;
}

#endif // _MementoPattern_
