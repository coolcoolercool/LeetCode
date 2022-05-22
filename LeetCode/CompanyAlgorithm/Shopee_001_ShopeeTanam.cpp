//
// Created by rainyzwzhou on 2022/4/26.
//



/**
 题目:
 在Shopee，有一个游戏叫Shopee Tanam。这是一个由Shopee游戏开发商在印度尼西亚开发的游戏。Shopee Tanam意味着你可以在游戏平台上种植一些植物。其中一个游戏开发者有一个想法，在Shopee Tanam中创建一个新的子游戏。在这个子游戏中，你会得到一个公园，这个公园有一维的形状，由M个不同的单元组成。在每个单元中，你必须准确地种植一棵树。每天，这棵树可以结出有益的果实/有毒的果实/既无益也无毒的果实。有益的果实意味着你将获得正数的健康。有毒的果实会让你获得负数的健康。否则，你将得到0健康。

然后你会得到一个角色，这个角色将从一维公园的左边开始。你有N天的时间来玩游戏。每一天，树上结出的每个水果的健康数量都可能发生变化。在一天中，角色可以做这些行动中的一个。

完全不穿越公园（停留在当前位置）。 穿过公园，最多穿过M个单元，沿途收集所有有益和有毒的水果，然后角色转身，回到他穿过公园前的初始位置。 完全穿过公园，走到公园的另一边，然后人物在那里休息。 注意：在一天中，一个牢房里的水果最多可以得到一次。

帮助角色获得最大的健康量。

输入格式 将有T（1 <= T <= 10）个测试案例。在每个测试案例中，有一行有两个整数，N和M（1 <= N <= 1000，1 <= M <= 1000）。然后N行跟进，每行包含M个整数，A[i,j] (-10^9 <= A[i,j] <= 10^9)，这意味着第i天j单元的水果的健康状况。 输出格式 输出必须由T个整数组成，表示该字符可以得到的最大健康量。

输入样本

3 1 5 -9 -8 1 2 3 2 3 1 4 -5 -1 -9 100 2 3 1 4 -5 -1 -1 100

样本输出

0 100 103

解释

在第一个例子中，角色可以决定完全不穿越公园，因此角色得到的健康总量为0。 对于第二个例子。 第一天，人物从左边走，然后完全穿过公园，然后他在公园的右边休息，总健康数为：1+4+(-5)=0 第二天，角色从桥的右边走，只从右边走到第一个牢房，然后回到桥的右边，角色在第二天得到的总健康数是100 因此，角色从2天得到的健康总数是0+100=100。 对于第三个例子。 第一天，角色从左边走，但只从前2个单元格获得健康，然后角色回到公园的左边，总的健康数是：1+4=5 第二天，人物从公园的左边走，完全穿过公园，获得的总健康数为：。(-1) + (-1) + 100 = 98 第二天 因此，该人物在2天内获得的健康总量是5+98=103。
*/

#include <bits/stdc++.h>
using namespace std;

int main_0okm76() {
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		vector<int> oneLineMVec(m);
		long long left = 0, right = -1e9;

		// n 条路，每条路 m 个cell
		for(int indexN = 0; indexN < n; indexN++) {
			long long sum = 0, tempMax = 0;

			// 收集 m 个 cell 的值
			for(int indexM = 0; indexM < m; indexM++) {
				cin >> oneLineMVec[indexM];
			}

			// 从左到右，遍历找到最大和
			for(int i = 0; i < m; i++) {
				sum += oneLineMVec[i];
				tempMax = max(tempMax, sum);
			}

			long long tempLeft = max(left + tempMax, right + sum);

			sum = tempMax = 0;
			// 从右到做，遍历找到最大值
			for(int j = m - 1; j >= 0; j--) {
				sum += oneLineMVec[j];
				tempMax = max(tempMax, sum);
			}

			long long tempRight = max(right + tempMax, left + sum);
			left = tempLeft;
			right = tempRight;
		}
		cout << max(left, right) << endl;

	}
	return 0;
}


















