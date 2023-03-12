// Created by 周子望 on 2023/2/18.

#include<bits/stdc++.h>
using namespace std;

int main_0lkm9() {
	cout << "vec cout" << endl;
	vector<int> vec;
	for(int i = 0; i < 5; i++) {
		vec.push_back(i);
	}
	for(int i = 0; i < vec.size(); i++) {
		cout << "vec i=" << i << ", val=" << vec[i] << endl;
	}
	cout << "vec front:" << vec.front() << endl;
	vec.pop_back();
	for(int i = 0; i < vec.size(); i++) {
		cout << "vec i=" << i << ", val=" << vec[i] << endl;
	}

	cout << "\nqueue cout" << endl;
	queue<int> qe;
	for(int i = 0; i < 5; i++) {
		qe.push(i);
	}
	cout << "queue front:" << qe.front() << endl;
	cout << "queue back:" << qe.back() << endl;
	qe.pop();
	cout << "queue front:" << qe.front() << endl;
	cout << "queue back:" << qe.back() << endl;


	cout << "\nstack cout" << endl;
	stack<int> st;
	for(int i = 0; i < 5; i++) {
		st.push(i);
	}
	cout << "stack top:" << st.top() << endl;
	st.pop();
	cout << "stack top:" << st.top() << endl;

	cout << "\nmap cout" << endl;
	map<int, int> mp;
	for(int i = 0; i < 5; i++) {
		mp.insert(pair<int, int>{i, i});
	}
	for(auto it= mp.begin(); it != mp.end(); it++) {
		cout << "mp key=" << it->first << ", second=" << it->second << endl;
	}
	mp[3] = -3;
	for(auto it= mp.begin(); it != mp.end(); it++) {
		cout << "mp key=" << it->first << ", second=" << it->second << endl;
	}
	mp.erase(3);
	for (auto it=mp.begin(); it != mp.end(); it++) {
		cout << "mp key=" << it->first << ", second=" << it->second << endl;
	}

	cout << "\nset cout" << endl;
	set<int> innerSet;
	for(int i = 0; i < 5; i++) {
		innerSet.insert(i);
	}
	for(auto it=innerSet.begin(); it != innerSet.end(); it++) {
		cout << "set val=" << *it << endl;
	}
	innerSet.erase(3);
	for(auto it = innerSet.begin(); it != innerSet.end(); it++){
		cout << "set val=" << *it << endl;
	}

	return 0;
}



















int main_230220() {
	cout << "queue cout" << endl;
	queue<int> qe;
	qe.push(1);
	qe.push(2);
	qe.push(3);
	cout << qe.front() << endl;
	cout << qe.back() << endl;
	qe.pop();
	cout << qe.front() << endl;
	cout << qe.back() << endl;


	cout << "\nqueue cout" << endl;
	stack<int> st;
	st.push(1);
	st.push(2);
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;

	cout << "\nvector cout" << endl;
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	for (int i = 0; i < vec.size(); i++) {
		cout << "vec i=" << i << " val = " << vec[i] << endl;
	}
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	vec.pop_back();
	cout << vec.back() << endl;

	cout << "\nmap cout" << endl;
	map<int, int> mp;
	mp.insert(pair<int, int>{1, 1});
	mp.insert({2, 2});
	mp.insert({3, 3});
	mp.insert({4, 4});
	cout << mp[2] << endl;
	mp[2] = 1;
	cout << mp[2] << endl;
	for(auto it = mp.begin(); it != mp.end(); it++) {
		cout << "mp key=" << it->first << ", mp second=" << it->second << endl;
	}

	cout << "\nset cout" << endl;
	set<int> innerSet;
	innerSet.insert(1);
	innerSet.insert(2);
	innerSet.insert(3);
	for(auto it = innerSet.begin(); it != innerSet.end(); it++) {
		cout << "set val=" << *it << endl;
	}
	innerSet.erase(2);
	for(auto it = innerSet.begin(); it != innerSet.end(); it++) {
		cout << "set val=" << *it << endl;
	}

	return 0;
}

