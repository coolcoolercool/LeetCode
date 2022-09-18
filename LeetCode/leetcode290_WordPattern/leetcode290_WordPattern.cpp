// Created by 周子望 on 2022/6/12.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<string, char> str2ch; // str 的单词映射到 pattern的每个字符
		unordered_map<char, string> ch2str; // pattern的每个字符映射到 str的每一个单词

		int strSize = str.length();
		int startIndex = 0; // str 中每个单词的开始索引位置
		for (auto ch : pattern) {
			if (startIndex >= strSize) { // 说明单词数量和字符数量不相等，字符数量多
				return false;
			}

			int j = startIndex; // str 每个单词后的空格
			while (j < strSize && str[j] != ' ') j++; // 一种是到字符串末尾，一种是索引j对应的字符为 ' '
			const string &word = str.substr(startIndex, j - startIndex); // 单词索引范围为 [startIndex, j - 1],索引j对应的是' '

			if (str2ch.count(word) && str2ch[word] != ch) {
				return false;
			}

			if (ch2str.count(ch) && ch2str[ch] != word) {
				return false;
			}

			str2ch[word] = ch;
			ch2str[ch] = word;

			startIndex = j + 1; // 偏移到下一个单词的开始处，即' '后的一个索引位置
		}

		return startIndex == strSize + 1; // 如果遍历完所有字符以后，此时如果str也遍历完了，则此时startIndex == strSize + 1
	}
};


// 将字符和字符串的归路映射到一个规律数组中，对比两个数组是否相等
class Solution_ziji {
public:
	bool wordPattern(string pattern, string s) {
		int pSize = pattern.size();
		vector<int> pVec(pSize);
		unordered_map<char, int> pMp;

		int cnt = 0;
		for(int i = 0; i < pSize; i++) {
			if(pMp.count(pattern[i]) == 0) {
				pMp[pattern[i]] = cnt;
				pVec[i] = cnt;
				cnt++;
			} else {
				pVec[i] = pMp[pattern[i]];
			}
		}

		int sSize = s.size();
		vector<int> sVec;
		unordered_map<string, int> sMp;

		cnt = 0;
		int startIndex = 0, wordCount = 0;
		for(int i = 0; i < sSize; i++) {
			if(s[i] == ' ' || i == sSize - 1) {
				string str;
				if(i == sSize - 1) {
					str = s.substr(startIndex);
				} else {
					str = s.substr(startIndex, i - startIndex);
				}

				if(sMp.count(str) == 0) {
					sMp[str] = cnt;
					sVec.push_back(cnt);
					cnt++;
				} else {
					sVec.push_back(sMp[str]);
				}
				startIndex = i + 1;
				wordCount++;
			}
		}

		if(pVec != sVec) {
			return false;
		}
		return true;
	}
};