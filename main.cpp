#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int size = nums.size();
		int index = 0;
		for(index = size - 2; index >= 0; index--) {
			if(nums[index] < nums[index + 1]) {
				break;
			}
		}
		if (index == -1) {
			reverse(nums.begin(), nums.end());
		} else {
			for(int j = size - 1; j >= 0; j--) {
				if (nums[j] > nums[index]) {
					swap(nums[index], nums[j]);
					reverse(nums.begin() + index + 1, nums.end());
					break;
				}
			}
		}
	}
};

void print_vector(const vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ", ";
	}
	cout << endl;
}

int main() {
	Solution sol;
	vector<int> nums = {1,8,5,7,6,4};
	vector<vector<int>> nums_vec = {{100, 200, 100},
	                                {200, 50,  200},
	                                {100, 200, 100},
	};
	vector<vector<char>> nums_vec_char = {{'1', '1', '1', '1', '0'},
	                                      {'1', '1', '0', '1', '0'},
	                                      {'1', '1', '0', '0', '0'},
	                                      {'0', '0', '0', '0', '0'}};
	vector<string> input_vec_string = {"flower","flow","flight"};
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

	sol.nextPermutation(nums);
	// cout << res_int << endl;
	// cout << res_bool << endl;
	// cout << resStr << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	print_vector(nums);

	return 0;
}
