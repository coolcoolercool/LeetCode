// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		int size = nums.size();
		deque<int> dQueue;
		for (int i = 0; i < k; ++i) {
			while (!dQueue.empty() && nums[i] >= nums[dQueue.back()]) {
				dQueue.pop_back();
			}
			dQueue.push_back(i);
		}

		vector<int> res;
		res.push_back(nums[dQueue.front()]);
		for (int i = k; i < size; ++i) {
			while (!dQueue.empty() && nums[i] >= nums[dQueue.back()]) {
				dQueue.pop_back();
			}
			dQueue.push_back(i);
			while (dQueue.front() <= i - k) {  // 如果窗口长度已经超过了k，则将最左边的元素移除
				dQueue.pop_front();
			}
			res.push_back(nums[dQueue.front()]);
		}
		return res;
	}

	vector<int> maxSlidingWindow_0(vector<int> &nums, int k) {
		vector<int> res;    // 使用双向队列
		deque<int> dQueue;
		for (int i = 0; i < nums.size(); ++i) {
			if (!dQueue.empty() && dQueue.front() == i - k) dQueue.pop_front();            //如果窗口长度已经超过了k，则将最左边的元素移除
			while (!dQueue.empty() && nums[i] > nums[dQueue.back()])
				dQueue.pop_back();            //从后往前移除所有队列中小于当前元素的元素
			dQueue.push_back(i);    //在队列中添加当前元素
			if (i + 1 >= k) res.push_back(nums[dQueue.front()]);    //如果窗口长度已经到达了k，则在结果中插入最大值(deque最前面的元素)
		}
		return res;
	}
};