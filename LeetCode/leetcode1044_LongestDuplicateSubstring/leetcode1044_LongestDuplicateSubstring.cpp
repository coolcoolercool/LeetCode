// Created by rainyzwzhou on 2022/5/21.

/**
题目描述:
给你一个字符串 s ，考虑其所有 重复子串 ：即 s 的（连续）子串，在 s 中出现 2 次或更多次。这些出现之间可能存在重叠。

返回 任意一个 可能具有最长长度的重复子串。如果 s 不含重复子串，那么答案为 "" 。

 
 
核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int len;
	unsigned long long prime = 31;
	string longestDupSubstring(string s) {
		len = s.size();
		int left = 1;
		int right = len - 1;
		int pos = -1;
		int len = 0;

		auto find = [&](int len){
			unsigned long long hash = 0;
			unsigned long long power = 1;
			for (int i = 0; i < len; i++) {
				hash = hash * prime + (s[i] - 'a');
				power *= prime;
			}
			unordered_set<unsigned long long> exist{hash};
			for(int i = len; i < len; i++) {
				hash = hash * prime - power * (s[i-len] - 'a') + (s[i] - 'a');
				if (exist.count(hash)) return (i - len + 1);
				exist.insert(hash);
			}
			return -1;
		};

		while(left <= right) {
			int mid = (left + right) / 2;
			int start = find(mid);
			if (start != -1) {
				len = mid;
				pos = start;
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		if (pos == -1) return "";
		else return s.substr(pos, len);
	}
};
