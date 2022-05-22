// Created by rainyzwzhou on 2022/5/10.

/**
 题目:
 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 请你设计并实现时间复杂度为O(n) 的算法解决此问题。

 核心思想:
 我们考虑枚举数组中的每个数 xx，考虑以其为起点，不断尝试匹配 x+1, x+2, x+1,x+2,⋯ 是否存在，假设最长匹配到了 x+y，那么以 x 为起点的最长连续序列即为 x, x+1, x+2, x+y，其长度为 y+1，我们不断枚举并更新答案即可。

 优化:
 如果以x为起点，如果发现存在x-1，那么可以跳过x为起点过程，因为x-1肯定比x的要长
 */

#include <bits/stdc++.h>
#include "../../include.h"

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> innerSet;
		for(auto num : nums) innerSet.insert(num);

		int res = 0;
		for(auto element : innerSet) {
			if (innerSet.count(element - 1) != 0) { // 以x为起点，如果发现存在x-1，那么可以跳过x为起点过程，因为x-1肯定比x的要长
				continue;
			} else {
				int curNum = element;
				int oneRes = 1;

				while(innerSet.count(curNum + 1) != 0) {
					curNum++;
					oneRes++;
				}

				res = max(oneRes, res);
			}
		}

		return res;
	}
};



