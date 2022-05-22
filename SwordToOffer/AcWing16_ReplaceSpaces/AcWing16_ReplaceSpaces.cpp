//
// Created by rainyzwzhou on 2022/4/27.
//

/**
请实现一个函数，把字符串中的每个空格替换成"%20"。

数据范围
0≤ 输入字符串的长度 ≤1000。
注意输出字符串的长度可能大于 1000。

样例
输入："We are happy."

输出："We%20are%20happy."
 */

#include "../../../LeetCode/include.h"

class Solution {
public:
	// 倒着输出i，j是一直大于i的，所以这就保证了j不回去遮盖住i没有遍历到的值。如果正着输出j会遮盖住i
	string replaceSpaces(string &str) {
		// 通过统计空格的个数，确认最终的字符串的长度
		int len = 0;
		for(auto element : str) {
			if(element == ' ') {
				len += 3;
			} else {
				len++;
			}
		}

		int oldIndex = str.size() - 1, newIndex = len - 1;
		str.resize(len);

		while(oldIndex >= 0) {
			if(str[oldIndex] == ' ') {
				str[newIndex--] = '0';
				str[newIndex--] = '2';
				str[newIndex--] = '%';
			}
			else {
				str[newIndex--] = str[oldIndex];
			}
			oldIndex--;
		}
		return str;
	}

	string replaceSpaces_low(string &str) {
		// 通过统计空格的个数，确认最终的字符串的长度
		string res;
		for(int i = 0; i < str.size(); i++) {
			if(str[i] == ' ') {
				res.append("02%");
			} else {
				res += (str[i]);
			}
		}

		return str;
	}

};

