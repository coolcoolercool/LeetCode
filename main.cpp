#include "./include.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// leetcode 19

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		ListNode* fast = dummy;
		ListNode* slow = dummy;
		ListNode* pre = nullptr;

		while(n > 0) {
			fast = fast->next;
			n--;
		}

		while(fast != nullptr) {
			fast = fast->next;
			pre = slow;
			slow = slow->next;
		}
		pre->next = pre->next->next;
		return dummy->next;
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
	vector<int> nums = {-2,0,1,1,2};
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

	res_vec_vec_int = sol.threeSum(nums);
	cout << resStr << endl;
	// cout << res_bool << endl;
	print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(res_vec);

	return 0;
}
