//#define _GreatestSumOfSubarrays_
#ifdef _GreatestSumOfSubarrays_

#include<iostream>
using namespace std;

bool g_InvalidInput = false;
int FindGreatestSumOfSubArray(int *pData, int nLength);// ȫ�Ǹ���ʱ������0
int FindGreatestSumOfSubArray_2(int *pData, int nLength);// ȫ�Ǹ���ʱ�����ص�һ��ֵ
int main()
{
	//int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int data[] = { -2, -8, -1, -5, -9 };
	//int data[] = { 2, 8, 1, 5, 9 };

	int length = sizeof(data) / sizeof(int);
	int sum1 = FindGreatestSumOfSubArray(data, length);
	int sum2 = FindGreatestSumOfSubArray_2(data, length);

	return 0;
}
int FindGreatestSumOfSubArray(int *pData, int nLength) {
	if (pData == NULL || nLength <= 0) {
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;
	int sum = 0;
	int maxsum = 0;
	int jstart = 0, jend = 0;
	cout << "ԭʼ����Ϊ��" << endl;
	for (int i = 0;i < nLength;i++) {
		cout << pData[i] << " ";
		if (sum <= 0) {
			sum = pData[i];
			jstart = i;
		}			
		else
			sum += pData[i];
		if (sum > maxsum) {
			maxsum = sum;
			jend = i;
		}
	}

	cout << endl << "���͵�������Ϊ��" << endl;
	for (int i = jstart;i <= jend;i++)
		cout << pData[i] << " ";
	cout << endl;
	cout << "����Ϊ��" << maxsum << endl;
	return maxsum;
}

int FindGreatestSumOfSubArray_2(int *pData, int nLength) {
	if (pData == NULL || nLength <= 0) {
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;
	int sum = 0;
	int maxsum = pData[0]; // ȫ�Ǹ���ʱ�����ص�һ��ֵ�������ֵ
	int jstart = 0, jend = 0;
	cout << "ԭʼ����Ϊ��" << endl;
	for (int i = 0;i < nLength;i++) {
		cout << pData[i] << " ";
		if (sum >= 0) 
			sum += pData[i];			
		else {
			sum = pData[i];
			jstart = i;
		}
		if ((sum > maxsum) && (sum >= 0)) {
			maxsum = sum;
			jend = i;
		}
	}

	cout << endl << "���͵�������Ϊ��" << endl;
	for (int i = jstart;i <= jend;i++)
		cout << pData[i] << " ";
	cout << endl;
	cout << "����Ϊ��" << maxsum << endl;
	return maxsum;
}

#endif // _GreatestSumOfSubarrays_
