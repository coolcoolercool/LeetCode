// Created by rainyzwzhou on 2022/5/2.

#include "../../include.h"

class Solution {
public:
	int mySqrt_BinarySearch(int x) {
		if (x <= 1) return x;
		int left = 0, right = x;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if (mid == x / mid) return mid;
			if(mid < x / mid) { // {mid + 1, right}
				if((mid + 1) > x / (mid + 1)) return mid;
				left = mid + 1;
			} else { // {left , mid - 1}
				right = mid - 1;
			}
		}
		return -1;
	}

	// 精确到指定位数，比如三位小数
	double mySqrt_BinarySearch_jinjie(int x) {
		double left = 0.0, right = x;
		while(left <= right) {
			double mid = left + (right - left) / 2;
			if(mid < x / mid) { // {mid + 1, right}
				left = mid + 1e-3;
			} else { // {left , mid - 1}
				right = mid - 1e-3;
			}
		}
		return right;
	}

public:
	int mySqrt_RedBlue(int x) {
		long long left = -1, right = (long long) x + 1;
		while(left + 1 != right) {
			long long mid = left + (right - left) / 2;
			if (mid * mid <= x) {
				left = mid;
			} else {
				right = mid;
			}
		}
		return left;
	}
};