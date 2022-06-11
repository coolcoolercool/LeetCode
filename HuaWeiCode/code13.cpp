// Created by 周子望 on 2022/6/11.

/**
题目描述:
https://www.nowcoder.com/practice/48b3cb4e3c694d9da5526e6255bb73c3?tpId=37&tqId=21236&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

int main_code13() {
	string str;
	vector<string> res;
	while(cin >> str) {
		res.push_back(str);
	}

	reverse(res.begin(), res.end());
	for(string& str : res) {
		cout << str << " ";
	}

	return 0;
}