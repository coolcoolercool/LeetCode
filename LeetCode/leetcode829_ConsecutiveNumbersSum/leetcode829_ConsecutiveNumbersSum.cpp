// Created by rainyzwzhou on 2022/6/3.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/consecutive-numbers-sum/solution/by-ac_oier-220q/
数学推论
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int consecutiveNumbersSum(int n) {
		int res = 0;
		n *= 2;
		for (int k = 1; k * k < n; k++) {
			if (n % k != 0) continue;
			if ((n / k - (k - 1)) % 2 == 0) res++;
		}
		return res;
	}


public:
	// 使用前缀和加速，还是超时了
	int consecutiveNumbersSum_ziji(int n) {
		vector<long> preSum(n + 1);
		for (int i = 1; i <= n; i++) {
			preSum[i] = i + preSum[i - 1];
		}

		unordered_map<long, int> mp; // preSum index
		for (int i = 0; i <= n; i++) {
			mp[preSum[i]] = i;
		}

		int res = 0;
		for (int i = 0; i <= n; i++) {
			if (mp.count(preSum[i] - n) != 0) {
				res++;
			}
		}
		return res;
	}
};