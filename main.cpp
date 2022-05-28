#include "./include.h"
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		int sizeNum1 = num1.size();
		int sizeNum2 = num2.size();

		int left = sizeNum1 - 1, right = sizeNum2 - 1;
		int add = 0;
		string res;
		while (left >= 0 || right >= 0 || add != 0) {
			int val1 = left >= 0 ? num1[left] - '0' : 0;
			int val2 = right >= 0 ? num2[right] - '0' : 0;

			int val = val1 + val2 + add;
			add = val / 10;
			val = val % 10;
			res.push_back(val + '0');
			if (left >= 0) left--;
			if (right >= 0) right--;
		}
		reverse(res.begin(), res.end());
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
	vector<int> nums = {-1};
	vector<vector<int>> nums_vec = {{2},
	                                {3, 4},
	                                {6, 5, 7},
	                                {4, 1, 8, 3}};
	vector<vector<char>> nums_vec_char = {{'1', '1', '1', '1', '0'},
	                                      {'1', '1', '0', '1', '0'},
	                                      {'1', '1', '0', '0', '0'},
	                                      {'0', '0', '0', '0', '0'}};
	vector<string> input_vec_string = {"pen", "apple"};
	string str_input = "10200";
	string str_input1 = "ABC";
	int int_input1 = 0;
	int int_input2 = 8;

	vector<int> res_vec;
	vector<string> res_vec_str;
	vector<vector<int>> res_vec_vec_int;
	vector<vector<string>> res_vec_vec_string;
	string resStr;
	int res_int = 0;
	bool res_bool = false;

	resStr = sol.removeKdigits(str_input, 1);
	cout << resStr << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(nums);

	return 0;
}
