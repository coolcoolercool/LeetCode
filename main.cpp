#include "./include.h"
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int size = height.size();
		int res = 0;
		int left = 0, right = size - 1;
		int curLeftMax = 0, curRightMax = 0;

		while(left < right) {
			curLeftMax = max(curLeftMax, height[left]);
			curRightMax = max(curRightMax, height[right]);

			if(curLeftMax < curRightMax) {
				res += curLeftMax - height[left];
				left++;
			} else {
				res += curRightMax - height[right];
				right--;
			}
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
	vector<int> nums = {2, 7,9,3,1};
	vector<vector<int>> nums_vec = {{2},{3,4},{6,5,7},{4,1,8,3}};
	vector<vector<char>> nums_vec_char = {{'1','1','1','1','0'},
										  {'1','1','0','1','0'},
										  {'1','1','0','0','0'},
										  {'0','0','0','0','0'}};
	vector<string> input_vec_string = {"pen", "apple"};
	string str_input = "pwwkew";
	string str_input1 = "0";
	int int_input1 = 0;
	int int_input2 = 4;

	vector<int> res_vec;
	vector<string> res_vec_str;
	vector<vector<int>> res_vec_vec_int;
	vector<vector<string>> res_vec_vec_string;
	string resStr;
	int res_int = 0;
	bool res_bool = false;

	res_int = sol.lengthOfLongestSubstring(str_input);
	cout << res_int << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(nums);

	return 0;
}
