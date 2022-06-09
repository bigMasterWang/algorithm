class Solution {
public:
	double myPow(double x, int n) {
		double res = 1;
		bool negative = false;
		long long timer = n;
		if (timer < 0)
		{
			timer = -timer;
			negative = true;
		}
		for (long long i = timer; i > 0; i /= 2)
		{
			if (i % 2 == 1)
			{
				res *= x;
			}
			x *= x;
		}
		if (negative)
			return 1 / res;
		return res;
	}
};