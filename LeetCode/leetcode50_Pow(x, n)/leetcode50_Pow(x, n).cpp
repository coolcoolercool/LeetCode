//
// Created by rainyzwzhou on 2022/5/2.
//

/**
 题目:
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n ）

 核心思想:
 https://leetcode-cn.com/problems/powx-n/solution/50-powx-n-kuai-su-mi-qing-xi-tu-jie-by-jyd/

 将 计算 十进制整数 幂 转换成计算 二进制 幂
 */

#include "../../include.h"

class Solution {
/**
	https://leetcode-cn.com/problems/powx-n/solution/qing-xi-jian-dan-de-dan-han-shu-di-gui-wu-lei-xing/
 */
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		if (n == 1) return x;
		if (n == -1) return 1 / x;

		double half = myPow(x, n / 2);
		double rest = myPow(x, n % 2);

		return rest * half * half;
	}

public:
	double myPow_1(double x, int n) {
		int64_t exp = n;    // n可能为-2147483648
		if (exp < 0) {
			x = 1 / x;
			exp = -exp;
		}

		double ans = 1;
		// 右移至把原MSB消掉时exp就变为0，就可以停了
		while (exp) {
			if (exp & 1) ans *= x; // 取余数 n % 2 等价于 判断二进制最右位 n & 1

			x *= x;
			exp >>= 1;  // 向下整除 n//2 等价于 右移一位 n >> 1
		}

		return ans;
	}
};