// Created by rainyzwzhou on 2022/6/9.

/**
题目描述:
https://www.nowcoder.com/practice/c5db069fd9d64e6e9cf5fd68860abcdd?tpId=196&tqId=40394&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D330%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196&difficulty=undefined&judgeStatus=undefined&tags=&title=330
牛客网 NC330 36进制加法


核心思想:
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int CharToNum(char ch) {
		if (isdigit(ch)) {
			return ch - '0';
		} else {
			return ch - 'a' + 10;
		}
	}

	char NumToChar(int num) {
		if (num < 10) { // 0 ~ 9
			return num + '0';
		} else { // 10 ~ 35
			return num - 10 + 'a';
		}
	}

	string thirtysixAdd(string A, string B) {
		int sizeA = A.size();
		int sizeB = B.size();

		vector<char> resVec(sizeA + sizeB, '0');

		int index = resVec.size() - 1;
		int indexA = sizeA - 1, indexB = sizeB - 1;

		int add = 0;
		while (indexA >= 0 || indexB >= 0 || add > 0) {
			int numA = indexA >= 0 ? CharToNum(A[indexA]) : 0;
			int numB = indexB >= 0 ? CharToNum(B[indexB]) : 0;

			int val = numA + numB + add;
			add = val / 36;
			val = val % 36;

			resVec[index] = NumToChar(val);

			index--;
			indexA--;
			indexB--;
		}

		index = 0;
		while (resVec[index] == '0') {
			index++;
		}
		string res;
		for (int i = index; i < resVec.size(); i++) {
			res.push_back(resVec[i]);
		}

		return res;
	}

};
