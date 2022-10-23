// Created by 周子望 on 2022/10/23.
#include "../../include.h"

/**
题目描述:

核心思想:
https://leetcode.cn/problems/h-index/solutions/869042/h-zhi-shu-by-leetcode-solution-fnhl/
**/

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int size = citations.size();
		int res = 0;
		vector<int> counter(size + 1);

		for(int i = 0; i < size; i++) {
			if (citations[i] >= size) {
				counter[size]++;
			} else {
				counter[citations[i]]++;
			}
		}

		for(int i = size; i >= 0; i--) {
			res += counter[i];
			if (res >= i) {
				return i;
			}
		}

		return 0;
	}

	// 排序
	int hIndex_ziji(vector<int>& citations) {
		int size = citations.size();
		sort(citations.begin(), citations.end());

		int res = 0;
		for(int i = 0; i < size; i++) {
			if (i > 0 && citations[i] == citations[i - 1]) {
				continue;
			}
			int hIndex = min(citations[i], size - i);
			res = max(hIndex, res);
		}

		return res;
	}
};