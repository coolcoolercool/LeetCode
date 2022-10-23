#include "./include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int size = citations.size();
		sort(citations.begin(), citations.end());

		int res = 0;
		for(int i = 0; i < size; i++) {
			if (i > 0 && citations[i] == citations[i - 1]) {
				continue;
			}
			int hIndex = min(citations[i], size - i);
			res = max(hIndex, res);
		}

		return res;
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
	vector<int> nums = {3,0,6,1,5};
	vector<vector<int>> nums_vec = {{1,2,3},
	                                {4,5,6},
	                                {7,8,9},
	};
	vector<vector<char>> nums_vec_char = {{'1', '1', '1', '1', '0'},
	                                      {'1', '1', '0', '1', '0'},
	                                      {'1', '1', '0', '0', '0'},
	                                      {'0', '0', '0', '0', '0'}};
	vector<string> input_vec_string = {};
	string str_input = "  hello world  ";
	string str_input1 = "dog cat cat dog";
	int int_input1 = 0;
	int int_input2 = 8;

	vector<int> res_vec;
	vector<string> res_vec_str;
	vector<vector<int>> res_vec_vec_int;
	vector<vector<string>> res_vec_vec_string;
	string resStr;
	int res_int = 0;
	bool res_bool = false;

	res_int = sol.hIndex(nums);
	 cout << res_int << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	print_vector(res_vec);

	return 0;
}
