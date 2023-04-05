#include <bits/stdc++.h>
#include "include.h"

using namespace std;
class Solution {
public:
	int myAtoi(string s) {
		int size = s.size();
		int index = 0;
		while(index < size && s[index] == ' ') {
			index++;
		}

		bool flag = true;
		if(s[index] == '-') {
			flag = false;
			index++;
		} else if(s[index] == '+') {
			index++;
		}

		long res = 0;
		while(index < size) {
			if(s[index] < '0' || s[index] > '9') break;
			res = res * 10 + s[index] - '0';
			if ((res > INT_MAX && flag) || (res * -1 < INT_MIN && !flag)) {
				if(flag) return INT_MAX;
				else return INT_MIN;
			}
			index++;
		}
		if(flag) {
			return res;
		} else{
			return -res;
		}
	}
};

void print_vector(const vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ", ";
	}
	cout << endl;
}

int main_0omj7() {
	Solution sol;
	vector<int> nums = {-1,0,1,2,-1,-4};
	vector<vector<int>> nums_vec = {{100, 200, 100},
	                                {200, 50,  200},
	                                {100, 200, 100},
	};
	vector<vector<char>> nums_vec_char = {{'1', '1', '1', '1', '0'},
	                                      {'1', '1', '0', '1', '0'},
	                                      {'1', '1', '0', '0', '0'},
	                                      {'0', '0', '0', '0', '0'}};
	vector<string> input_vec_string = {"flower","flow","flight"};
	string str_input = "PAYPALISHIRING";
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

	// res_vec_vec_int = sol.threeSum(nums);
	// cout << res_int << endl;
	// cout << res_bool << endl;
	// cout << resStr << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(nums);

	return 0;
}
