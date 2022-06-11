// Created by 周子望 on 2022/6/11.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

int main_code7() {
	float fNum;
	cin >> fNum;

	int res = fNum;
	if(fNum - res >= 0.5) {
		res++;
	}

	cout << res << endl;

	return 0;
}