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
	long getCount(long prefix, long n) { // prefix是前缀，n是上界
		long cur = prefix;
		long next = cur + 1; // 下一个前缀
		long count = 0;
		while (cur <= n) {   // 当前的前缀当然不能大于上界
			count += min(n + 1, next) - cur; // 下一个前缀的起点减去当前前缀的起点
			cur *= 10;
			next *= 10;
			// 如果说刚刚prefix是1，next是2，那么现在分别变成10和20
			// 1为前缀的子节点增加10个，十叉树增加一层, 变成了两层

			// 如果说现在prefix是10，next是20，那么现在分别变成100和200，
			// 1为前缀的子节点增加100个，十叉树又增加了一层，变成了三层
		}
		return count; // 把当前前缀下的子节点和返回去。
	}

	int findKthNumber(int n, int k) {
		long p = 1; // 作为一个指针，指向当前所在位置，当p==k时，也就是到了排位第k的数
		long prefix = 1; // 前缀
		while (p < k) {
			long count = getCount(prefix, n); // 获得当前 前缀下所有子节点的和
			if (p + count > k) { // 说明第k个数，在这个前缀范围里面
				prefix *= 10; // 把指针指向了第一个子节点的位置，比如11乘10后变成110，指针从11指向了110
				p++;
			} else if (p + count <= k) {    // 说明第k个数，不在这个前缀范围里面，前缀需要扩大+1
				prefix++;
				p += count; // 注意这里的操作，把指针指向了下一前缀的起点
			}
		}
		return static_cast<int>(prefix);
	}
};

