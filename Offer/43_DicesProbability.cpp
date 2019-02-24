//#define _DicesProbability_
#ifdef _DicesProbability_

#include<iostream>
using namespace std;

int g_maxValue = 6;
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);
void PrintProbability_1(int number);

void PrintProbability_2(int number);
int main()
{
	PrintProbability_1(1);
	PrintProbability_1(2);

	PrintProbability_2(1);
	PrintProbability_2(2);
	return 0;
}
void Probability(int number, int* pProbabilities) {
	for (int i = 1;i <= g_maxValue;i++)
		Probability(number, number, i, pProbabilities);
}
void Probability(int original, int current, int sum, int* pProbabilities) {
	if (current == 1)
		pProbabilities[sum - original]++;
	else {
		for (int i = 1;i <= g_maxValue;i++)
			Probability(original, current - 1, sum + i, pProbabilities);
	}
}
void PrintProbability_1(int number) {
	if (number < 1)
		return;
	cout << number << " 个骰子：" << endl;
	int maxsum = g_maxValue*number;
	int* pPro = new int[maxsum - number + 1];
	for (int i = number;i <= maxsum;i++)
		pPro[i - number] = 0;
	Probability(number, pPro);
	int total = pow(g_maxValue, number);
	for (int i = number;i <= maxsum;i++) {
		double ratio = (double)pPro[i - number] / total;
		cout << i << " " << ratio << endl;
	}
	delete[] pPro;
}

void PrintProbability_2(int number) {
	if (number < 1)
		return;
	cout << number << " 个骰子：" << endl;
	int* pPro[2];
	pPro[0] = new int[g_maxValue*number + 1];
	pPro[1] = new int[g_maxValue*number + 1];
	for (int i = 0;i < g_maxValue*number + 1;i++) {
		pPro[0][i] = 0;
		pPro[1][i] = 0;
	}
	int flag = 0;
	for (int i = 1;i <= g_maxValue;i++)
		pPro[flag][i] = 1;
	for (int k = 2;k <= number;k++) {
		for (int i = 0;i < k;i++)
			pPro[1 - flag][i] = 0;
		for (int i = k;i <= g_maxValue * k;i++) {
			pPro[1 - flag][i] = 0;
			for (int j = 1;j <= i&&j <= g_maxValue;j++)
				pPro[1 - flag][i] += pPro[flag][i - j];
		}
		flag = 1 - flag;
	}
	double total = pow(g_maxValue, number);
	for (int i = number;i <= g_maxValue*number;i++) {
		double ratio = (double)pPro[flag][i] / total;
		cout << i << " " << ratio << endl;
	}
	delete[] pPro[0];
	delete[] pPro[1];
}
#endif // _DicesProbability_