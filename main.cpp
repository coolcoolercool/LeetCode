#include "./include.h"
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int res = INT_MAX;
		int rows = triangle.size();
		if(rows == 1) return triangle[1][0];

		vector<vector<int>> dp(rows);
		dp.push_back(triangle[0]);
		int levelIndex = 1;
		for(int i = 1; i < rows; i++) {
			int levelSize = i + 1;
			vector<int> levelVec;
			for(int j = 0; j < levelSize; j++) {
				if(j == 0) {
					levelVec.push_back(triangle[levelIndex - 1][0] + triangle[levelIndex][0]);
				} else {
					levelVec.push_back(min(triangle[levelIndex - 1][j], triangle[levelIndex - 1][j - 1]) + triangle[levelIndex][j]);
				}
			}
			dp.push_back(levelVec);
			levelIndex++;
		}

		for(int j = 0; j < rows; j++) {
			res = min(res, dp[rows - 1][j]);
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

	res_int = sol.minimumTotal(nums_vec);
	cout << res_int << endl;
	// cout << res_bool << endl;
	// print_vector_vector(res_vec_vec_int);
	// print_vector_vector(res_vec_vec_string);
	// print_vector(nums);

	return 0;
}
