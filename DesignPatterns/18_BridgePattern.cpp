//#define _BridgePattern_
#ifdef _BridgePattern_

#include<iostream>
#include<string>

using namespace std;

class HandsetSoft
{
public:
	virtual void Run() = 0;
};
class HandsetGame :public HandsetSoft
{
public:
	virtual void Run() {
		cout << "run mobile game." << endl;
	}
};
class HandsetAddressList :public HandsetSoft
{
public:
	virtual void Run() {
		cout << "run mobile address list." << endl;
	}
};
class HandsetBrand
{
protected:
	HandsetSoft* m_soft;
public:
	void SetHandsetSoft(HandsetSoft* temp) {
		m_soft = temp;
	}
	virtual void Run() = 0;
};
class HandsetBrandM :public HandsetBrand
{
public:
	virtual void Run() {
		m_soft->Run();
	}
};
class HandsetBrandN :public HandsetBrand
{
public:
	virtual void Run() {
		m_soft->Run();
	}
};
int main()
{
	HandsetBrand* brand = new HandsetBrandM();
	brand->SetHandsetSoft(new HandsetGame());
	brand->Run();
	brand->SetHandsetSoft(new HandsetAddressList());
	brand->Run();
	return 0;
}

#endif // _BridgePattern_
