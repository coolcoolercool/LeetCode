// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/solution/by-elliefeng-ip3d/

**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int shortestSubarray(vector<int> &nums, int k) {
		int size = nums.size();
		vector<long long> prefixSum(size + 1);
		for (int i = 1; i <= size; ++i) {
			prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
		}

		deque<int> q;
		q.push_back(0);
		int res = INT_MAX;
		for (int i = 1; i <= size; ++i) {
			while (q.size() && prefixSum[i] - prefixSum[q.front()] >= k) {
				res = min(res, i - q.front());
				q.pop_front();
			}
			while (q.size() && prefixSum[q.back()] > prefixSum[i]) {
				q.pop_back();
			}
			q.push_back(i);
		}
		if (res == INT_MAX) return -1;
		return res;
	}
};