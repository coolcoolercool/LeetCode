// Created by rainyzwzhou on 2022/5/11.

/**
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canMakeArithmeticProgression(vector<int>& arr) {
		if (arr.size() < 3) {  // 等差数列至少有三项,数学定义
			return false;
		}

		sort(arr.begin(), arr.end());

		int diff = arr[1] - arr[0];
		for(int i = 1; i < arr.size(); i++) {
			if(arr[i] != arr[0] + i * diff) return false;
		}

		return true;
	}
};

