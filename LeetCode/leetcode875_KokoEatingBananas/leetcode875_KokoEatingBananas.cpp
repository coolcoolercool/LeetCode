// Created by rainyzwzhou on 2022/6/7.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minEatingSpeed(vector<int> &piles, int h) { // H是总小时数目
		int maxVal = 1;
		for (int pile : piles) {
			maxVal = max(maxVal, pile);
		}

		int left = 1;        // 速度最小的时候，耗时最长
		int right = maxVal; // 速度最大的时候，耗时最短

		while (left < right) {
			int mid = left + (right - left) / 2;

			if (calculateSum(piles, mid) > h) {
				// 耗时太多，说明速度太慢了，下一轮搜索区间是 [mid + 1..right]
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return left;
	}

	/**
     * 如果返回的小时数严格大于 H，就不符合题意
     *
     * @param piles
     * @param speed
     * @return 需要的小时数
     */
	int calculateSum(vector<int> &piles, int speed) {
		int sum = 0;
		for (int pile : piles) {
			sum += (pile + speed - 1) / speed;            // 上取整可以这样写
		}
		return sum;
	}
};

