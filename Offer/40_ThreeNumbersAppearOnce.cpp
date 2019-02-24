//#define _ThreeNumbersAppearOnce_
#ifdef _ThreeNumbersAppearOnce_

#include<iostream>
#include<vector>
using namespace std;

vector<int> do_zero(vector<int>& nums);
vector<int> singleNumber(vector<int>& nums);
int main()
{
	int length = 7;
	int elem;
	vector<int> data;
	cout << "输入 " << length << " 个数字:" << endl;
	for (int i = 0;i < length;i++) {
		cin >> elem;
		data.push_back(elem);
	}
	vector<int> result = singleNumber(data);
	cout << "只出现一次的三个数字是： " << endl;
	for (int i = 0;i < result.size();i++)
		cout << result[i] << endl;

	return 0;
}
vector<int> do_zero(vector<int>& nums) {
	int sz = nums.size();
	vector<int> ans;
	for (int i = 0; i < 31; ++i) {
		int base = 1 << i, sum1 = 0, sum2 = 0;;
		for (int j = 0; j < sz; ++j) {
			if (nums[j] & base)
				sum1 ^= nums[j];
			else
				sum2 ^= nums[j];
		}
		if (sum1 != 0) {
			ans.push_back(sum1);
			break;
		}
		if (sum2 != 0) {
			ans.push_back(sum2);
			break;
		}
	}
	int cur = ans[0], sum = cur, base = 1;
	while (sum) {
		if (sum & 1)
			break;
		base <<= 1, sum >>= 1;
	}
	int e1 = 0, e2 = 0;
	for (int i = 0; i < sz; ++i) {
		if (nums[i] == cur)
			continue;
		if (nums[i] & base)
			e1 ^= nums[i];
		else
			e2 ^= nums[i];
	}
	ans.push_back(e1);
	ans.push_back(e2);
	return ans;
}

vector<int> singleNumber(vector<int>& nums) {
	int sz = nums.size(), sum = 0;
	for (int i = 0; i < sz; ++i)
		sum ^= nums[i];
	if (sum == 0)
		return do_zero(nums);
	for (int i = 0; i < sz; ++i)
		nums[i] ^= sum;
	vector<int> ans = do_zero(nums);
	for (int i = 0; i < 3; ++i)
		ans[i] ^= sum;
	return ans;
}

#endif // _ThreeNumbersAppearOnce_