//
// Created by rainyzwzhou on 2022/5/7.
//

#include<bits/stdc++.h>

using namespace std;

// cin只会读到到空格，剩下的字符在下次读取
int main_code2() {
	string s;
	char c;
	getline(cin, s);
	c = tolower(getchar());

	int count = 0;
	for(auto element: s) {
		if(tolower(element) == c) count++;
	}

	cout << count << endl;

	return 0;
}