// Created by rainyzwzhou on 2022/5/20.

/**
题目描述:
给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/

核心思想:
https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/solution/ben-ti-shi-shang-zui-wan-zheng-ju-ti-de-shou-mo-sh/

https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/solution/tou-liao-liang-wei-da-lao-de-tu-he-ti-ji-fs9r/
 **/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long getCount(long prefix, long n) {
		long cur = prefix;
		long next = cur + 1;
		long count = 0;
		while(cur <= n) {
			count += min(n+1, next) - cur;
			cur *= 10;
			next *= 10;
		}
		return count;
	}

	int findKthNumber(int n, int k) {
		long p = 1;
		long prefix = 1;
		while(p < k) {
			long count = getCount(prefix, n);
			if (p + count > k) { // 说明第k个数，在这个前缀范围里面
				prefix *= 10;
				p++;
			} else if (p+count <= k) { 	// 说明第k个数，不在这个前缀范围里面，前缀需要扩大+1
				prefix++;
				p += count;
			}
		}
		return static_cast<int>(prefix);
	}
};
