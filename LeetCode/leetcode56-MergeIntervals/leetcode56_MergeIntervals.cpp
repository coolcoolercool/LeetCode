//
// Created by 周子望 on 2021/11/3.
//

/*
题目:
 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

 */

#include "../../include.h"

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() < 2) {
			return intervals;
		}

		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res;
		for (int i = 0; i < intervals.size(); i++) {
			int left = intervals[i][0], right = intervals[i][1];  // 当前第i个区间的左右边界
			if (res.empty() || res.back()[1] < left) {  // 如果 当前的右边 < next的左边，直接将 next 区间添加到结果中
				res.push_back({left, right});
			} else {
				res.back()[1] = max(res.back()[1], right); // 如果 当前的右边 >= next 的左边，更新当前的右边界 为 当前和next 区间的右边界的较大值
			}
		}

		return res;
	}
};

void test () {
	vector<vector<int>> sort_vec = {{1,4},{1,3}};

	sort(sort_vec.begin(), sort_vec.end());

	print_vector_vector(sort_vec);
}

int main_OMJN87 () {
	Solution sol;
	vector<vector<int>> intervals = {{1,4}, {4,5}};
	vector<vector<int>> res = sol.merge(intervals);

	print_vector_vector(res);

	intervals = {{1,3},{2,6},{8,10},{15,18}};
	res = sol.merge(intervals);;
	print_vector_vector(res);

	cout << endl;

	test();
	return 0;
}