// Created by rainyzwzhou on 2022/6/9.

/**
题目描述:
在给定一个字符串str，在给定一个target字符串
在str中寻找，是否存在，跟target字符串的字符和数量是相等，如果有则返回符合子串的开始的索引，如果没有则返回-1
 即比如
 target = "abc"
 str = "ccab"
 那么cab是符合，类似于异位词

 target字符串，中字符可能存在重复

核心思想:
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int findTarget(string &str, string &target) {
		int strSize = str.size();
		int targetSize = target.size();

		if (strSize < targetSize) return -1;

		// 使用两个26长度的数组来存储
		vector<int> strVec(26);
		vector<int> targetVec(26);
		for (char e : target) {
			targetVec[e - 'a']++;
		}

		int left = 0, right = 0;
		int cnt = 1;
		strVec[str[0] - 'a']++;
		while (left <= right && right < strSize) {
			if (cnt == targetSize) {
				if (strVec == targetVec) {
					return left;
				} else {
					strVec[str[left] - 'a']--;
					left++;
					cnt--;
				}
			} else if (cnt < targetSize) {
				right++;
				if (right < strSize) {
					strVec[str[right] - 'a']++;
					cnt++;
				}
			}
		}

		return -1;
	}


};

