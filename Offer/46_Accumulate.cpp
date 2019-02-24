//#define _Accumulate_
#ifdef _Accumulate_

#include<iostream>
using namespace std;
// 1.构造函数
class SumClass;
int Sum_1(int n);
// 2.虚函数
class A;
A* Array[2];
int Sum_2(int n);
// 3.函数指针

// 4.模板类型

int main()
{

	return 0;
}

class SumClass
{
public:
	SumClass() { N++;Sum += N; }
	~SumClass() {}
	static void Reset() { N = 0;Sum = 0; }
	static int GetSum() { return Sum; }
private:
	static int N;
	static int Sum;
};
int SumClass::N = 0;
int SumClass::Sum = 0;
int Sum_1(int n) {
	SumClass::Reset();
	SumClass* p = new SumClass[n];
	delete[] p;
	p = NULL;
	return SumClass::GetSum();
}

class A
{
public:
	virtual int Sum(int n) {
		return 0;
	}
};
class B :public A 
{
public:
	virtual int Sum(int n) {
		return Array[!!n]->Sum(n - 1) + n;
	}
};
int Sum_2(int n) {
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int value = Array[1]->Sum(n);
	return value;
}
#endif // _Accumulate_