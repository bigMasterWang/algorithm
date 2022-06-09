#include<math.h>
#include<algorithm>
using namespace std;


class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 2)
			return 1;
		if (n == 3)
			return 2;
		if ((n % 3) == 1)
			return pow(3, (n - 3) / 3) * 4;
		return pow(3, n / 3) * max((n % 3), 1);
	}
};
