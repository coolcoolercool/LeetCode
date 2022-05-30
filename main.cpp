#include "./include.h"
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int> &nums) {
		int size = nums.size();
		int res = size + 1;
		int curSum = nums[0];
		int left = 0, right = 0;
		while (left <= right && right < size) {
			if (curSum >= target) {
				res = min(right - left + 1, res);
				curSum -= nums[left];
				left++;
			} else if (curSum < target) {
				right++;
				if (right < size) curSum += nums[right];;
			}
		}

		return res > size ? 0 : res;
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
	vector<string> input_vec_string = {"flower", "flow", "flight"};
	string str_input = "21474836460";
	string str_input1 = "ABC";
	int int_input1 = 5;
	int int_input2 = 8;

	vector<int> res_vec;
	vector<string> res_vec_str;
	vector<vector<int>> res_vec_vec_int;
	vector<vector<string>> res_vec_vec_string;
	string resStr;
	int res_int = 0;
	bool res_bool = false;

	res_int = sol.minSubArrayLen(7, nums);
	cout << res_int << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(nums);

	return 0;
}
