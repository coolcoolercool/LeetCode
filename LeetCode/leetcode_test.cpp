#include "../include.h"

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char> innerSet;
		int left = 0, right = 0;
		int maxLenSubstring = 1;

		while(left <= right && right < s.size()) {
			if (innerSet.count(s[right]) != 0) {
				innerSet.erase(s[left]);
				left++;
			} else {
				innerSet.insert(s[right]);
				right++;
				if (innerSet.size() > maxLenSubstring) {
					maxLenSubstring = innerSet.size();
				}
			}
		}

		return maxLenSubstring;
	}
};

static void print_vector(const vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ", ";
	}
	cout << endl;
}


int main_okmnj8() {
	Solution sol;
	vector<int> nums = {3,30,34,5,9};

	int resultInt = 0;
	string str = "pwwkew";
	int target = 11;
	vector<int> res;
	string resStr;

	resultInt = sol.lengthOfLongestSubstring(str);

	//print_vector(res);
	cout << "resultInt: " << resStr << endl;

	return 0;
}


