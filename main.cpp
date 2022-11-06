#include "./include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int size = s.size();
		int left = 0, right = size - 1;
		while(left < right) {
			while(!isalnum(s[left]) && left < right) {
				left++;
			}
			while(!isalnum(s[right]) && left < right) {
				right--;
			}
			if (left != right && toupper(s[left]) != toupper(s[right])) {
				return false;
			}
			left++, right--;
		}

		return true;
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
	vector<int> nums = {0,1,0,3,12};
	vector<vector<int>> nums_vec = {{100,200,100},
	                                {200,50,200},
	                                {100,200,100},
	};
	vector<vector<char>> nums_vec_char = {{'1', '1', '1', '1', '0'},
	                                      {'1', '1', '0', '1', '0'},
	                                      {'1', '1', '0', '0', '0'},
	                                      {'0', '0', '0', '0', '0'}};
	vector<string> input_vec_string = {};
	string str_input = "A man, a plan, a canal: Panama";
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

	res_bool = sol.isPalindrome(str_input);
	// cout << res_int << endl;
	cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	//print_vector(nums);

	return 0;
}
