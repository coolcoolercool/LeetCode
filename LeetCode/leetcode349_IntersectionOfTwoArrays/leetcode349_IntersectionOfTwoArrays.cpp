// Created by rainyzwzhou on 2022/5/21.

/**
题目描述:
https://leetcode.cn/problems/intersection-of-two-arrays/
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

public:
	vector<int> intersection_0(vector<int>& nums1, vector<int>& nums2) {
		vector<int> hashNum1(1001);
		vector<int> hashNum2(1001);
		for(int i = 0; i < nums1.size(); i++) {
			hashNum1[nums1[i]]++;
		}

		vector<int> res;
		for(int i = 0; i < nums2.size(); i++) {
			hashNum2[nums2[i]]++;
		}

		for(int i = 0; i < 1001; i++) {
			if(hashNum1[i] > 0 && hashNum2[i] > 0) res.push_back(i);
		}

		return res;
	}
};