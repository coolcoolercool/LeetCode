// Created by 周子望 on 2022/11/6.
#include "../../include.h"
/**
题目描述:

核心思想:
**/


class Solution {
public:
	bool detectCapitalUse(string word) {
		int size = word.size();
		if (size >= 2 && islower(word[0]) && isupper(word[1])) {
			return false;
		}
		for (int i = 2; i < size; i++) {
			if (islower(word[1]) ^ islower(word[i])) {
				return false;
			}
		}
		return true;
	}
	
	bool detectCapitalUse_ziji(string word) {
		int size = word.size();
		bool firstUpper = false;
		if (word[0] >= 'A' && word[0] <= 'Z') {
			firstUpper = true;
		}

		if (size == 1) {
			return true;
		}

		bool secondUpper = false;
		if (word[1] >= 'A' && word[1] <= 'Z') {
			secondUpper = true;
		}

		if (!firstUpper && secondUpper) {
			return false;
		}

		for(int i = 2; i < size; i++) {
			if (firstUpper && secondUpper && word[i] >= 'a' && word[i] <= 'z') {
				return false;
			} else if (firstUpper && !secondUpper && word[i] >= 'A' && word[i] <= 'Z') {
				return false;
			} else if (!firstUpper && !secondUpper && word[i] >= 'A' && word[i] <= 'Z') {
				return false;
			}
		}

		return true;
	}
};