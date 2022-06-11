// Created by 周子望 on 2022/6/11.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

int main_code11() {
	int num;
	cin >> num;

	string numStr = to_string(num);
	reverse(numStr.begin(), numStr.end());

	cout << numStr << endl;

	return 0;
}