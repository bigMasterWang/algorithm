class Solution {
private:
	int res = 1;
public:
	int sumNums(int n) {
		int x = n > 1 && sumNums(n - 1);
		res += x;
		return res;
	}
};