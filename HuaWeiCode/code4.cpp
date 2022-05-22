//
// Created by rainyzwzhou on 2022/5/7.
//

#include<bits/stdc++.h>

using namespace std;

// cin只会读到到空格，剩下的字符在下次读取
int main_code4() {
	string str;
	cin >> str;

	int size = str.size();
	int addChar = size % 8;
	if(addChar != 0) {
		addChar = 8 - addChar;
	}

	for(int i = 0; i < addChar; i++) {
		str.append("0");
	}

	vector<string> vec;
	int index = 0;
	while(index < str.size()) {
		vec.push_back(str.substr(index, 8));
		index += 8;
	}

	for(auto element : vec) {
		cout << element << endl;
	}

	return 0;
}