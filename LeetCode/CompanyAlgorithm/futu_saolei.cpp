// Created by rainyzwzhou on 2022/5/9.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateVector(int num, int row, int col) {
		srand((unsigned int)time(NULL));  // srand() 用来设置 rand() 产生随机数时的随机数种子, 使用当前时间作为种子

		// 随机生成 指定雷数 的扫雷地图
		vector<vector<int>> res(row, vector<int>(col));
		for(int i = 0; i < num; i++) {
			int tempRow = rand() % row;
			int tempCol = rand() % col;

			if (res[tempRow][tempCol] == 0) {
				res[tempRow][tempCol] = -1;
			} else {
				i--;
			}
		}

		// 找到雷，把以雷为中心的九宫格的所有元素都加1，除了(格子本身是雷的除外)
		for (int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {

				// 找到一个雷
				if (res[i][j] == -1) {
					for(int rowIndex = i - 1; rowIndex <= i + 1; rowIndex++) {
						for(int colIndex = j - 1; colIndex <= j + 1; colIndex++) {
							if(rowIndex >= 0 && rowIndex < row && colIndex >= 0 && colIndex < col && res[rowIndex][colIndex] != -1) {
								res[rowIndex][colIndex]++;
							}
						}
					}
				}
			}
		}

		return res;
	};
};