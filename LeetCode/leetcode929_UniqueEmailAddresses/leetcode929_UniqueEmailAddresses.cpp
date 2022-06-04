// Created by rainyzwzhou on 2022/6/4.

/**
题目描述:

核心思想:
直接模拟规则即可
使用两个flag表示 + 后面的不取 和 @ 后面的规则不再使用
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string help(string &email) {
		int size = email.size();
		string realEmail;
		bool flagAt = false;
		bool flagPlus = false;
		for (int i = 0; i < size; i++) {
			if (flagAt) { // @以后的字符直接添加即可
				realEmail.push_back(email[i]);
				continue;
			}

			if (email[i] == '.') {
				continue;
			} else if (email[i] == '+') {
				flagPlus = true;
			} else if (email[i] == '@') {
				flagAt = true;
				flagPlus = false;
				realEmail.push_back(email[i]);
			} else {
				if (!flagPlus) {
					realEmail.push_back(email[i]);
				}
			}
		}

		return realEmail;
	};

	int numUniqueEmails(vector<string> &emails) {
		unordered_set<string> st;
		for (auto &email : emails) {
			st.insert(help(email));
		}

		return (int) st.size();
	}
};