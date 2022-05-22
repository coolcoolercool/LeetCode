// Created by rainyzwzhou on 2022/5/13.

/**
题目描述:

核心思想:
BrianKernighan 算法的原理是：对于任意整数 x，令 x=x&(x−1)，该运算将 x 的二进制表示的最后一个 1 变成 0。因此，对 x 重复该操作，直到 x 变成 0，则操作次数即为 x 的「一比特数」

**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countOnes(int x) {
		int ones = 0;
		while (x > 0) {
			x &= (x - 1);
			ones++;
		}
		return ones;
	}

	vector<int> countBits(int n) {
		vector<int> bits(n + 1);
		for (int i = 0; i <= n; i++) {
			bits[i] = countOnes(i);
		}
		return bits;
	}
};