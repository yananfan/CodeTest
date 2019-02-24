//#define _StatePattern_
#ifdef _StatePattern_

#include<iostream>

using namespace std;

class Work;
class ForeniinState;
class NoonState;

class State
{
public:
	virtual void WriteProgram(Work* w) = 0;
};
class Work
{
private:
	State* current;
public:
	double hour;
	Work();
	void SetState(State* temp) {
		current = temp;
	}
	void Writeprogram() {
		current->WriteProgram(this);
	}
};
class NoonState :public State
{
public:
	virtual void WriteProgram(Work* w) {
		cout << "execute" << endl;
		if ((w->hour) < 13)
			cout << "good." << endl;
		else
			cout << "no,go to sleep." << endl;
	}
};
class ForenoonState :public State
{
public:
	virtual void WriteProgram(Work* w) {
		if ((w->hour) < 12)
			cout << "very good." << endl;
		else {
			w->SetState(new NoonState());
			w->Writeprogram();
		}
	}
};
Work::Work() {
	current = new ForenoonState();
}

int main()
{
	Work* mywork = new Work();
	mywork->hour = 9;
	mywork->Writeprogram();

	mywork->hour = 14;
	mywork->Writeprogram();
	return 0;
}

#endif // _StatePattern_
