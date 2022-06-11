// Created by 周子望 on 2022/6/11.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

int main_code8() {
	int size = 0;
	cin >> size;
	map<int, int> inMp;

	for(int i = 0; i < size; i++) {
		int key, value;
		cin >> key, cin >> value;
		inMp[key] += value;
	}

	for(auto& element : inMp) {
		cout << element.first << " " << element.second << endl;
	}

	return 0;
}

/**
4
0 1
0 2
1 2
3 4

**/