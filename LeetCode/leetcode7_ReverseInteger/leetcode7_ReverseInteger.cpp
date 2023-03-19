// Created by rainyzwzhou on 2022/6/2.

/**
题目描述:
 将一个32位的整数反转
32位整数最大为 2147483647， 最小为 -2147483648

核心思想:
以此从右到左取整数的数字，然后以此计算反转的后的值， 但是需要注意溢出的问题
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int res = 0;
		while (x != 0) {
			if (res < INT_MIN / 10 || res > INT_MAX / 10) { // 处理结果溢出的场景
				return 0;
			}
			int digit = x % 10;
			x /= 10;
			res = res * 10 + digit;
		}
		return res;
	}

public:
	int reverse_ziji(int x) {
		string num = to_string(x);

		int size = num.size();
		if (size == 1) return x;
		int index = 0, flag = 1;
		if (num[index] == '-') {
			flag = -1;
		}

		::reverse(num.begin() + index, num.end());
		int res = 0;
		int beginZero = true;

		for (int i = index; i < size; i++) {
			if (num[i] == '0' && beginZero) continue;
			beginZero = false;
			if (res > INT_MAX / 10 || (flag == -1 && res == INT_MAX / 10 && num[i] - '0' > 7)) return 0;

			res = res * 10 + num[i] - '0';
		}

		return res * flag;
	}
};