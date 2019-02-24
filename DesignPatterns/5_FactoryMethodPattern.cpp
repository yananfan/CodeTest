//#define _FactoryMethodPattern_
#ifdef _FactoryMethodPattern_
// ��������ģʽ
#include <string>
#include <iostream>
using namespace std;
//ʵ�����࣬�൱�� Product(Ϊ�˷��㣬û�ó���)
class LeiFeng
{
public:virtual void Sweep()
{
	cout << "�׷�ɨ��" << endl;
}
};
//ѧ�׷�Ĵ�ѧ�����൱�� ConcreteProduct
class Student : public LeiFeng
{
public:
	virtual void Sweep()
	{
		cout << "��ѧ��ɨ��" << endl;
	}
};
//ѧ�׷��־Ը�ߣ��൱�� ConcreteProduct
class Volenter : public LeiFeng
{
public:
	virtual void Sweep()
	{
		cout << "־Ը��" << endl;
	}
};
//�������� Creator
class LeiFengFactory
{
public:
	virtual LeiFeng* CreateLeiFeng()
	{
		return new LeiFeng();
	}
};
//����������
class StudentFactory : public LeiFengFactory
{
public:
	virtual LeiFeng* CreateLeiFeng()
	{
		return new Student();
	}
};
class VolenterFactory : public LeiFengFactory {
public:
	virtual LeiFeng* CreateLeiFeng()
	{
		return new Volenter();
	}
};
//�ͻ���
int main()
{
	LeiFengFactory *lf = new LeiFengFactory();
	LeiFeng* l = lf->CreateLeiFeng();
	l->Sweep();
	LeiFeng* l2 = lf->CreateLeiFeng();
	l2->Sweep();

	StudentFactory* sf = new StudentFactory();
	LeiFeng* s = sf->CreateLeiFeng();
	s->Sweep();

	VolenterFactory* vf = new VolenterFactory();
	LeiFeng* v = vf->CreateLeiFeng();
	v->Sweep();

	delete s;
	delete sf;

	return 0;
}
#endif // _FactoryMethodPattern_