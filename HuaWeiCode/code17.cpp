// Created by 周子望 on 2022/6/12.

/**
题目描述:

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string str) {
	if(str.empty()) return false;
	if(str[0] != 'A' && str[0] != 'D' && str[0] != 'W' && str[0] != 'S') return false;

	for(int i = 1; i < str.size(); i++) {
		if(!isdigit(str[i])) return false;
	}

	return true;
}


int main_code17() {
	string str;
	int curX = 0, curY = 0;
	cin >> str;
	int size = str.size();

	int startIndex = 0;
	for(int i = 0; i < size; i++) {
		if(str[i] == ';') {
			string oneStr = str.substr(startIndex, i - startIndex);
			if(!isValid(oneStr) ) {
				startIndex = i + 1;
				continue;
			}

			char dire = oneStr[0];
			int stepNum = stoi(oneStr.substr(1));

			if(dire == 'A') {
				curX -= stepNum;
			} else if (dire == 'D') {
				curX += stepNum;
			} else if (dire == 'W') {
				curY += stepNum;
			} else if (dire == 'S') {
				curY -= stepNum;
			}
			startIndex = i + 1;
		}
	}

	cout << curX << "," << curY << endl;

	return 0;
}