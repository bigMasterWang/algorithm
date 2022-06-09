#include<climits>


class Solution {
public:
	int divide(int dividend, int divisor) {
		bool isNegative = false;
		if (divisor > 0)
		{
			isNegative = !isNegative;
			divisor = -divisor;
		}
		if (dividend > 0)
		{
			isNegative = !isNegative;
			dividend = -dividend;
		}
		if (dividend > divisor)
			return 0;
		int res = 1, pre = 0, preDivisor = 0, saveDivisor = divisor;
		while (dividend <= divisor)
		{
			preDivisor = divisor;
			divisor += divisor;
			pre = res;
			res += res;
		}
		if (dividend == divisor)
			return res;
		for (int i = pre; i < res && preDivisor > dividend; i++)
		{
			preDivisor += saveDivisor;
			res += 1;
		}
		res -= 1;
		if (isNegative)
		{
			if (-res < INT_MIN)
				return INT_MIN;
			else
				return -res;
		}
		else
		{
			if (res > INT_MAX)
				return INT_MAX;
			else
				return res;
		}
	}
};