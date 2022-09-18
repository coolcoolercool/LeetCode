// Created by 周子望 on 2022/6/13.

/**
题目描述:
https://leetcode.cn/problems/brick-wall/

核心思想:
题目中说的砖的边沿，指的就是每块砖的边界，
比如这一层的砖的长度为{1,2,2,1}
那么在1，3和5都有，砖的边界，此时从这个边界往下走就不算穿过砖头

思路:
map 记录缝隙，注意每行的最后一个砖块不加入，遍历完之后找最多缝隙的通道，然后用层数减去最多缝隙数即可得到最少穿砖数。

**/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	int leastBricks(vector<vector<int>> &wall) {
		int size = wall.size();
		unordered_map<int, int> mp; // 出现的边沿所在的索引位置，和出现的次数
		for (int i = 0; i < size; i++) {
			int sum = 0;
			for (int cur: wall[i]) {
				sum += cur;
				mp[sum]++;
			}
			mp.erase(sum); // 不能从两边穿过，需要 remove 掉最后一个
		}

		int res = size; // 初始化，最多不会超过 size 层砖
		for (auto &onePair: mp) {
			res = min(res, size - onePair.second);
		}
		return res;
	}
};
