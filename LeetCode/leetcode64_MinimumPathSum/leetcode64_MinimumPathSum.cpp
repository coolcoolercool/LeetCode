// Created by 周子望 on 2021/11/8.

/*
 题目: 最小路径和
 给定一个包含非负整数的 mxn网格grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 说明：每次只能向下或者向右移动一步。

 核心思想:
动态规划
由于路径的方向只能是向下或向右，因此网格的第一行的每个元素只能从左上角元素开始向右移动到达，网格的第一列的每个元素只能从左上角元素开始向下移动到达，此时的路径是唯一的，因此每个元素对应的最小路径和即为对应的路径上的数字总和。
对于不在第一行和第一列的元素，可以从其上方相邻元素向下移动一步到达，或者从其左方相邻元素向右移动一步到达，元素对应的最小路径和等于其上方相邻元素与其左方相邻元素两者对应的最小路径和中的最小值加上当前元素的值。由于每个元素对应的最小路径和与其相邻元素对应的最小路径和有关，因此可以使用动态规划求解。
创建二维数组 {dp}dp，与原始网格的大小相同，dp[i][j] 表示从左上角出发到 (i,j)(i,j) 位置的最小路径和。显然，dp[0][0]=grid[0][0]。对于 {dp}dp 中的其余元素，通过以下状态转移方程计算元素值。

当 i>0 且 j=0 时，dp[i][0]=dp[i−1][0]+grid[i][0]。
当 i=0 且 j>0 时，dp[0][j]=dp[0][j−1]+grid[0][j]。
当 i>0且 j>0时，dp[i][j]=min(dp[i−1][j],dp[i][j−1])+grid[i][j]。
最后得到 dp[m−1][n−1] 的值即为从网格左上角到网格右下角的最小路径和。
 */

#include "../../include.h"

// 使用回溯可以做，但是这里的标签是动态规划，因此可以推论使用回溯多半会有超时的例子
class Solution {
public:
	int minPathSum(vector<vector<int>> &grid) {
		// 使用f{i,j} = mat[i, j] + min(mat[i, j - 1], mat[i - 1,j])
		// dp[i][j] 表示从左上角出发到 (i,j)(i,j) 位置的最小路径和
		int rows = grid.size(), cols = grid[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols));

		dp[0][0] = grid[0][0];
		for (int j = 1; j < cols; j++) { 		// 第一行累加，因为只有一条路
			dp[0][j] = grid[0][j] + dp[0][j - 1];
		}

		for (int i = 1; i < rows; i++) { 		// 第一列累加
			dp[i][0] = grid[i][0] + dp[i - 1][0];
		}

		for (int i = 1; i < rows; i++) {
			for (int j = 1; j < cols; j++) {
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		return dp[rows - 1][cols - 1];
	}
};

int main_in8m0 () {
	Solution sol;
	vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
	int res = sol.minPathSum(grid);
	cout << "res: " << res << endl;

	grid = {{1,2,3},{4,5,6}};
	res = sol.minPathSum(grid);
	cout << "res: " << res << endl;

	return 0;
}


