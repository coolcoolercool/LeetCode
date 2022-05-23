// Created by rainyzwzhou on 2022/5/23.

/**
题目描述:
给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。


核心思想:
https://leetcode.cn/problems/insert-interval/solution/shou-hua-tu-jie-57-cha-ru-qu-jian-fen-cheng-3ge-ji/

逐个分析
1. 不重叠，需满足：绿区间的右端，位于蓝区间的左端的左边，如[1,2]。
(1)则当前绿区间，推入 res 数组，指针 +1，考察下一个绿区间。
(2)循环结束时，当前绿区间的屁股，就没落在蓝区间之前，有重叠了，如[3,5]。

2. 现在看重叠的。我们反过来想，没重叠，就要满足：绿区间的左端，落在蓝区间的屁股的后面，反之就有重叠：绿区间的左端 <= 蓝区间的右端，极端的例子就是[8,10]。
(1)和蓝有重叠的区间，会合并成一个区间：左端取蓝绿左端的较小者，右端取蓝绿右端的较大者，不断更新给蓝区间。
(2)循环结束时，将蓝区间（它是合并后的新区间）推入 res 数组。

3. 剩下的，都在蓝区间右边，不重叠。不用额外判断，依次推入 res 数组。


**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		int index = 0;
		int size = intervals.size();
		int newStart = newInterval[0], newEnd = newInterval[1];

		// end < newStart < newEnd
		while(index < size && intervals[index][1] < newStart) { // 当前遍历的是蓝左边的，不重叠的区间
			res.push_back(intervals[index]);
			index++;
		}

		//  start <= newEnd
		while(index < size && intervals[index][0] <= newEnd) {  // 当前遍历是有重叠的区间
			newStart = min(intervals[index][0], newStart);  // 左端取较小者，更新给兰区间的左端
			newEnd = max(intervals[index][1], newEnd);      // 右端取较大者，更新给兰区间的右端
			index++;
		}
		res.push_back({newStart, newEnd}); // 循环结束后，兰区间为合并后的区间，推入res

		while(index < size) {  // 在蓝右边，没重叠的区间
			res.push_back(intervals[index]);
			index++;
		}

		return res;
	}
};