// Created by rainyzwzhou on 2022/5/14.

/**
题目描述:

核心思想:
 使用一个map记录到目前索引位置的前缀和和出现的次数，每次更新前，检查curSum - k，满足从索引A到索引B，和为k的有多少个，累加到结果中。初始化一个都不取，满足{0, 1}
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> innerMap;
		innerMap.insert({0, 1});
		int curSum = 0, res = 0;
		for(int i = 0; i < nums.size(); i++) {
			curSum += nums[i];
			if(innerMap.count(curSum - k) != 0) {
				res += innerMap[curSum - k];
			}
			innerMap[curSum]++;
		}

		return res;
	}
};