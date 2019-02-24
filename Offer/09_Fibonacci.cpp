//#define _Fibonacci_
#ifdef _Fibonacci_

#include<iostream>

using namespace std;

long long Fibonacci_recur(unsigned int n);
long long Fibonacci_cycle(unsigned int n);

int main()
{
	long long test11 = Fibonacci_recur(3), test12 = Fibonacci_cycle(3);
	cout << "F(3)=" << test11 << "  " << test12 << endl;
	test11 = Fibonacci_recur(5);
	test12 = Fibonacci_cycle(5);
	cout << "F(5)=" << test11 << "  " << test12 << endl;
	test11 = Fibonacci_recur(10);
	test12 = Fibonacci_cycle(10);
	cout << "F(10)=" << test11 << "  " << test12 << endl;

	test11 = Fibonacci_recur(0);
	test12 = Fibonacci_cycle(0);
	cout << "F(0)=" << test11 << "  " << test12 << endl;
	test11 = Fibonacci_recur(1);
	test12 = Fibonacci_cycle(1);
	cout << "F(1)=" << test11 << "  " << test12 << endl;
	test11 = Fibonacci_recur(2);
	test12 = Fibonacci_cycle(2);
	cout << "F(2)=" << test11 << "  " << test12 << endl;

	test11 = Fibonacci_recur(40);
	test12 = Fibonacci_cycle(40);
	cout << "F(40)=" << test11 << "  " << test12 << endl;
	test11 = Fibonacci_recur(50);
	test12 = Fibonacci_cycle(50);
	cout << "F(50)=" << test11 << "  " << test12 << endl;
	test11 = Fibonacci_recur(100);
	test12 = Fibonacci_cycle(100);
	cout << "F(100)=" << test11 << "  " << test12 << endl;

	return 0;
}
long long Fibonacci_recur(unsigned int n) {
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	else
		return Fibonacci_recur(n - 1) + Fibonacci_recur(n - 2);
}
long long Fibonacci_cycle(unsigned int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	long long fn_1 = 1, fn_2 = 0, fn = 0;
	for (unsigned int i = 2;i <= n;i++) {
		fn = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
	}
	return fn;
}
#endif // _Fibonacci_