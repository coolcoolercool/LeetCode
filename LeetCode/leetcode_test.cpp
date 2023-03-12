#include "../include.h"

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int col = matrix.size();
		int row = col;

		for(int i = 0; i < col; i++) {
			int low = 0, high = col - 1;
			while(low < high) {
				swap(matrix[low][i], matrix[high][i]);
				low++;
				high--;
			}
		}

		for(int i = 0; i < row; i++) {
			for(int j = 0; j < i; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};

static void print_vector(const vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ", ";
	}
	cout << endl;
}


int main_okmnj8() {
	Solution sol;
	vector<int> nums = {3,30,34,5,9};

	int resultInt = 0;
	string str = "pwwkew";
	int target = 11;
	vector<int> res;
	string resStr;

	// resultInt = sol.lengthOfLongestSubstring(str);

	//print_vector(res);
	cout << "resultInt: " << resStr << endl;

	return 0;
}


