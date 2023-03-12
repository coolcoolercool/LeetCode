// Created by 周子望 on 2023/2/26.

/**
题目描述:
有序数组中中找指定的值
(二分查找)

核心思想:
**/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int findTargetInSortedVector(vector<int>& vec, int target) {
		int size = vec.size();
		if (size < 1) return -1;

		int left = 0, right = size;
		while(left <= right) {
			int mid = left + (right - left)/2;
			if (vec[mid] == target) return mid;
			else if (vec[mid] < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return -1;
	}
};

