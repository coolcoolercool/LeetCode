// Created by rainyzwzhou on 2022/5/13.

/**
题目描述:

核心思想:
 按照身高从大到小排序（身高相同的情况下K小的在前面），这样的话，无论哪个人的身高都小于等于他前面人的身高。所以接下来只要按照K值将他插入相应的位置就可以了
 只要按照K值将他插入相应的位置就可以了。 解释： 因为前面的每个人身高都比它大， 但是他前面只能有 K 个人大于等于它的身高，所以他只能放在第K个位置。

 eg
 原数组
< 7,0, >< 4,4, >< 7,1, >< 5,0, >< 6,1, >< 5,2, >

 排序后的位置
< 7,0, >< 7,1, >< 6,1, >< 5,0, >< 5,2, >< 4,4, >

 依次根据排序的数组，插入到结果队列中
 根据ki的值插入到对应的位置

< 7,0, >
< 7,0, >< 7,1, >
< 7,0, >< 6,1, >< 7,1, >
< 5,0, >< 7,0, >< 6,1, >< 7,1, >
< 5,0, >< 7,0, >< 5,2, >< 6,1, >< 7,1, >
< 5,0, >< 7,0, >< 5,2, >< 6,1, >< 4,4, >< 7,1, >
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	static bool cmp(vector<int> &left, vector<int> &right) {
		if (left[0] == right[0]) return left[1] < right[1];
		return left[0] > right[0];
	}

public:
	vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
		int n = people.size();
		sort(people.begin(), people.end(), cmp);
		vector<vector<int> > res;

		for (int i = 0; i < n; i++) {
			int pos = people[i][1];
			res.insert(res.begin() + pos, people[i]);
		}
		return res;
	}
};

