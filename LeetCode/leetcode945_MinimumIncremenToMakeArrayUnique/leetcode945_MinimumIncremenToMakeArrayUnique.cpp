// Created by rainyzwzhou on 2022/5/22.

/**
题目描述:
给你一个整数数组 nums 。每次 move 操作将会选择任意一个满足 0 <= i < nums.length 的下标 i，并将nums[i] 递增1。
返回使 nums 中的每个值都变成唯一的所需要的最少操作次数。

核心思想:
 https://leetcode.cn/problems/minimum-increment-to-make-array-unique/solution/ji-shu-onxian-xing-tan-ce-fa-onpai-xu-onlogn-yi-ya/

 计数排序，然后让每个桶只有一个数字，多余数字，放到右边最近的桶中
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {

	// On级别
public:
	int minIncrementForUnique(vector<int> &nums) {
		vector<int> count(10000, 0);
		int maxNum = 0;
		int res = 0;

		// counter数组统计每个数字的个数。
		//（这里为了防止下面遍历counter的时候每次都走到40000，所以设置了一个max，这个数据量不设也行，再额外设置min也行）
		for (auto num : nums) {
			count[num]++;
			maxNum = max(maxNum, num);
		}

		// 遍历count数组，若当前数字的个数cnt大于1个，则只留下1个，其他的cnt-1个后移
		for (int i = 0; i < maxNum; i++) {
			if (count[i] > 1) {
				res += count[i] - 1;
				count[i + 1] = count[i] - 1;
			}
		}

		// 最后, counter[max+1]里可能会有从counter[max]后移过来的，counter[max+1]里只留下1个，其它的d个后移。
		// 设 max+1 = x，那么后面的d个数就是[x+1,x+2,x+3,...,x+d],
		// 因此操作次数是[1,2,3,...,d],用求和公式求和。
		if (count[maxNum] > 1) {//也可以换成 20000 的数组
			int d = count[maxNum] - 1;
			res += (d + 1) * d / 2;
		}
		return res;
	}

	// 不会超时 nlogn
public:
	int minIncrementForUnique_1(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int resMove = 0;
		for(int i = 1; i < nums.size(); i++) {
			if(nums[i - 1] >= nums[i]) {
				int start = nums[i];
				nums[i] = nums[i - 1] + 1;
				resMove += nums[i] - start;
			};
		}

		return resMove;
	}

	// 计数方法，会超时
public:
	int minIncrementForUnique_0(vector<int>& nums) {
		unordered_set<int> st;
		vector<int> dupVec; // 保存重复出现的元素的元素

		for(int i = 0; i < nums.size(); i++) {
			if(st.count(nums[i])) {
				dupVec.push_back(i);
			} else {
				st.insert(nums[i]);
			}
		}

		int res = 0;
		for(int i = 0; i < dupVec.size(); i++) {
			int num = nums[dupVec[i]];
			while(st.count(num) != 0) {
				num++;
				res++;
			}
			st.insert(num);
		}

		return res;
	}
};