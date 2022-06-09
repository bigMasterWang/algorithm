#include<vector>
using namespace std;


class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.size() == 0)
			return true;
		int root = postorder[postorder.size() - 1];
		bool rightTreePart = true;
		vector<int>small, big;
		for (int i = postorder.size() - 1; i >= 0; i--)
		{
			if (postorder[i] > root)
			{
				big.push_back(postorder[i]);
				if (!rightTreePart)
					return false;
			}
			if (postorder[i] < root)
			{
				small.push_back(postorder[i]);
				rightTreePart = false;
			}
		}
		return verifyPostorder(small) && verifyPostorder(big);
	}
};