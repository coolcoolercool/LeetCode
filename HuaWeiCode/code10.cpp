// Created by 周子望 on 2022/6/11.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

int main_code10() {
	string str;
	cin >> str;

	unordered_set<char> st;
	for(char ch : str) {
		st.insert(ch);
	}

	cout << st.size() << endl;

	return 0;
}