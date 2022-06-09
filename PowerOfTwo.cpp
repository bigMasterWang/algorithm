class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		if (n == 1)
			return true;
		for (int i = 0; i < 31; i++)
		{
			if ((2 << i) == n)
				return true;
		}
		return false;
	}
};