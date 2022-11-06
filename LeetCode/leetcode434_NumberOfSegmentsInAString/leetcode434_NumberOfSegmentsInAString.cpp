// Created by 周子望 on 2022/11/6.
#include "../../include.h"
/**
题目描述:

核心思想:
**/

class Solution {
public:
	int countSegments(string s) {
		int size = s.size(), result = 0;

		for(int i = 0; i < size; i++) {
			if ((i == 0 || s[i - 1] == ' ') && s[i] != ' '){
				result++;
			}
		}
		return result;
	}
};