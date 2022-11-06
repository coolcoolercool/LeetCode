// Created by 周子望 on 2022/10/30.
#include "../../include.h"
/**
题目描述:

核心思想:
**/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		res.push_back(vector<int>{1});
		for(int row = 1; row < numRows; row++) {
			vector<int> vec(row + 1); // 需要提前生命了 size，后面才能直接使用 vec[index]
			for(int col = 0; col < row + 1; col++) {
				if (col == 0 || col == row) {
					vec[col] = 1;
				} else{
					vec[col] = res[row - 1][col -1] + res[row - 1][col];
				}
			}
			res.push_back(vec);
		}
		return res;
	}
};