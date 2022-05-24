//
// Created by 周子望 on 2021/11/2.
//

/*
题目:
 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

 */

#include "../../include.h"

/*

class Solution {
public:
	// 优先队列 使用 的比较器
	struct compare {
		bool operator() (vector<int> vec1, vector<int> vec2) {
			if (vec1[0] > vec2[0]) {
				return vec1[0] > vec2[0];
			} else if (vec1[0] == vec2[0]) {
				return vec1[1] > vec2[1];
			} else if (vec1[0] < vec2[0]) {
				vec1[0] < vec2[0];
			}
		}
	};

	priority_queue<vector<int>, vector<vector<int>>, compare> queue;

	// sort 排序函数使用的比较函数
	static bool compare (const vector<int>& vec1, const vector<int>& vec2) {
		if (vec1[0] < vec2[0]) {
			return vec1[0] < vec2[0];
		} else if (vec1[0] == vec2[0]) {
			return vec1[1] < vec2[1];
		}
	}

public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() < 2) {
			return intervals;
		}

		for (auto element : intervals) {
			queue.push(element);
		}

		intervals.clear();

		vector<int> last_top = queue.top();
		vector<int> cur_top;


		while (!queue.empty()) {
			cur_top = queue.top();

			if (last_top[1] < cur_top[0]) {
				intervals.push_back(last_top);
				last_top = cur_top;
				if (!queue.empty()) {
					queue.pop();
				}
			} else if (last_top[1] >= cur_top[0] && last_top[1] <= cur_top[1]) {
				cur_top[0] = last_top[0];
				last_top = cur_top;

				if (!queue.empty()) {
					queue.pop();
				}
			}
		}

		intervals.push_back(cur_top);

		return intervals;
	}
};

void test () {
	struct compare {
		bool operator() (vector<int> vec1, vector<int> vec2) {
			if (vec1[0] > vec2[0]) {
				return vec1[0] > vec2[0];
			} else if (vec1[0] == vec2[0]) {
				return vec1[1] > vec2[1];
			}
		}
	};

	priority_queue<vector<int>, vector<vector<int>>, compare> queue;

	vector<vector<int>> intervals = {{1,4}, {4,5}};

	for (auto element : intervals) {
		queue.push(element);
	}

	while (!queue.empty()) {
		print_vector(queue.top());
		queue.pop();
	}
}


int main () {
	Solution sol;
	vector<vector<int>> intervals = {{1,4}, {4,5}};
	vector<vector<int>> res = sol.merge(intervals);

	print_vector_vector(res);

	intervals = {{1,3},{2,6},{8,10},{15,18}};
	res = sol.merge(intervals);;
	print_vector_vector(res);

	//test();
	return 0;
}
 */