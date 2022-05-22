#include "./include.h"
using namespace std;

class Solution {
public:
	string removeDuplicates(string s) {
		stack<char> st;
		for(int i = 0; i < s.size(); i++) {
			if(!st.empty() && st.top() == s[i]) {
				st.pop();
			} else {
				st.push(s[i]);
			}
		}

		string res;
		while(!st.empty()) {
			res.push_back(st.top());
			st.pop();
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
	vector<int> nums = {2, 7,9,3,1};
	vector<vector<int>> nums_vec = {{7,0},{4,4},{7,1},{5, 0}, {6, 1}, {5, 2}};
	vector<vector<char>> nums_vec_char = {{'1','1','1','1','0'},
										  {'1','1','0','1','0'},
										  {'1','1','0','0','0'},
										  {'0','0','0','0','0'}};
	vector<string> input_vec_string = {"pen", "apple"};
	string str_input = "abbaca";
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

	resStr = sol.removeDuplicates(str_input);
	cout << resStr << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(nums);

	return 0;
}
