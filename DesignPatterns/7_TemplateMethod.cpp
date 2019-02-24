//#define _TemplateMethod_
#ifdef _TemplateMethod_
// 模板方法模式
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class AbstractClass
{
public:
	void Show()
	{
		cout << "我是" << GetName() << endl;
	}
protected:
	virtual string GetName() = 0;
};
class Naruto : public AbstractClass
{
protected:
	virtual string GetName()
	{
		return "火影史上最帅的六代目--一鸣惊人 Naruto";
	}
};
class OnePice : public AbstractClass
{
protected:
	virtual string GetName()
	{
		return "我是无恶不作的大海贼--路飞";
	}
};
//客户端
int main()
{
	Naruto* man = new Naruto();
	man->Show();
	OnePice* man2 = new OnePice();
	man2->Show();
		
    return 0;
}
#endif // _TemplateMethod_
