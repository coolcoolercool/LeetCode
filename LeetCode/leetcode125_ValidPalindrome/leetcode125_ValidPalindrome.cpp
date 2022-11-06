// Created by 周子望 on 2022/11/6.
#include "../../include.h"
/**
题目描述:

核心思想:
**/

class Solution {
public:
	bool isPalindrome(string s) {
		int size = s.size();
		int left = 0, right = size - 1;
		while(left < right) {
			while(!isalnum(s[left]) && left < right) {
				left++;
			}
			while(isalnum(s[right]) && left < right) {
				right--;
			}
			if (left != right && toupper(s[left]) != toupper(s[right])) {
				return false;
			}
		}

		return true;
	}
};

/*
isalnum()用来判断一个字符是否为数字或者字母，也就是说判断一个字符是否属于a~z||A~Z||0~9
isalpha()用来判断一个字符是否为字母，如果是字符则返回非零，否则返回零。
isupper()和islower相反，用来判断一个字符是否为大写字母。
islower()用来判断一个字符是否为小写字母，也就是是否属于a~z。
tolower()函数是把字符串都转化为小写字母
toupper()函数是把字符串都转化为小写字母
 */

