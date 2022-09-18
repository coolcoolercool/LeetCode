// Created by 周子望 on 2022/6/16.

/**
题目描述:

核心思想:
https://leetcode.cn/problems/k-diff-pairs-in-an-array/solution/by-ac_oier-ap3v/

**/

#include <bits/stdc++.h>
using namespace std;

// 排序加双指针
class Solution_ver1 {
public:
	int findPairs(vector<int>& nums, int k) {
		int res = 0;
		sort(nums.begin(), nums.end());


		return res;
	}
};

// 使用map存储数组中的元素和出现频率
// k 为 0：此时只能 (x, x) 组成数对，此时判断 x 出现次数是否大于 1 次，若满足则进行计数加一；
// k 不为 0：此时 x 能够与 a = x - k或 b = x + k 组成数对，分别查询 a 和 b 是否出现过，若出现过则进行计数加一。
class Solution_ver0 {
public:
	int findPairs(vector<int>& nums, int k) {
		int res = 0;
		map<int, int> mp;

		for(int num : nums) mp[num]++;

		if(k == 0) {
			for(auto& element : mp) {
				if(element.second > 1) {
					res++;
				}
			}
		} else { // k > 0
			for(auto& element : mp) {
				if(mp.count(element.first - k) != 0) {
					res++;
				}
			}
		}

		return res;
	}
};