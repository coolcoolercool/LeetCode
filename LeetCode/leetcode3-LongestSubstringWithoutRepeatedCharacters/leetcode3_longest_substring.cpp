#include "../../include.h"

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty() || s.size() == 1) {
			return s.size();
		}

		set<char> set_element;
		int left = 0, right = 0, max_length = 1;

		//  双指针法
		while (left <= right && right < s.size()) {
			if (set_element.count(s[right]) == 1) {
				set_element.erase(s[left]);
				left++;
			} else {
				set_element.insert(s[right]);
				max_length = max(right - left + 1, max_length);
				right++;
			}
		}

		return max_length;
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