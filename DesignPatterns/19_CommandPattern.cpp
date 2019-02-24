//#define _CommandPattern_
#ifdef _CommandPattern_

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Barbucer
{
public:
	void MakeMutton() {
		cout << "make mutton." << endl;
	}
	void MakeChicken() {
		cout << "make chicken." << endl;
	}
};
class Command
{
protected:
	Barbucer* receiver;
public:
	Command(Barbucer* temp) {
		receiver = temp;
	}
	virtual void ExecuteCmd() = 0;
};
class BakeMuttonCmd :public Command
{
public:
	BakeMuttonCmd(Barbucer* temp) :Command(temp) {}
	virtual void ExecuteCmd() {
		receiver->MakeMutton();
	}
};
class BakeChickenCmd :public Command
{
public:
	BakeChickenCmd(Barbucer* temp) :Command(temp) {}
	virtual void ExecuteCmd() {
		receiver->MakeChicken();
	}
};
class Waiter
{
protected:
	vector<Command*> m_cmdlist;
public:
	void SetCmd(Command* temp) {
		m_cmdlist.push_back(temp);
		cout << "add lists." << endl;
	}
	void Notify() {
		vector<Command*>::iterator p = m_cmdlist.begin();
		while (p != m_cmdlist.end()) {
			(*p)->ExecuteCmd();
			p++;
		}
	}
};

int main()
{
	Barbucer* barbucer = new Barbucer();
	Command* cmd1 = new BakeMuttonCmd(barbucer);
	Command* cmd2 = new BakeChickenCmd(barbucer);
	Waiter* girl = new Waiter();
	girl->SetCmd(cmd1);
	girl->SetCmd(cmd2);
	girl->Notify();
	return 0;
}

#endif // _CommandPattern_
