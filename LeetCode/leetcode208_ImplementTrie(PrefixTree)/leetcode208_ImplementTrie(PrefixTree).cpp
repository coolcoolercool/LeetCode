// Created by rainyzwzhou on 2022/5/30.

/**
题目描述:
https://leetcode.cn/problems/implement-trie-prefix-tree/
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

核心思想:
**/

#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
	vector<Trie *> children;
	bool isEnd;

	Trie *searchPrefix(string prefix) {
		Trie *node = this;
		for (char ch : prefix) {
			ch -= 'a';
			if (node->children[ch] == nullptr) {
				return nullptr;
			}
			node = node->children[ch];
		}
		return node;
	}

public:
	Trie() : children(26), isEnd(false) {}

	void insert(string word) {
		Trie *node = this;
		for (char ch : word) {
			ch -= 'a';
			if (node->children[ch] == nullptr) {
				node->children[ch] = new Trie();
			}
			node = node->children[ch];
		}
		node->isEnd = true;
	}

	bool search(string word) {
		Trie *node = this->searchPrefix(word);
		return node != nullptr && node->isEnd;
	}

	bool startsWith(string prefix) {
		return this->searchPrefix(prefix) != nullptr;
	}
};

