#include "./include.h"
using namespace std;

class Solution {
public:
	string help(string &email) {
		int size = email.size();
		string realEmail;
		bool flagAt = false;
		bool flagPlus = false;
		for (int i = 0; i < size; i++) {
			if (email[i] == '.' && !flagAt) {
				continue;
			} else if (email[i] == '+' && !flagAt) {
				flagPlus = true;
			} else if (email[i] == '@') {
				flagAt = true;
				flagPlus = false;
				realEmail.push_back(email[i]);
			} else {
				if (!flagPlus) {
					realEmail.push_back(email[i]);
				}
			}
		}

		return realEmail;
	};

	int numUniqueEmails(vector<string> &emails) {
		unordered_set<string> st;
		for (auto &email : emails) {
			st.insert(help(email));
		}

		return (int) st.size();
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
	vector<int> nums = {1, 1, 1, 1, 1};
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

	res_int = sol.numUniqueEmails(input_vec_string);
	cout << res_int << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(nums);

	return 0;
}
