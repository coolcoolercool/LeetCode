// Created by rainyzwzhou on 2022/6/9.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
		int rows = mat.size(), cols = mat[0].size();
		int cnt = rows + cols - 1; // 总对角线数量
		int index = 0, curX = 0, curY = 0;  // curX:纵坐标，curY:横坐标
		vector<int> res(rows * cols);

		for (int i = 0; i < cnt; ++i) {
			// 斜上方向(curX - 1, curY + 1)
			while (curX >= 0 && curY < cols) {
				res[index++] = mat[curX--][curY++];
			}
			// 斜上方向越界后的处理
			if (curY < cols) { // 在左边越界
				curX++;
			} else {  // 在右边越界
				curX += 2;
				curY--;
			}

			// 斜下方向(curX + 1, curY - 1)
			while (curX < rows && curY >= 0) {
				res[index++] = mat[curX++][curY--];
			}

			// 斜下方向越界后的处理
			if (curX < rows) { // 在右边越界
				curY++;
			} else { // 在下边越界
				curX--;
				curY += 2;
			}
		}

		return res;
	}
};