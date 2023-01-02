// Created by 周子望 on 2022/12/4.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numWays(int n) {
		if (n == 0) {
			return 1;
		} else if (n == 1) {
			return 1;
		} else if (n == 2) {
			return 2;
		}
		
		int a = 2, b = 1, c = 1;
		for(int i = 2; i <= n; i++) {
			a = (b + c) % 1000000007;
			c = b;
			b = a;
		}
		return a;
	}
};