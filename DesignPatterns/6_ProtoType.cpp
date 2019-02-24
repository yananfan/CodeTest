//#define _ProtoType
#ifdef _ProtoType
// ԭ��ģʽ
#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Prototype //�������
{
private:
	string m_strName;
public:
	Prototype(string strName) { m_strName = strName; }
	Prototype() { m_strName = " "; }
	void Show()
	{
		cout << m_strName << endl;
	}
	virtual Prototype* Clone() = 0 ;
} ;
// class ConcretePrototype1
class ConcretePrototype1 : public Prototype
{
public:
	ConcretePrototype1(string strName) : Prototype(strName) {}
	ConcretePrototype1() {}
	virtual Prototype* Clone()
	{
		ConcretePrototype1 *p = new ConcretePrototype1();
		*p = *this; //���ƶ���
		return p;
	}
};
	
// class ConcretePrototype2
class ConcretePrototype2 : public Prototype
{
public:
	ConcretePrototype2(string strName) : Prototype(strName) {}
	ConcretePrototype2() {}
	virtual Prototype* Clone()
	{
		ConcretePrototype2 *p = new ConcretePrototype2();
		*p = *this; //���ƶ���
		return p;
	}
};//�ͻ���
int main()
{
	ConcretePrototype1* test = new ConcretePrototype1("С��");
	ConcretePrototype2* test2 = (ConcretePrototype2*)test->Clone();
	test->Show();
	test2->Show();
	
	return 0;
}

#endif // _ProtoType