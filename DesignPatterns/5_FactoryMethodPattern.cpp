//#define _FactoryMethodPattern_
#ifdef _FactoryMethodPattern_
// 工厂方法模式
#include <string>
#include <iostream>
using namespace std;
//实例基类，相当于 Product(为了方便，没用抽象)
class LeiFeng
{
public:virtual void Sweep()
{
	cout << "雷锋扫地" << endl;
}
};
//学雷锋的大学生，相当于 ConcreteProduct
class Student : public LeiFeng
{
public:
	virtual void Sweep()
	{
		cout << "大学生扫地" << endl;
	}
};
//学雷锋的志愿者，相当于 ConcreteProduct
class Volenter : public LeiFeng
{
public:
	virtual void Sweep()
	{
		cout << "志愿者" << endl;
	}
};
//工场基类 Creator
class LeiFengFactory
{
public:
	virtual LeiFeng* CreateLeiFeng()
	{
		return new LeiFeng();
	}
};
//工场具体类
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
//客户端
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