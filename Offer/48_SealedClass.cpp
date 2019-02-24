//#define _SealedClass_
#ifdef _SealedClass_

#include<iostream>
using namespace std;

class SealedClass1
{
public:
	static SealedClass1* GetInstance() {
		return new SealedClass1();
	}
	static void DeleteInstance(SealedClass1* pInstance) {
		delete pInstance;
	}
private:
	SealedClass1() {}
	~SealedClass1() {}
};
// �̳�ʧ�ܣ��������
// ��SealedClass1::SealedClass1��: �޷����� private ��Ա(�ڡ�SealedClass1����������)
// ��SealedClass1::~SealedClass1��: �޷����� private ��Ա(�ڡ�SealedClass1����������)
class SubClass1 :public SealedClass1
{
public:
	SubClass1() {}
	~SubClass1() {}
};

template<class T>
class MakeSealed
{
	friend T;
private:
	MakeSealed() {}
	~MakeSealed() {}
};
class SealedClass2 :virtual public MakeSealed<SealedClass2>
{
public:
	SealedClass2() {}
	~SealedClass2() {}
};
// �̳�ʧ�ܣ��������
// ��MakeSealed<SealedClass2>::MakeSealed��: �޷����� private ��Ա(�ڡ�MakeSealed<SealedClass2>����������)
// ��MakeSealed<SealedClass2>::~MakeSealed��: �޷����� private ��Ա(�ڡ�MakeSealed<SealedClass2>����������)
class SubClass2 :public SealedClass2
{
public:
	SubClass2() {}
	~SubClass2() {}
};
int main()
{
	return 0;
}
#endif // _SealedClass_