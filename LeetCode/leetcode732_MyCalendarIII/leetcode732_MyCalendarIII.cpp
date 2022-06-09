// Created by rainyzwzhou on 2022/6/6.

/**
题目描述:
https://leetcode.cn/problems/my-calendar-iii/

核心思想:
https://leetcode.cn/problems/my-calendar-iii/solution/wo-de-ri-cheng-an-pai-biao-iii-by-leetco-9rif/
差分数组

**/

#include <bits/stdc++.h>

using namespace std;

class MyCalendarThree {
private:
	map<int, int> mp; // 记录start和end的个数。需要用有序的mp

public:
	MyCalendarThree() {}

	int book(int start, int end) {
		int res = 0;
		int maxBook = 0;
		mp[start]++;
		mp[end]--;
		for (auto &item: mp) {
			maxBook += item.second;
			res = max(maxBook, res);
		}
		return res;
	}
};

