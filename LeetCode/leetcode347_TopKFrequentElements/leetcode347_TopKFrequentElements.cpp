// Created by rainyzwzhou on 2022/5/13.

/**
题目描述:

核心思想:
 首先遍历整个数组，并使用哈希表记录每个数字出现的次数，并形成一个「出现次数数组」。找出原数组的前 kk 个高频元素，就相当于找出「出现次数数组」的前 kk 大的值。
最简单的做法是给「出现次数数组」排序。但由于可能有 O(N) 个不同的出现次数（其中 NN 为原数组长度），故总的算法复杂度会达到 O(NlogN)，不满足题目的要求。
在这里，我们可以利用堆的思想：建立一个小顶堆，然后遍历「出现次数数组」：

（1）如果堆的元素个数小于 k，就可以直接插入堆中。
（2）如果堆的元素个数等于 k，则检查堆顶与当前出现次数的大小。如果堆顶更大，说明至少有 k 个数字的出现次数比当前值大，故舍弃当前值；否则，就弹出堆顶，并将当前值插入堆中。
（3）遍历完成后，堆中的元素就代表了「出现次数数组」中前 kk 大的值。
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct Comp {
		bool operator()(pair<int, int> &left, pair<int, int> &right) {
			return left.second > right.second;//小顶堆是大于号
		}
	};

	vector<int> topKFrequent(vector<int> &nums, int k) {
		//1.map记录元素出现的次数
		unordered_map<int, int> mp;//两个int分别是元素和出现的次数
		for (auto &element:nums) {
			mp[element]++;
		}
		//2.利用优先队列，将出现次数排序
		//自定义优先队列的比较方式，小顶堆

		//创建优先队列
		priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pQueue;
		//遍历map中的元素
		//1.管他是啥，先入队列，队列会自己排序将他放在合适的位置
		//2.若队列元素个数超过k，则将栈顶元素出栈（栈顶元素一定是最小的那个）
		for (auto &onePair : mp) {
			pQueue.push(onePair);
			if (pQueue.size() > k) pQueue.pop();
		}
		//将结果导出
		vector<int> res;
		while (!pQueue.empty()) {
			res.emplace_back(pQueue.top().first);
			pQueue.pop();
		}

		return res;
	}
};
