// Created by rainyzwzhou on 2022/5/11.
/**
 题目描述:

 核心思想:
 https://leetcode.cn/problems/course-schedule/solution/ke-cheng-biao-by-leetcode-solution/
 拓扑排序

学习拓扑排序的思路
（1）统计入度inDegree, 统计有向边的关系unordered_map<int, vector<int>> mp;
（2）将所有入度为0的加入q
（3）每次从q中取出一个节点（代表可以直接选这门课），然后将q所指向的节点的入度-1，如果入度变为了0，则加入q
（4）只要q不为空，则一直处理下去。

 C -> A -> B
 B的入度是1，出度是0
 A的入度是1，出度是1
 C的入度是0，出度是1

 这里入度为0，表示

 **/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	unordered_map<int, vector<int>> mp; // 统计邻接关系，指向关系

	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		vector<int> inDeVec(numCourses, 0); // 节点就是对应索引 0~n-1， 索引对应的值就是节点的入度
		queue<int> degQueue; // 记录入度为0的节点集合

		for (auto item: prerequisites) { // [1,2] 表示需要先学2，才能学1，即 2->1
			++inDeVec[item[0]]; // 因为有1->0，所以0的入度加一
			mp[item[1]].push_back(item[0]); // item[1] 指向 item[0]
		}

		for (int i = 0; i < inDeVec.size(); ++i) { // 将入度为0的节点拿出来，因为可以直接学习
			if (inDeVec[i] == 0) degQueue.push(i);  // 注意这里添加的是 节点，也就是索引，而不是索引对应的value值
		}

		int count = 0;  // 记录所选的课程数
		while (!degQueue.empty()) {
			// 取出此时入度为0的一个节点， 将该节点所指向的节点的入度-1， 然后如果入度为0， 则添加到queue中
			int cur = degQueue.front();
			degQueue.pop();
			++count;

			for (auto element: mp[cur]) { // 遍历此节点直接连接的后续节点，将它们的入度减一
				--inDeVec[element];
				if (inDeVec[element] == 0) {
					degQueue.push(element);
				}
			}
		}

		return count == numCourses; // 这里不能使用 queue是否empty为判断，因为可能一开始就没有入度为0的节点
	}


};








