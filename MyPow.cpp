class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		bool nNegative = false;
		if (n < 0)
			nNegative = true;

		double res = 1;
		for (int i = 0; i < n; i++)
		{
			res *= x;
		}
		if (nNegative)
			res = 1 / res;
		return res;
	}
};