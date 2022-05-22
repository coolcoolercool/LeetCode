// Created by rainyzwzhou on 2022/5/16.

/**
题目描述:

核心思想:

 滑动窗口的心法（核心思想）
（1）初始化双指针left和right。【初始化】
（2）先不断增加right扩大窗口，直到窗口中的内容符合要求。【寻找可行解】
（3）停止增加right，不断增加left缩小窗口，直到窗口中的内容不再满足要求。在每次增加left时都要更新所求的结果。【优化可行解】

不断重复扩大窗口、缩小窗口的操作，直到right到达序列的末端。

具体而言，以本题为例：
（1）在s中使用双指针left、right，初始化left = right = 0。
（2）先不断增加right扩大窗口，直到窗口中的字符串符合要求（包含t中的所有字符串）。【寻找可行解】
（3）此时停止增加right，转而不断增加left缩小窗口，直到窗口中的字符串不再符合要求（不包含t中的所有字符串了）。同时，每次增加left都要更新一轮结果。【优化可行解】
（4）重复第2步和第3步，直到right到达字符串的尽头。

https://leetcode.cn/problems/minimum-window-substring/solution/leetcode-76-zui-xiao-fu-gai-zi-chuan-cja-lmqz/

**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	unordered_map<char, int> sHash, tHash;

	string minWindow(string s, string t) {
		for (auto e: t) tHash[e]++;
		string res;

		int cnt = 0, left = 0, right = 0;
		for (; right < s.size(); right++) {
			sHash[s[right]]++;
			if (sHash[s[right]] <= tHash[s[right]]) cnt++; // 表示满足条件的字符数，cnt=t.size(),表示s的子串已经包含t

			while (sHash[s[left]] > tHash[s[left]]) { // 如果出现不满足的情况，移除left，则left++，
				sHash[s[left]]--;
				left++;
			}

			if (cnt == t.size()) {
				if (res.empty() || right - left + 1 < res.size()) // 记录包含t的最小子串
					res = s.substr(left, right - left + 1);
			}
		}
		return res;
	}
};

