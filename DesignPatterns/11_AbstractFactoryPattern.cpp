//#define _AbstractFactoryPattern_
#ifdef _AbstractFactoryPattern_

#include<iostream>
#include<string>

using namespace std;

class AUser
{
public:
	virtual void GetUser() = 0;
	virtual void InsertUser() = 0;
};
class ADepartment
{
public:
	virtual void GetDepartment() = 0;
	virtual void InsertDepartment() = 0;
};
class RAccessUser :public AUser
{
public:
	virtual void GetUser() {
		cout << "access getuser." << endl;
	}
	virtual void InsertUser() {
		cout << "access insertuser." << endl;
	}
};
class RAccessDepartment :public ADepartment
{
public:
	virtual void GetDepartment() {
		cout << "access getDepartment." << endl;
	}
	virtual void InsertDepartment() {
		cout << "access insertDepartment." << endl;
	}
};
class RSqlUser :public AUser
{
public:
	virtual void GetUser() {
		cout << "Sql getuser." << endl;
	}
	virtual void InsertUser() {
		cout << "Sql insertuser." << endl;
	}
};
class RSqlDepartment :public ADepartment
{
public:
	virtual void GetDepartment() {
		cout << "Sql getDepartment." << endl;
	}
	virtual void InsertDepartment() {
		cout << "Sql insertDepartment." << endl;
	}
};
class AFactory
{
public:
	virtual AUser* CreatUser() = 0;
	virtual ADepartment* CreatDepartment() = 0;
};
class AccessFactory :public AFactory
{
public:
	virtual AUser* CreatUser() {
		return new RAccessUser();
	}
	virtual ADepartment* CreatDepartment() {
		return new RAccessDepartment();
	}
};
class SqlFactory :public AFactory
{
public:
	virtual AUser* CreatUser() {
		return new RSqlUser();
	}
	virtual ADepartment* CreatDepartment() {
		return new RSqlDepartment();
	}
};

int main()
{
	AFactory* factory = new SqlFactory();
	AUser* user = factory->CreatUser();
	ADepartment* depart = factory->CreatDepartment();
	user->GetUser();
	depart->GetDepartment();
	return 0;
}

#endif // _AbstractFactoryPattern_
