#include "./include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int partition(vector<int>& nums, int left, int right) {
		int pivot = rand() % (right - left) + left;
		swap(nums[left], nums[pivot]);
		int index = pivot + 1;

		for(int i = index; i <= right; i++) {
			if (nums[i] < nums[pivot]) {
				swap(nums[i], nums[index]);
				index++;
			}
		}
		swap(nums[index - 1], nums[pivot]);
		return index - 1;
	}

	void quickSortHelp(vector<int>& nums, int left, int right) {
		if (left < right) {
			int partitionIndex = partition(nums, left, right);
			quickSortHelp(nums, left, partitionIndex - 1);
			quickSortHelp(nums, partitionIndex + 1, right);
		}
	}

	void quickSort(vector<int>& nums) {
		quickSortHelp(nums, 0, nums.size() - 1);
	}

	int findKthLargest(vector<int>& nums, int k) {

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
	vector<int> nums = {1, 3, 1, 5, 4};
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

	resStr = sol.reverseWords(str_input);
	cout << resStr << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(res_vec);

	return 0;
}
