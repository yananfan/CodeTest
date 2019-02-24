//#define _SingletonPattern_
#ifdef _SingletonPattern_

#include<iostream>
#include<string>

using namespace std;

class Singleton
{
private:
	Singleton() {}
	static Singleton* single;
public:
	static Singleton* GetInstance() {
		if (single == NULL)
			single = new Singleton();
		return single;
	}
};
Singleton* Singleton::single = NULL;

int main()
{
	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();
	if (s1 == s2)
		cout << "ok." << endl;
	else
		cout << "no." << endl;
	return 0;
}

#endif // _SingletonPattern_
