#include "../../include.h"

/*
题目: 给定一个 n×n 的二维矩阵matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像

核心思路:
两次翻转
先沿右上 - 左下的对角线翻转（270° +270°+ 一次镜像），再沿水平中线上下翻转（-180° +−180°+ 一次镜像），可以实现顺时针 90 度的旋转效果

 */

class Solution {
public:
	void rotate (vector<vector<int>>& matrix) {
		int col = matrix.size();
		int row = col;

		// 先上下对折
		for(int i = 0; i < col; i++) {
			int low = 0, high = col - 1;
			while(low < high) {
				swap(matrix[low][i], matrix[high][i]);
				low++; high--;
			}
		}

		// 再沿着 左到右 对角线对折
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < i; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}

public:
	/*
    顺时针旋转90：先沿对角线反转矩阵，再沿竖中轴线反转矩阵；
	顺时针旋转180：先沿横中轴线反转矩阵，再沿竖中轴线反转矩阵；
	顺时针旋转270：先沿对角线反转矩阵，再沿横中轴线反转矩阵；
	https://leetcode.cn/problems/rotate-image/solution/xuan-zhuan-90180270-by-cheless-w-5b8m/
	 */
};

int main_234k() {
	Solution sol;

	vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

	sol.rotate(matrix);

	for (auto vec_element : matrix) {
		for (auto element : vec_element) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}

