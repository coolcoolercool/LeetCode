// Created by rainyzwzhou on 2022/6/3.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<string> ans;

void dfs(int n, int cur, string s) {
	if (cur == n) {
		cnt++;
		ans.push_back(s);
		return;
	}
	if (cur > n) return;
	dfs(n, cur + 1, s + to_string(cur + 1));
	dfs(n, cur + 2, s + to_string(cur + 2));
}

int main_0ok1km() {
	int n;
	cin >> n;
	dfs(n, 0, "0");
	cout << cnt << endl;
	for (auto &s : ans) {
		cout << s << endl;
	}
}