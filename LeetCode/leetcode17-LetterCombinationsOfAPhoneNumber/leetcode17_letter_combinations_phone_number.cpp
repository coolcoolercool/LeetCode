#include "../../include.h"

class Solution {
public:
	string oneRes;
	vector<string> res;
	vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	void DFS(int charPos, string digits) {
		if (charPos == digits.size()) {
			res.push_back(oneRes);
			return;
		}
		int num = digits[charPos] - '0';
		for (int i = 0; i < board[num].size(); i++) {
			oneRes.push_back(board[num][i]);
			DFS(charPos + 1, digits);
			oneRes.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return res;
		DFS(0, digits);
		return res;
	}


public:
	vector<string> letterCombinations_1(string digits) {
		vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		if (digits == "") return {};

		vector<string> res{""};

		for (int i = 0; i < digits.size(); i++) {
			vector<string> temp;  // temp是本轮字符选择完成的结果
			char ch = digits[i];
			string curStr = dict[ch - '0'];

			for (int j = 0; j < curStr.size(); j++) {
				for (int k = 0; k < res.size(); k++) {
					temp.push_back(res[k] + curStr[j]);   // res[k] 是上一轮字符选择的结果
				}
				res = temp;  // 这里 是因为会直接修改res的值，因此使用了临时变量temp
			}

		}
		return res;
	}
};

// Test
int mainasdsad() {
	Solution sol;
	string n = "25";
	vector<string> res = sol.letterCombinations(n);

	for(string s : res)
	{
		cout << s << " ";
	}
	cout << endl;
	return 0;
}


