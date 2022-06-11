// Created by 周子望 on 2022/6/11.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

int main_code14() {
	int size;
	cin >> size;
	vector<string> vec;
	for(int i = 0; i < size; i++) {
		string str;
		cin >> str;
		vec.push_back(str);
	}

	sort(vec.begin(), vec.end());
	for(string& str : vec) {
		cout << str << endl;
	}

	return 0;
};
