// Created by rainyzwzhou on 2022/6/9.

/**
题目描述:
https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/

核心思想:
https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/solution/shui-tang-chou-yang-by-xiaohu9527-7b3d/
**/

#include <bits/stdc++.h>

using namespace std;


// 水塘抽样
class Solution_ver0 {
private:
	vector<vector<int>> rectVec;
public:
	Solution_ver0(vector<vector<int>> &rects) {
		rectVec = rects;
	}

	vector<int> pick() {
		int idx = -1, cur = 0, curSum = 0, size = rectVec.size();
		for (int i = 0; i < size; ++i) {
			int x1 = rectVec[i][0], y1 = rectVec[i][1], x2 = rectVec[i][2], y2 = rectVec[i][3];
			cur = (x2 - x1 + 1) * (y2 - y1 + 1); // cur当前正方形下有多少个点
			curSum += cur; // 记录加上当前正方形的点，总共有多少点
			if (rand() % curSum < cur) // 在当前所有的点中随机选择一个点
				idx = i;
		}

		int x1 = rectVec[idx][0], y1 = rectVec[idx][1], x2 = rectVec[idx][2], y2 = rectVec[idx][3];

		return {x1 + rand() % (x2 - x1 + 1), y1 + rand() % (y2 - y1 + 1)};
	}
};

// 前缀和
class Solution {
private:
	vector<vector<int>> rects;
	vector<int> preS;
public:
	Solution(vector<vector<int>> &rects) {
		this->rects = rects;
		preS.push_back(0);
		for (auto &rec : rects) {
			int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];
			preS.push_back(preS.back() + (x2 - x1 + 1) * (y2 - y1 + 1));
		}
	}

	vector<int> pick() {
		int w = rand() % preS.back() + 1;
		int l = 0, r = preS.size() - 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (preS[mid] < w)
				l = mid + 1;
			else
				r = mid;
		}
		--l;
		int x1 = rects[l][0], y1 = rects[l][1], x2 = rects[l][2], y2 = rects[l][3];
		return {x1 + rand() % (x2 - x1 + 1), y1 + rand() % (y2 - y1 + 1)};
	}
};
