// Created by 周子望 on 2023/3/26.

/**
题目描述:
验证接受各种输入
总结一下，这里主要是cin为主如何接收固定格式的字符，数字，字符串等等，我列举了几种情况。

首先，说明一下c++接收字符的几种方式。都包含在#include<iostream>里面。

cin>>str1;   //这种方式默认接收不带空格的，回车表示用户输入结束，一句可以接收一个空格前的字符或字符串
cin.get(ch);   //这种方式可以接收字符
cin.get(str2,10); //这种方式可以接收 字符串(但是不接受string),第二个参数为字符串长度
cin.get();   //这种方式主要是用来舍弃输入流中不需要的字符
cin.getline(strs,16); //这种方式可以接收字符串数组，第二个参数也是字符串长度
cin.getline(strs,16,' '); //这种方式可以接收字符串数组，第三个参数是结束的标志，默认是’\0’。
getline(cin,strs); //这种方式可以接收string类型的字符串

 cin
cin默认读取空白符（空格，回车，换行，制表，换纸）就会忽略掉
想避免这种情况就需要设置一个方法。
cin>>noskipws;

核心思想:
**/

#include <bits/stdc++.h>
using namespace std;

string str_input, str_input1;
void help() {
	// 接受从键盘输入的string
	cout << "input string:" << endl;
	cin >> str_input;
	cout << "input string->" << str_input << endl;
}

void help_1() {
	// 接收从键盘输入的两个string, 两个字符串使用换行符隔开
	cout << "input two string:" << endl;
	cin >> str_input >> str_input1;
	cout << "input string->" << str_input << "," << str_input1 << endl;
}

void help_2() {
	// 从键盘接收输入不定数目个string， 每个string之间换行符， 数量小于100个
	// 可以使用 ctrl + D 打断输入
	vector<string> vec(100);
	int index = 0;
	while(cin) {
		cin >> vec[index];
		index++;
	}
	for(int i = 0; i < index; i++) {
		cout << "i=" << i << "," << vec[i] << endl;
	}
}

void help_3() {
	// 从键盘接受指定数目个整数， 每个整数之间换行符，数量为3
	int num = 3;
	vector<int> vec(num);

	for(int i = 0; i < num; i++) {
		cin >> vec[i];
	}

	for(int i = 0; i < num; i++) {
		cout << "i=" << i << "," << vec[i] << endl;
	}
};

void help_4() {
	// 从键盘接收 rows为n， cols为m的二维矩阵, 这里输入例子为
	/*
	 1 2 3 4
	 5 6 7 8
	 9 10 11 12
	 */
	int m = 0, n = 0;
	cin >> m >> n;
	vector<vector<int>> vec(m, vector<int>(n));
	cout << "m=" << m << ",n=" << n << endl;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << vec[i][j] << ",";
		}
		cout << endl;
	}
}

void help_5() {
	/*
		cin默认读取空白符（空格，回车，换行，制表，换纸）就会忽略掉
		想避免这种情况就需要设置一个方法。
		cin>>noskipws;
	 */
	char ch;
	cin>>noskipws; // 会将比如空格这类也接收
	while(cin >> ch) {
		cout << ch;
	}
}

int main_oklm98() {
	help_4();

	return 0;
}
