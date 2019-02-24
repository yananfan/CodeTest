//#define _TemplateMethod_
#ifdef _TemplateMethod_
// ģ�巽��ģʽ
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class AbstractClass
{
public:
	void Show()
	{
		cout << "����" << GetName() << endl;
	}
protected:
	virtual string GetName() = 0;
};
class Naruto : public AbstractClass
{
protected:
	virtual string GetName()
	{
		return "��Ӱʷ����˧������Ŀ--һ������ Naruto";
	}
};
class OnePice : public AbstractClass
{
protected:
	virtual string GetName()
	{
		return "�����޶����Ĵ���--·��";
	}
};
//�ͻ���
int main()
{
	Naruto* man = new Naruto();
	man->Show();
	OnePice* man2 = new OnePice();
	man2->Show();
		
    return 0;
}
#endif // _TemplateMethod_
