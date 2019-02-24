//#define _StackPushPopOrder_
#ifdef _StackPushPopOrder_

#include<iostream>
#include<stack>

using namespace std;
bool IsPopOrder(const int* pPush, const int* pPop, int nLength); // 形参分别表示压入序列，弹出序列，序列长度
int main()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 5, 3, 2, 1 };
	//int pop[nLength] = { 4, 5, 3, 2, 1 };

	IsPopOrder(push, pop, nLength);

	return 0;
}
bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
	bool result = false;
	if (pPush != NULL && pPop != NULL && nLength > 0) {
		const int* p1 = pPush;
		const int* p2 = pPop;
		stack<int> stack;
		while (p2 - pPop < nLength)
		{
			while (stack.empty() || *p2 != stack.top()) {
				if (p1 - pPush == nLength)
					break;
				stack.push(*p1);
				p1++;
			}
			if (stack.top() != *p2)
				break;
			stack.pop();
			p2++;
		}
		if (stack.empty() && p2 - pPop == nLength)
			result = true;
	}
	cout << "result ( 1 for true,0 for false ) = " << result << endl;
	return result;
}
#endif // _StackPushPopOrder_