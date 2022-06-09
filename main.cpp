#include "./include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int multiply(string &str, string &target) {
		int strSize = str.size();
		int targetSize = target.size();

		if (strSize < targetSize) return -1;

		vector<int> strVec(26);
		vector<int> targetVec(26);
		for (char e : target) {
			targetVec[e - 'a']++;
		}

		int left = 0, right = 0;
		int cnt = 1;
		strVec[str[0] - 'a']++;
		while (left <= right && right < strSize) {
			if (cnt == targetSize) {
				if (strVec == targetVec) {
					return left;
				} else {
					strVec[str[left] - 'a']--;
					left++;
					cnt--;
				}
			} else if (cnt < targetSize) {
				right++;
				if (right < strSize) {
					strVec[str[right] - 'a']++;
					cnt++;
				}
			}
		}

		return -1;
	}
};

void print_vector(const vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ", ";
	}
	cout << endl;
}

int main() {
	Solution sol;
	vector<int> nums = {2, 3, 1, 2, 4, 3};
	vector<vector<int>> nums_vec = {{2},
	                                {3, 4},
	                                {6, 5, 7},
	                                {4, 1, 8, 3}};
	vector<vector<char>> nums_vec_char = {{'1', '1', '1', '1', '0'},
	                                      {'1', '1', '0', '1', '0'},
	                                      {'1', '1', '0', '0', '0'},
	                                      {'0', '0', '0', '0', '0'}};
	vector<string> input_vec_string = {};
	string str_input = "ccaabb";
	string str_input1 = "abab";
	int int_input1 = 5;
	int int_input2 = 8;

	vector<int> res_vec;
	vector<string> res_vec_str;
	vector<vector<int>> res_vec_vec_int;
	vector<vector<string>> res_vec_vec_string;
	string resStr;
	int res_int = 0;
	bool res_bool = false;

	res_int = sol.multiply(str_input, str_input1);
	cout << res_int << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(res_vec);

	return 0;
}
