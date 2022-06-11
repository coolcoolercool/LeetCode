// Created by 周子望 on 2022/6/11.

/**
题目描述:

核心思想:
这里有个理解错的地方，就是购买附件一定要购买主件，但是购买主件不一定要购买附件
可以组合 附件1 + 主件，附件2 + 主件，主件，不买

**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int money, count;
	cin >> money >> count;
	// 由于价格是10的整数倍，处理一下以降低空间/时间复杂度
	money /= 10;
	vector<vector<int> > prices(61, vector<int>(3));        // 价格
	vector<vector<int> > priceMultiplyPriority(61, vector<int>(3));  // 重要程度
	for (int i = 1; i <= count; ++i) {
		int price, importance, isMain;
		cin >> price >> importance >> isMain;
		price /= 10; importance *= price;
		if (isMain == 0) {  // 是主件
			prices[i][0] = price;
			priceMultiplyPriority[i][0] = importance;
		} else { // 附件
			if (prices[isMain][1] == 0) {  // 附件1
				prices[isMain][1] = price;
				priceMultiplyPriority[isMain][1] = importance;
			} else { // 如果附件1已经有值了，则作为附件2
				prices[isMain][2] = price;
				priceMultiplyPriority[isMain][2] = importance;
			}
		}
	}
	// 使用分组背包
	vector<vector<int> > dp(count + 1, vector<int>(money + 1, 0));
	for (int i = 1; i <= count; ++i) {
		for (int j = 1; j <= money; ++j) {
			int a = prices[i][0], b = priceMultiplyPriority[i][0]; // 主件
			int c = prices[i][1], d = priceMultiplyPriority[i][1]; // 附件1
			int e = prices[i][2], f = priceMultiplyPriority[i][2]; // 附件2
			dp[i][j] = j >= a ? max(dp[i-1][j-a] + b, dp[i-1][j]) : dp[i-1][j];
			dp[i][j] = j >= (a+c) ? max(dp[i-1][j-a-c] + b + d, dp[i][j]) : dp[i][j];
			dp[i][j] = j >= (a+e) ? max(dp[i-1][j-a-e] + b + f, dp[i][j]) : dp[i][j];
			dp[i][j] = j >= (a+c+e) ? max(dp[i-1][j-a-c-e] + b + d + f, dp[i][j]) : dp[i][j];
		}
	}
	cout << dp[count][money] * 10 << endl;
}