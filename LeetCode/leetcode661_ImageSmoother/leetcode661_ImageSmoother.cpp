// Created by 周子望 on 2022/10/30.
#include "../../include.h"
/**
题目描述:

核心思想:
**/


class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
		int rows = img.size(), cols = img[0].size();
		if (rows == 1 || cols == 1) {
			return img;
		}

		vector<vector<int>> res(rows, vector<int>(cols));
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				int sum = 0, count = 0;

				for(int x = i - 1; x <= i + 1; x++) {
					for(int y = j - 1; y <= j + 1; j++) {
						if (x >= 0 && x < rows && y >= 0 && y < cols) {
							count++;
							sum += img[x][y];
						}
					}
				}
				res[i][j] = sum/count;
			}
		}

		return res;
	}
};
