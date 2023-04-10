#include <bits/stdc++.h>
#include "include.h"

using namespace std;
class Solution {
public:
	int kthLargest(TreeNode* root, int k) {
		stack<TreeNode*> st;
		while(root != nullptr || !st.empty()) {
			while(root != nullptr) {
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();
			k--;
			if (k == 0) return root->val;
			root = root->right;
		}

		return -1;
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
	string str_input = "bbbbb";
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

	// sol.mergeSort(nums);
	//cout << res_int << endl;
	// cout << res_bool << endl;
	// cout << resStr << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	print_vector(nums);

	return 0;
}
