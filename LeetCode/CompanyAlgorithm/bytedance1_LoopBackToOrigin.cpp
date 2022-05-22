// Created by rainyzwzhou on 2022/5/16.

/**
题目描述:
圆环上有10个点，编号为0~9。从0点出发，每次可以逆时针和顺时针走一步，问走n步回到0点共有多少种走法。

输入: 2
输出: 2
解释：有2种方案。分别是0->1->0和0->9->0

核心思想:
 本题考察的是动态规划。
如果你之前做过leetcode的70题爬楼梯，则应该比较容易理解：走n步到0的方案数=走n-1步到1的方案数+走n-1步到9的方案数。
因此，若设dp[i][j]为从0点出发走i步到j点的方案数，则递推式为：

 ps:公式之所以取余是因为j-1或j+1可能会超过圆环0~9的范围

 dp[i][j]表示从0出发，每次只走一步,走i步到j的方案数
 dp[i][j] = dp[i-1][(j-1+length)%length] + dp[i-1][(j+1)%length]

 https://www.nowcoder.com/practice/16409dd00ab24a408ddd0c46e49ddcf8?tpId=196&tqId=40267&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D%25E5%259C%2586%25E7%258E%25AF%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196&difficulty=undefined&judgeStatus=undefined&tags=&title=%E5%9C%86%E7%8E%AF

 https://zhuanlan.zhihu.com/p/338806463

 	0	1	2	3	4	5	6	7	8	9
0	1	0	0	0	0	0	0	0	0	0
1	0	1	0	0	0	0	0	0	0	1
2	2	0	1	0	0	0	0	0	1	0
3	0	3	0	1	0	0	0	1	0	3
4	6	0	4	0	1	0	1	0	4	0
5	0	10	0	5	0	1	0	5	0	10
6	20	0	15	0	6	0	6	0	15	0
7	0	35	0	21	0	12	0	21	0	35
8	70	0	56	0	33	0	33	0	56	0
9	0	126	0	89	0	66	0	89	0	126


**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int circle(int n) {
		// int mod = 1000000007;
		int len = 10;
		vector<vector<int>> dp(n + 1, vector<int>(len));

		dp[0][0] = 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < len; j++) {
				dp[i][j] = dp[i - 1][(j - 1 + len) % len] +
				           dp[i - 1][(j + 1) % len];
			}
		}

		return dp[n][0];
	}
};


