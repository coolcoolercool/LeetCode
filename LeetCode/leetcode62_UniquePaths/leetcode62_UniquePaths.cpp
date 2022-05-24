//
// Created by 周子望 on 2021/11/4.
//

/*
一个机器人位于一个 m x n网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？

 思路:
 方法一：动态规划
思路与算法
我们用 select(i, j) 表示从左上角走到 (i, j) 的路径数量，其中 i 和 j 的范围分别是 [0, m) 和 [0, n)。
由于我们每一步只能从向下或者向右移动一步，因此要想走到 (i, j)(i,j)，如果向下走一步，那么会从 (i-1, j)(i−1,j) 走过来；如果向右走一步，那么会从 (i, j-1)走过来。因此我们可以写出动态规划转移方程：
select(i, j) = select(i-1, j) + select(i, j-1)
需要注意的是，如果 i=0i=0，那么 select(i-1,j) 并不是一个满足要求的状态，我们需要忽略这一项；同理，如果 j=0j=0，那么 select(i,j-1) 并不是一个满足要求的状态，我们需要忽略这一项。
初始条件为 select(0,0)=1f(0,0)=1，即从左上角走到左上角有一种方法。
最终的答案即为 select(m-1,n-1)select(m−1,n−1)。

细节
为了方便代码编写，我们可以将所有的 select(0, j) 以及 select(i, 0)都设置为边界条件，它们的值均为 1。
 */

#include "../../include.h"

class Solution {
	/**
	dp(i, j) 表示从左上角走到 (i, j) 的路径数量，其中 i 和 j 的范围分别是 [0, m) 和 [0, n)
	每一步只能从向下或者向右移动一步，因此要想走到 (i, j)，如果向下走一步，那么会从 (i-1, j) 走过来；如果向右走一步，那么会从 (i, j-1) 走过来。因此我们可以写出动态规划转移方程：
	select(i, j) = select(i-1, j) + select(i, j-1)
	 */
public:
	int uniquePaths(int m, int n) {
		// dp(i, j) 表示从左上角走到 (i, j) 的路径数量，其中 i 和 j 的范围分别是 [0, m) 和 [0, n)
		vector<vector<int>> dp(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			dp[i][0] = 1;
		}

		for (int j = 0; j < n; j++) {  // 因为在边界只有一条路可走
			dp[0][j] = 1;
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};


// 递归回溯，会运行超时
class Solution_Bad_Method {
private:
	int num_path = 0;
	void dfs (int m, int n, int cur_x, int cur_y) {
		if (cur_x == m - 1 && cur_y == n - 1) {
			num_path++;
			return;
		}

		// 向下移动
		if (cur_x + 1 < m && cur_y < n) {
			dfs (m, n, cur_x + 1, cur_y);
		}

		// 向右移动
		if (cur_x < m && cur_y + 1 < n) {
			dfs (m ,n, cur_x, cur_y + 1);
		}
	}

public:
	int uniquePaths(int m, int n) {
		dfs (m, n, 0, 0);

		return num_path;
	}
};

int main_ok98m () {
	Solution sol;
	int m = 0, n = 0, res = 0;

	m = 3, n = 7;
	//res = sol.uniquePaths(m , n);
	cout << "res: " << res << endl;

	res = 0;
	m = 19, n = 13;
	res = sol.uniquePaths(m , n);
	cout << "res: " << res << endl;

	return 0;
}

