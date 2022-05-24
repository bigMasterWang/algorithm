/*

���ַ��� s ���ҳ���һ��ֻ����һ�ε��ַ������û�У�����һ�����ո� s ֻ����Сд��ĸ��
*/
#include<string>
#include<map>
using namespace std;


// "loveleetcode"
//class Solution {
//public:
//	char firstUniqChar(string s) {
//		map<char, int> counter;
//		for (char x : s)
//			counter[x]++;
//		for (char x : s)
//			if (counter[x] == 1)
//				return x;
//		return ' ';
//	}
//};


class Solution {
public:
	char firstUniqChar(string s) {
		int table[26] = { 0 };
		for (char x : s)
			table[x - 'a']++;
		for (char x : s)
			if (table[x - 'a'] == 1)
				return x;
		return ' ';
	}
};