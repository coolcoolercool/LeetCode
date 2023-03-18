#include "../../include.h"

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int size = s.size();
		if (size < 2) return size;

		set<char> innerSet;
		int left = 0, right = 0, res = 1;

		//  双指针法
		while (left <= right && right < size) { // 注意这里 left <= right
			if (innerSet.count(s[right]) != 0) {
				innerSet.erase(s[left]);
				left++;
			} else {
				innerSet.insert(s[right]);
				res = max(int(innerSet.size()), res);
				right++;
			}
		}

		return res;
	}

	int lengthOfLongestSubstring_1(string s) {
		vector<int> m(128, 0);
		int max_length = 0;
		int i = 0;
		for (int j = 0; j < s.size(); j++) {
			i = max(i, m[s[j]]);
			m[s[j]] = j+1;
			max_length = max(max_length, j - i + 1);
		}

		return max_length;
	}
};