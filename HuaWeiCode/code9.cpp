// Created by 周子望 on 2022/6/11.

/**
题目描述:
https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

int main_code9() {
	int num = 0;
	cin >> num;

	string numStr = to_string(num);
	reverse(numStr.begin(), numStr.end());
	vector<int> vec(10); // 使用一个长度为10的数组代替set
	string res;

	for(char element : numStr) {
		if(vec[element - '0'] == 0) {
			vec[element - '0'] = 1;
			res.push_back(element);
		}
	}

	cout << res << endl;

	return 0;
}