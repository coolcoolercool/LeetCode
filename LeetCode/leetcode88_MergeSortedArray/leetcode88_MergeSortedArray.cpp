// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:


核心思想:
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	// 逆向双指针
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
		if (n == 0) return;
		int left = m - 1, right = n - 1, index = m + n - 1;
		while (left >= 0 && right >= 0) {
			if (nums1[left] < nums2[right]) {
				nums1[index--] = nums2[right--];
			} else {
				nums1[index--] = nums1[left--];
			}
		}

		while (left >= 0) {
			nums1[index--] = nums1[left--];
		}

		while (right >= 0) {
			nums1[index--] = nums2[right--];
		}
	}
};