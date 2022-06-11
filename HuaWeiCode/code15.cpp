// Created by 周子望 on 2022/6/11.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

int main_code15() {
	int num = 0;
	cin >> num;

	int res = 0;
	while(num > 0) {
		if(num & 1 == 1) res++;
		num >>= 1;
	}

	cout << res << endl;
	return 0;
}