#include<iostream>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int number = 0;
		while (n)
		{
			number += (n & 1);
			n = n >> 1;
		}
		return number;
	}
};