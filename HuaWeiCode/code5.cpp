// Created by 周子望 on 2022/6/10.

/**
题目描述:
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

int CharToNum(char ch) {
	if(isdigit(ch)) {
		return ch - '0';
	} else {
		return ch - 'A' + 10;
	}
}

int main_plmn25() {
	string str;
	cin >> str;

	int size = str.size();
	int res = 0;
	for(int index = size - 1; index >= 2; index--) {
		res += (CharToNum(str[index])) * pow(16, size - index - 1);
	}

	cout << res << endl;
	return 0;
}

