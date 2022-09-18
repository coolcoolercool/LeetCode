// Created by 周子望 on 2021/9/25.

#ifndef HELLOTEST_INCLUDE_LIB_H
#define HELLOTEST_INCLUDE_LIB_H

#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <string>

#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {};
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

struct Node {
	int val;
	Node *left;
	Node *right;
	Node() : val(0), left(nullptr), right(nullptr) {};
	Node(int x) : val(x), left(nullptr), right(nullptr) {};
	Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {};
};


class NestedInteger {
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

template <typename T>
void print_vector_vector(vector<vector<T>> nums) {
	cout << endl;
	for (auto vec : nums) {
		cout << "< ";
		for (auto element : vec) {
			cout << element << ",";
		}
		cout << " >" << endl;
	}
	cout << endl;
}

template <typename T>
inline void print_vector(vector<T> nums, string msg = "") {
	cout << msg << " ";
	for (auto element : nums) {
		cout << element << " ";
	}
	cout << endl;
}


inline void print_bool (bool flag) {
	if (flag) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
}

inline void print_set(const set<char>& set_char) {
	for (auto element : set_char) {
		cout << element << ", ";
	}
	cout << endl;
}

inline void print_list(list<int>* int_list) {
	for (auto iter = int_list->begin(); iter != int_list->end(); iter++) {
		cout << *iter << ", ";
	}
	cout << endl;
}

#endif //HELLOTEST_INCLUDE_LIB_H
