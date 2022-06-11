// Created by 周子望 on 2022/6/11.

/**
题目描述:
https://www.nowcoder.com/practice/196534628ca6490ebce2e336b47b3607?tpId=37&tqId=21229&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=

核心思想:
首先他给定的数就是可以只用质数就可以分解
其次需要稍微减少遍历的次数
**/

#include <bits/stdc++.h>
using namespace std;

int main_km87hg() {
	long long num;
	cin >> num;
	long long s = sqrt(num); // 这里不用开方会超时
	for (long long i = 2; i <= s; i++) {
		while (num % i == 0) {
			cout << i << " ";
			num /= i;
		}
		if (num == 1)break;

	}
	if (num != 1)cout << num << " ";
	cout << endl;
}