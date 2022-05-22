// Created by rainyzwzhou on 2022/5/13.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		int sSize = s.size(), pSize = p.size();
		if (sSize < pSize) return res;

		// 统计目标的单词的每个元素和对应的个数
		vector<int> pHash(26, 0);
		for (int i = 0; i < p.size(); i++) {
			pHash[p[i] - 'a']++;
		}

		vector<int> sHash(26, 0);
		int left = 0, right = 0;
		for(; right < sSize; right++) {
			sHash[s[right] - 'a']++;
			if( right - left + 1 < pSize) {
				continue;
			} else if(right - left + 1 == pSize){
				if(pHash == sHash) res.push_back(left);
				sHash[s[left] - 'a']--;
				left++;
			}
		}

		return res;
	}
};
