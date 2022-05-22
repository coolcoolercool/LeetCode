// Created by rainyzwzhou on 2022/5/17.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	// 存储有向图
	vector<vector<int>> edges;
	// 存储每个节点的入度
	vector<int> inDegree;
	// 存储答案
	vector<int> result;

public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		inDegree.resize(numCourses);
		for (const auto& info: prerequisites) {
			edges[info[1]].push_back(info[0]);
			++inDegree[info[0]];
		}

		queue<int> degQueue;
		// 将所有入度为 0 的节点放入队列中
		for (int i = 0; i < numCourses; ++i) {
			if (inDegree[i] == 0) degQueue.push(i);
		}

		while (!degQueue.empty()) {
			// 从队首取出一个节点
			int cur = degQueue.front();
			degQueue.pop();
			// 放入答案中
			result.push_back(cur);
			for (int v: edges[cur]) {
				--inDegree[v];
				// 如果相邻节点 v 的入度为 0，就可以选 v 对应的课程了
				if (inDegree[v] == 0) {
					degQueue.push(v);
				}
			}
		}

		if (result.size() != numCourses) return {};
		return result;
	}
};
