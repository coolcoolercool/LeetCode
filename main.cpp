#include "./include.h"
#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
	double x, y;
	double len;

public:
	Solution(double radius, double x_center, double y_center) {
		x = x_center;
		y = y_center;
		len = radius;
	}

	vector<double> randPoint() {
		double curX = 0, curY = 0;
		while (true) {
			curX = rand() % len;
			curY = rand
		}
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
	vector<int> nums = {1, 2, 5};
	vector<vector<int>> nums_vec = {{2},
	                                {3, 4},
	                                {6, 5, 7},
	                                {4, 1, 8, 3}};
	vector<vector<char>> nums_vec_char = {{'1', '1', '1', '1', '0'},
	                                      {'1', '1', '0', '1', '0'},
	                                      {'1', '1', '0', '0', '0'},
	                                      {'0', '0', '0', '0', '0'}};
	vector<string> input_vec_string = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
	                                   "testemail+david@lee.tcode.com"};
	string str_input = "acdaba";
	string str_input1 = "badaa";
	int int_input1 = 13;
	int int_input2 = 8;

	vector<int> res_vec;
	vector<string> res_vec_str;
	vector<vector<int>> res_vec_vec_int;
	vector<vector<string>> res_vec_vec_string;
	string resStr;
	int res_int = 0;
	bool res_bool = false;

	res_int = sol.coinChange(nums, 11);
	cout << res_int << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(nums);

	return 0;
}
