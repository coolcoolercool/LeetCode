#include "./include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>> &mat) {

	}
};

void print_vector(const vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ", ";
	}
	cout << endl;
}

int main_okmjng() {
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
	string str_input = "1b";
	string str_input1 = "2b";
	int int_input1 = 5;
	int int_input2 = 8;

	vector<int> res_vec;
	vector<string> res_vec_str;
	vector<vector<int>> res_vec_vec_int;
	vector<vector<string>> res_vec_vec_string;
	string resStr;
	int res_int = 0;
	bool res_bool = false;

	// resStr = sol.thirtysixAdd(str_input, str_input1);
	cout << resStr << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(res_vec);

	return 0;
}
