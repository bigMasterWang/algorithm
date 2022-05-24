#include<string>
#include<vector>
using namespace std;


class Solution {
public:
	string multiply(string num1, string num2) {
		int i_1 = num1.size() - 1;
		int i_2 = num2.size() - 1;
		int add = 0;
		vector<string> addResVector;
		for (i_1; i_1 >= 0; i_1--)
		{
			i_2 = num2.size() - 1;
			string res = "";
			add = 0;
			for (i_2; i_2 >= 0; i_2--)
			{
				int mul = (num2[i_2] - '0') * (num1[i_1] - '0') + add;
				// 直接用数字可能会越界
				res += (mul % 10) + '0';
				add = mul / 10;
			}
			if (add != 0)
				res += add + '0';
			// 根据mulBase
			for (int i = 0; i < num1.size() - 1 - i_1; i++)
				res = '0' + res;
			addResVector.push_back(res);
		}

		// 然后再把所有这个addRes中的string相加, 可以两两相加，循环即可
		string addRes = addResVector[0];
		for (int i = 1; i < addResVector.size(); i++)
		{
			//addRes + addResVector[i], 直接从个位开始相加即可
			string strTwo = addResVector[i];
			int ptr_1 = 0, ptr_2 = 0;
			add = 0;
			while (ptr_1 < addRes.size() && ptr_2 < strTwo.size())
			{
				int _a = (addRes[ptr_1] - '0') + (strTwo[ptr_2] - '0') + add;
				addRes[ptr_1] = (_a % 10) + '0';
				add = _a / 10;

				ptr_1++;
				ptr_2++;
			}
			// 有可能还有一个没加完
			while (ptr_1 < addRes.size())
			{
				int _a = (addRes[ptr_1] - '0') + add;
				addRes[ptr_1] = (_a % 10) + '0';
				add = _a / 10;
				ptr_1++;
			}
			while (ptr_2 < strTwo.size())
			{
				int _a = (strTwo[ptr_2] - '0') + add;
				addRes += (_a % 10) + '0';
				add = _a / 10;
				ptr_2++;
			}
			if (add != 0)
				addRes += add + '0';
		}
		// 反转顺序
		reverse(addRes.begin(), addRes.end());
		// 然后取出多余的0
		for (int i = 0; i < addRes.size(); i++)
		{
			if (addRes[i] == '0')
			{
				addRes.erase(0, 1);
				i--;
			}
			else
				break;
		}
		if (addRes == "")
			return "0";
		return addRes;
	}
};