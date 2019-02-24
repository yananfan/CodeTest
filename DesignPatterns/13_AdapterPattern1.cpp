//#define _AdapterPattern1_
#ifdef _AdapterPattern1_

#include<iostream>
#include<string>
using namespace std;

class Player
{
protected:
	string name;
public:
	Player(string strname) {
		name = strname;
	}
	virtual void Attack() = 0;
	virtual void Defense() = 0;
};
class Forwards :public Player
{
public:
	Forwards(string strname) :Player(strname) {}
	virtual void Attack() {
		cout << name << "forwards attack." << endl;
	}
	virtual void Defense() {
		cout << name << "forwards defense." << endl;
	}
};
class Center :public Player
{
public:
	Center(string strname) :Player(strname) {}
	virtual void Attack() {
		cout << name << "Center attack." << endl;
	}
	virtual void Defense() {
		cout << name << "Center defense." << endl;
	}
};
class Translater :public Player
{
private:
	Center* player;
public:
	Translater(string strname) :Player(strname) {
		player = new Center(strname);
	}
	virtual void Attack() {
		player->Attack();
	}
	virtual void Defense() {
		player->Defense();
	}
};

int main()
{
	Player* p = new Translater("Li ");
	p->Attack();
	return 0;
}

#endif // _AdapterPattern1_
