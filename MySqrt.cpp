class Solution {
public:
	int mySqrt(int x) {


		int left = 0, right = x, middle;

		while (left < right)
		{
			middle = (left + right) / 2;
			if (middle == x / middle)
				break;
			else if (middle < x / middle)
				left = middle + 1;
			else
				right = middle - 1;
		}
		middle = (left + right) / 2;
		return middle;
	}
};